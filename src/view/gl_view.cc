#define GL_SILENCE_DEPRECATION
#include "gl_view.h"

#include <OpenGL/OpenGL.h>

#include <QDebug>

#include "controller/controller.h"
#include "core/obj.h"
#include "main_widget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent, MainWidget* mv_ptr,
                           s21::Controller* controller_ptr)
    : QOpenGLWidget(parent),
      main_widget_ptr_(mv_ptr),
      controller_(controller_ptr) {}

// init_data_struct(&objData);
//}

void OpenGLWidget::initRenderSettings() {
  glPointSize(setting.vertexSize);  // размер точек
  glLineWidth(setting.edgeWidth);   // толщина линий
  glClearColor(setting.backgroundColor.redF(), setting.backgroundColor.greenF(),
               setting.backgroundColor.blueF(), setting.backgroundColor.alphaF());  //цвет фона
  glClear(GL_COLOR_BUFFER_BIT);

  if (setting.vertexMode == 1)
    glEnable(GL_POINT_SMOOTH);
  else if (setting.vertexMode == 0)
    glDisable(GL_POINT_SMOOTH);
  if (setting.lineMode) {  // вид линии - пунктир
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
  } else  // вид линии - сплошная
    glDisable(GL_LINE_STIPPLE);
}

void OpenGLWidget::initializeGL() { initRenderSettings(); }

void OpenGLWidget::resizeGL(int w, int h) {
  setting.aspectRatio = static_cast<double>(geometry().width()) /
                static_cast<double>(geometry().height());  // соотношение сторон
  setupPerspective();      // Настройка перспективы
  glViewport(0, 0, w, h);  // Установка точки опоры
  glLoadIdentity();
}

void OpenGLWidget::paintObjLines() {
  glColor3d(setting.edgeColor.redF(), setting.edgeColor.greenF(),
            setting.edgeColor.blueF());  // задаем цвет для полигонов
  const std::vector<s21::Vertex_3d>& vertexes = controller_->getObjVertexes();
  const std::vector<s21::Facet_3d>& polygons = controller_->getObjPolygons();
  for (auto& poly : polygons) {
    glBegin(GL_LINE_LOOP);
    for (auto& it : poly.vertex_indexes) {
      glVertex3d(vertexes[it].x, vertexes[it].y, vertexes[it].z);
    }
    glEnd();
  }
}

void OpenGLWidget::paintObjVertexes() {
  if (setting.vertexMode != 2) {
    glColor3d(setting.vertexColor.redF(), setting.vertexColor.greenF(),
              setting.vertexColor.blueF());  // задаем цвет для точек
    glBegin(GL_POINTS);
    for (auto& vertex : controller_->getObjVertexes()) {
      glVertex3d(vertex.x, vertex.y, vertex.z);
    }
    glEnd();
  }
}

void OpenGLWidget::paintGL() {
  if (controller_ == nullptr) {
    return;
  }
  initRenderSettings();
  glLoadIdentity();    // Сброс матрицы проекции
  setupPerspective();  // Настройка перспективы

  if (controller_->objIsValid()) {
    paintObjLines();
    paintObjVertexes();
  }
}

void OpenGLWidget::setupPerspective() {
  double maxCoord = controller_->getObjMaxValue() * 2;  //дальность камеры
  GLdouble zNear = 0.01;  // Ближнее расстояние отсечения
  GLdouble zFar = maxCoord * 10;  // Дальнее расстояние отсечения

  if (maxCoord < 1) {
    maxCoord = 2;
  }
  if (!setting.perspectiveMode) {
    GLdouble fovY = 90;  // Поле зрения в градусах по оси y
    GLdouble fH = tan(fovY / 360 * M_PI) * zNear;
    GLdouble fW = fH * setting.aspectRatio;
    glFrustum(-fW, fW, -fH, fH, zNear,
              zFar);  // Устанавливает усеченный конус в режим перспективы
    glTranslatef(0, 0, -maxCoord);
  } else {
    glOrtho(-maxCoord * setting.aspectRatio, maxCoord * setting.aspectRatio, -maxCoord,
            maxCoord, -maxCoord, zFar);
  }
}
