#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <model.h>
#include <QString>

class Controller
{
public:
    Controller();
    std::vector<double> calculate(QString infix, double left, double right, bool NumX, double x);

private:
    Model *model;

};

#endif // CONTROLLER_H
