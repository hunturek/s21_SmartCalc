#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    setMouseTracking(false);
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    aspect = static_cast<float>(w) / h;
    if (w >= h) {
        glOrtho(-zoom * aspect, zoom * aspect, -zoom, zoom, -1.0, 1.0);
    } else {
        glOrtho(-zoom, zoom, -zoom / aspect, zoom / aspect, -1.0, 1.0);
    }
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glDisable(GL_BLEND);
    resizeGL(width(), height());
    glTranslatef(offsetX, offsetY, 0.0f);
    if(graph.size() == 0) {
        DrawNum(0., 0.1, -0.95,0);
        zoom = 1.0f;
        offsetX = 0.0f;
        offsetY = 0.0f;
    }
    else if(graph.size() == 1) {
        DrawNum(graph[0], 0.1, -0.95, 0);
        zoom = 1.0f;
        offsetX = 0.0f;
        offsetY = 0.0f;
    }
    else {
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-1000000, 0);
        glVertex2f(1000000, 0);
        glVertex2f(0, -1000000);
        glVertex2f(0, 1000000);
        glEnd();
        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_LINES);
        for(float i = -stepY; i > -zoom * aspect - offsetY; i += -stepY){
            glVertex2f(-zoom * aspect - offsetX, i);
            glVertex2f(zoom * aspect - offsetX, i);
        }
        for(float i = stepY; i < zoom * aspect - offsetY; i += stepY){
            glVertex2f(-zoom * aspect - offsetX, i);
            glVertex2f(zoom * aspect - offsetX, i);
        }
        for(float i = -stepX; i > -zoom * aspect - offsetX; i += -stepX){
            glVertex2f(i, -zoom * aspect - offsetY);
            glVertex2f(i, zoom * aspect - offsetY);
        }
        for(float i = stepX; i < zoom * aspect - offsetX; i += stepX){
            glVertex2f(i, -zoom * aspect - offsetY);
            glVertex2f(i, zoom * aspect - offsetY);
        }
        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        for(size_t i = 0; i < graph.size(); i++)
            glVertex2f(-offsetX-zoom + (2 * zoom / 100) * i, graph[i]);
        glEnd();
    }
}

void GLWidget::Draw0(float size, float x, float y){
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(x+size,y);
    glVertex2f(x+size,y-2*size);
    glVertex2f(x,y-2*size);
    glEnd();
}

void GLWidget::Draw1(float size, float x, float y){
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y-size);
    glVertex2f(x+size,y);
    glVertex2f(x+size,y-2*size);
    glEnd();
}

void GLWidget::Draw2(float size, float x, float y){
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y);
    glVertex2f(x+size,y);
    glVertex2f(x+size,y-size);
    glVertex2f(x,y-size);
    glVertex2f(x,y-2*size);
    glVertex2f(x+size,y-2*size);
    glEnd();
}

void GLWidget::Draw3(float size, float x, float y){
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y);
    glVertex2f(x+size,y);
    glVertex2f(x+size,y-size);
    glVertex2f(x,y-size);
    glVertex2f(x+size,y-size);
    glVertex2f(x+size,y-2*size);
    glVertex2f(x,y-2*size);
    glEnd();
}

void GLWidget::Draw4(float size, float x, float y){
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y);
    glVertex2f(x,y-size);
    glVertex2f(x+size,y-size);
    glVertex2f(x+size,y);
    glVertex2f(x+size,y-2*size);
    glEnd();
}

void GLWidget::Draw5(float size, float x, float y){
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+size,y);
    glVertex2f(x,y);
    glVertex2f(x,y-size);
    glVertex2f(x+size,y-size);
    glVertex2f(x+size,y-2*size);
    glVertex2f(x,y-2*size);
    glEnd();
}

void GLWidget::Draw6(float size, float x, float y){
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+size,y);
    glVertex2f(x,y);
    glVertex2f(x,y-2*size);
    glVertex2f(x+size,y-2*size);
    glVertex2f(x+size,y-size);
    glVertex2f(x,y-size);
    glEnd();
}

