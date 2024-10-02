#include "model.h"

Model::Model()
{

}

QStringList Model::parser(QString infix)
{
    QStringList tokens;
    QRegularExpression re(R"((\d+\.?\d*)|(x|mod|[a-zA-Z_]\w*)|(\S))");
    QRegularExpressionMatchIterator it = re.globalMatch(infix);
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        tokens << match.captured(0);
    }
    return tokens;
}

QStringList Model::postfix(QStringList infix, bool *graph)
{
    bool unaryMinus = true;
    std::map<QString, int> OpPriority = {
        {"(", 0},
        {"+", 1},
        {"-", 1},
        {"cos", 4},
        {"sin", 4},
        {"tan", 4},
        {"acos", 4},
        {"asin", 4},
        {"atan", 4},
        {"sqrt", 4},
        {"ln", 4},
        {"log", 4},
        {"*", 2},
        {"/", 2},
        {"mod", 2},
        {"^", 3},
        {"~", 4}
    };
    QStringList result;
    std::stack<QString> stack;
    QRegularExpression operators("[-+*/^]");
    QRegularExpression numbers("\\d+\\.?\\d*");
    QRegularExpression functions("[a-zA-Z_][a-zA-Z0-9_]*");
    for (const QString &item : infix) {
        if(item == "x"){
            result << item;
            *graph = true;
        }
        else if(numbers.match(item).hasMatch()){
            result << item;
            unaryMinus = false;
        }
        else if(item == "(")
            stack.push(item);
        else if(item == ")") {
            while(!stack.empty() && stack.top() != "(") {
                unaryMinus = true;
                result << stack.top();
                stack.pop();
            }
            stack.pop();
            if(!stack.empty() && functions.match(stack.top()).hasMatch()){
                result << stack.top();
                stack.pop();
            }
        } else if(operators.match(item).hasMatch() || functions.match(item).hasMatch()) {
            while(!stack.empty() && OpPriority[stack.top()] >= OpPriority[item]) {
                result << stack.top();
                stack.pop();
            }
            if(item == "-" && unaryMinus)
                stack.push("~");
            else {
                unaryMinus = true;
                stack.push(item);
            }
        }
    }
    while(!stack.empty()){
        result << stack.top();
        stack.pop();
    }
    return result;
}

double Model::calc(QStringList postfix, double x)
{
    double result = 0.;
    QRegularExpression numbers("\\d+\\.?\\d*");
    double tmp = 0;
    QSet<QString> unary = {"cos", "sin", "tan", "acos", "asin", "atan", "sqrt", "ln", "log", "~"};
    QSet<QString> binary = {"+", "-", "*", "/", "mod", "^"};
    std::stack<double> stack;
    for (const QString &item : postfix) {
        if(numbers.match(item).hasMatch())
           stack.push(item.toDouble());
        else if(item == "x")
           stack.push(x);
        else if(item == "+"){
            tmp = stack.top();
            stack.pop();
            tmp = stack.top() + tmp;
            stack.pop();
            stack.push(tmp);
        } else if(item == "-"){
            tmp = stack.top();
            stack.pop();
            tmp = stack.top() - tmp;
            stack.pop();
            stack.push(tmp);
        } else if(item == "*"){
            tmp = stack.top();
            stack.pop();
            tmp = stack.top() * tmp;
            stack.pop();
            stack.push(tmp);
        } else if(item == "/"){
            tmp = stack.top();
            stack.pop();
            tmp = stack.top() / tmp;
            stack.pop();
            stack.push(tmp);
        } else if(item == "^"){
            tmp = stack.top();
            stack.pop();
            tmp = pow(stack.top(), tmp);
            stack.pop();
            stack.push(tmp);
        } else if(item == "mod"){
            tmp = stack.top();
            stack.pop();
            tmp = fmod(stack.top(), tmp);
            stack.pop();
            stack.push(tmp);
        } else if(item == "cos"){
            tmp = stack.top();
            stack.pop();
            stack.push(cos(tmp));
        } else if(item == "~"){
            tmp = stack.top();
            stack.pop();
            stack.push(-tmp);
        } else if(item == "sin"){
            tmp = stack.top();
            stack.pop();
            stack.push(sin(tmp));
        } else if(item == "tan"){
            tmp = stack.top();
            stack.pop();
            stack.push(tan(tmp));
        } else if(item == "acos"){
            tmp = stack.top();
            stack.pop();
            stack.push(acos(tmp));
        } else if(item == "asin"){
            tmp = stack.top();
            stack.pop();
            stack.push(asin(tmp));
        } else if(item == "atan"){
            tmp = stack.top();
            stack.pop();
            stack.push(atan(tmp));
        } else if(item == "sqrt"){
            tmp = stack.top();
            stack.pop();
            stack.push(sqrt(tmp));
        } else if(item == "log"){
            tmp = stack.top();
            stack.pop();
            stack.push(log10(tmp));
        } else if(item == "ln"){
            tmp = stack.top();
            stack.pop();
            stack.push(log(tmp));
        }
    }
    result = stack.top();
    stack.pop();
    if(!stack.empty())
        result = -255.;
    return result;
}

std::vector<double> Model::calculate(QString infix, double left, double right, bool NumX, double x)
{
    bool graph = false;
    QStringList notation = parser(infix);
    QStringList polish = postfix(notation, &graph);
    std::vector<double> result;
    if(graph && !NumX){
        for(double i = left; i < right; i+=(right-left)/100)
            result.push_back(calc(polish, i));
    } else {
        result.push_back(calc(polish, x));
    }
    return result;
}
