#include "controller.h"

Controller::Controller()
{

}

std::vector<double> Controller::calculate(QString infix, double left, double right, bool NumX, double x)
{
    return model->calculate(infix, left, right, NumX, x);
}
