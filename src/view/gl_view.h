#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include "main_widget.h"

class OpenGLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  OpenGLWidget(QWidget *parent = nullptr, MainWidget* mw_prt = nullptr);

  void setMainWidgetPtr(MainWidget* ptr) {
      main_widget_ptr_ = ptr;
  }

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
  void setupPerspective();
  void initRenderSettings();
  MainWidget* main_widget_ptr_;
};

#endif  // OPENGLWIDGET_H

