#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    this->setFixedSize(425, 519);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    connect(ui->openGLWidget, &GLWidget::triggerCalculateButton, this, &View::on_pushButton_clicked);
}

View::~View()
{
    delete ui;
}

void View::on_pushButton_clicked()
{
    double left = 0.;
    double right = 0.;
    if(ui->openGLWidget->aspect > 0){
        left = -ui->openGLWidget->zoom * ui->openGLWidget->aspect - ui->openGLWidget->offsetX;
        right = ui->openGLWidget->zoom * ui->openGLWidget->aspect - ui->openGLWidget->offsetX;
    }
    ui->openGLWidget->graph.clear();
    if(ui->lineEdit->text() != "")
        ui->openGLWidget->graph = controller->calculate(ui->lineEdit->text(), left, right, NumX, ui->doubleSpinBox_numx->value());
    ui->openGLWidget->stepX = ui->doubleSpinBox_stepx->value();
    ui->openGLWidget->stepY = ui->doubleSpinBox_stepy->value();
    ui->openGLWidget->repaint();
}

void View::on_radioButton_clicked()
{
    NumX = !NumX;
}

void View::on_doubleSpinBox_stepx_valueChanged(double arg1)
{
    ui->openGLWidget->stepX = arg1;
    ui->openGLWidget->repaint();
}

void View::on_doubleSpinBox_stepy_valueChanged(double arg1)
{
    ui->openGLWidget->stepY = arg1;
    ui->openGLWidget->repaint();
}
