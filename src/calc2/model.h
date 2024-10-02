#ifndef MODEL_H
#define MODEL_H

#include <QtCore/QString>
#include <QStringList>
#include <QDebug>
#include <QRegularExpression>
#include <stack>
#include <map>
#include <set>
#include <cmath>

class Model
{
public:
    Model();
    std::vector<double> calculate(QString infix, double left, double right, bool NumX, double x);

private:
    QStringList parser(QString infix);
    QStringList postfix(QStringList infix, bool *graph);
    double calc(QStringList postfix, double x);

};

#endif // MODEL_H
