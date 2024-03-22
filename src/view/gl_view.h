#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>

class OpenGLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  OpenGLWidget(QWidget *parent = nullptr);
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
  void setupPerspective();
  void initRenderSettings();
};

#endif  // OPENGLWIDGET_H

