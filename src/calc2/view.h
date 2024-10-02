#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <controller.h>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    bool NumX = false;
    ~View();

public slots:

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_doubleSpinBox_stepx_valueChanged(double arg1);

    void on_doubleSpinBox_stepy_valueChanged(double arg1);

private:
    Ui::View *ui;
    Controller *controller;

};
#endif // VIEW_H