void GLWidget::Draw7(float size, float x, float y){
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y);
    glVertex2f(x+size,y);
    glVertex2f(x+size,y-2*size);
    glEnd();
}

void GLWidget::Draw8(float size, float x, float y){
    Draw0(size,x,y);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+size,y-size);
    glVertex2f(x,y-size);
    glEnd();
}

void GLWidget::Draw9(float size, float x, float y){
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y-2*size);
    glVertex2f(x+size,y-2*size);
    glVertex2f(x+size,y);
    glVertex2f(x,y);
    glVertex2f(x,y-size);
    glVertex2f(x+size,y-size);
    glEnd();
}

void GLWidget::DrawDot(float size, float x, float y){
    glBegin(GL_POLYGON);
    glVertex2f(x+2*size/5, y-2*size);
    glVertex2f(x+3*size/5, y-2*size);
    glVertex2f(x+3*size/5, y-2*size+size/5);
    glVertex2f(x+2*size/5, y-2*size+size/5);
    glEnd();
}

void GLWidget::DrawMinus(float size, float x, float y)
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+size,y-size);
    glVertex2f(x,y-size);
    glEnd();
}

void GLWidget::DrawNum(double num, float size, float x, float y){
    QString str = QString("%1").arg(num, 0, 'f', 7);
    for(int i = 0; i < str.length(); i++){
        switch(str.at(i).unicode()){
            case '0':
                Draw0(size, x, y);
            break;
            case '1':
                Draw1(size, x, y);
            break;
            case '2':
                Draw2(size, x, y);
            break;
            case '3':
                Draw3(size, x, y);
            break;
            case '4':
                Draw4(size, x, y);
            break;
            case '5':
                Draw5(size, x, y);
            break;
            case '6':
                Draw6(size, x, y);
            break;
            case '7':
                Draw7(size, x, y);
            break;
            case '8':
                Draw8(size, x, y);
            break;
            case '9':
                Draw9(size, x, y);
            break;
            case '.':
                DrawDot(size, x, y);
            break;
            case '-':
                DrawMinus(size, x, y);
            break;
        }
        x += size + size/3;
    }
}

void GLWidget::mousePressEvent(QMouseEvent *apEvent){
    mPosition = apEvent->position();
    if(apEvent->button() == Qt::MiddleButton){
        middleButtonPressed = true;
        setCursor(Qt::SizeAllCursor);
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *apEvent){
    if(middleButtonPressed){
        QPointF startPos = mPosition;
        mPosition = apEvent->position();
        if(startPos.x() != 0 && startPos.y() != 0){
            float dx = (mPosition.x() - startPos.x());
            float dy = (startPos.y() - mPosition.y());

            offsetX += dx * zoom / 175;
            offsetY += dy * zoom / 175;

            emit triggerCalculateButton();

            repaint();
        }
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *apEvent)
{
    if(apEvent->button() == Qt::MiddleButton){
        middleButtonPressed = false;
        setCursor(Qt::ArrowCursor);
    }
}

void GLWidget::wheelEvent(QWheelEvent *event){
    int delta = event->angleDelta().y();
    float scaleFactor = 1.1f;
    if (delta > 0) {
        zoom /= scaleFactor;
    } else {
        zoom *= scaleFactor;
    }
    emit triggerCalculateButton();
    repaint();
}

QPointF GLWidget::widgetToInternalCoords(int x, int y) {
    float aspect = float(width()) / float(height());
    float normalizedX = (2.0f * x - width()) / width() * zoom;
    float normalizedY = - (2.0f * y - height()) / height() * zoom;
    if (width() >= height()) {
        normalizedX *= aspect;
    } else {
        normalizedY /= aspect;
    }
    return QPointF(normalizedX - offsetX, normalizedY - offsetY);
}
