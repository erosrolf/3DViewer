#define GL_SILENCE_DEPRECATION
#include <QDebug>

#include "gl_view.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) : QOpenGLWidget{parent} {
  //init_data_struct(&objData);
}

void OpenGLWidget::initRenderSettings() {
  // glPointSize(vertexSize);  // размер точек
  // glLineWidth(edgeWidth);   // толщина линий
  // glClearColor(backgroundColor.redF(), backgroundColor.greenF(),
  //              backgroundColor.blueF(), backgroundColor.alphaF());  //цвет фона
  // if (vertexMode == 1)
  //   glEnable(GL_POINT_SMOOTH);
  // else if (vertexMode == 0)
  //   glDisable(GL_POINT_SMOOTH);
  // if (lineMode) {  // вид линии - пунктир
  //   glEnable(GL_LINE_STIPPLE);
  //   glLineStipple(1, 0x00F0);
  // } else  // вид линии - сплошная
  //   glDisable(GL_LINE_STIPPLE);
}

void OpenGLWidget::initializeGL() { initRenderSettings(); }

void OpenGLWidget::resizeGL(int w, int h) {
  // aspectRatio = static_cast<double>(geometry().width()) /
  //               static_cast<double>(geometry().height());  // соотношение сторон
  // setupPerspective();      // Настройка перспективы
  // glViewport(0, 0, w, h);  // Установка точки опоры
  // glLoadIdentity();
}

void OpenGLWidget::paintGL() {
    /*
  Polygon_t *topStack =
      objData.polygons;  //запоминаем верхушку стека с полигонами
  initRenderSettings();
  glLoadIdentity();    // Сброс матрицы проекции
  setupPerspective();  // Настройка перспективы

  glColor3d(edgeColor.redF(), edgeColor.greenF(),
            edgeColor.blueF());  // задаем цвет для полигонов
  while (objData.polygons) {
    glBegin(GL_LINE_LOOP);  // отрисовка линий полигона
    for (unsigned int i = 0; i < objData.polygons->count_vert; i++) {
      glVertex3d(objData.vertexes[objData.polygons->vertexes[i]].x,
                 objData.vertexes[objData.polygons->vertexes[i]].y,
                 objData.vertexes[objData.polygons->vertexes[i]].z);
    }
    glEnd();  // закончалась отрисовка линий полигона
    objData.polygons = objData.polygons->prev;
  }
  objData.polygons = topStack;  //возвращаем верхний элемент стека

  if (vertexMode != 2) {  // 2 мод = отсутвствие точек
    glColor3d(vertexColor.redF(), vertexColor.greenF(),
              vertexColor.blueF());  // задаем цвет для точек
    glBegin(GL_POINTS);              // отрисовка точек
    for (unsigned int i = 0; i < objData.count_of_vertexes; i++) {
      glVertex3d(objData.vertexes[i].x, objData.vertexes[i].y,
                 objData.vertexes[i].z);
    }
    glEnd();  // закончилась отрисовка точек
  }*/
}

void OpenGLWidget::setupPerspective() {
    /*
  double maxCoord = objData.max_coordinate * 3;  //дальность камеры
  GLdouble zNear = 0.01;  // Ближнее расстояние отсечения
  GLdouble zFar = maxCoord * 10;  // Дальнее расстояние отсечения

  if (maxCoord < 1) {
    maxCoord = 2;
  }
  if (perspectiveMode) {
    GLdouble fovY = 90;  // Поле зрения в градусах по оси y
    GLdouble fH = tan(fovY / 360 * M_PI) * zNear;
    GLdouble fW = fH * aspectRatio;
    glFrustum(-fW, fW, -fH, fH, zNear,
              zFar);  // Устанавливает усеченный конус в режим перспективы
    glTranslatef(0, 0, -maxCoord);
  } else {
    glOrtho(-maxCoord * aspectRatio, maxCoord * aspectRatio, -maxCoord,
            maxCoord, -maxCoord, zFar);
  }
  */
}

