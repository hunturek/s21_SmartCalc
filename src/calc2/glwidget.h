    #ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <vector>
#include <QMouseEvent>
#include <QWheelEvent>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);
    bool num = false;
    std::vector<double> graph;
    float zoom = 1.0f;
    float offsetX = 0.0f;
    float aspect = 0.;
    float stepX = 1.0f;
    float stepY = 1.0f;

protected:
     void initializeGL() override;
     void resizeGL(int w, int h) override;
     void paintGL() override;
     void DrawNum(double num, float size, float x, float y);
     void Draw0(float size, float x, float y);
     void Draw1(float size, float x, float y);
     void Draw2(float size, float x, float y);
     void Draw3(float size, float x, float y);
     void Draw4(float size, float x, float y);
     void Draw5(float size, float x, float y);
     void Draw6(float size, float x, float y);
     void Draw7(float size, float x, float y);
     void Draw8(float size, float x, float y);
     void Draw9(float size, float x, float y);
     void DrawDot(float size, float x, float y);
     void DrawMinus(float size, float x, float y);

     float offsetY = 0.0f;
     QPoint lastMousePosition;

     void mousePressEvent(QMouseEvent*) override;
     void mouseMoveEvent(QMouseEvent*) override;
     void mouseReleaseEvent(QMouseEvent*) override;
     void wheelEvent(QWheelEvent *event) override;
     QPointF widgetToInternalCoords(int x, int y);

     QPointF mPosition;
     QPointF sPosition;
     bool middleButtonPressed = false;
     bool leftButtonPressed = false;

signals:
     void triggerCalculateButton();

};

#endif // GLWIDGET_H
