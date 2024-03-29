#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>

#include "controller/controller.h"
#include "main_widget.h"

class OpenGLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  OpenGLWidget(QWidget* parent = nullptr, MainWidget* mw_ptr = nullptr,
               s21::Controller* controller_ptr = nullptr);

  void setMainWidgetPtr(MainWidget* ptr) { main_widget_ptr_ = ptr; }

  void setControllerPtr(s21::Controller* ptr) { controller_ = ptr; }

  int perspectiveMode;
  double aspectRatio;
  QColor backgroundColor;
  QColor edgeColor;
  QColor vertexColor;
  int vertexSize;
  int edgeWidth;
  double maxCoordinate;
  int lineMode;
  int vertexMode;

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 private:
  void paintObjLines();
  void paintObjVertexes();
  void setupPerspective();
  void initRenderSettings();
  MainWidget* main_widget_ptr_;
  s21::Controller* controller_;
};

#endif  // OPENGLWIDGET_H
