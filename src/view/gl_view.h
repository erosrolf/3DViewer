#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>

#include "controller/controller.h"
#include "main_widget.h"

class SettingState {
 public:
  SettingState()
      : perspective_mode(0),
        edge_color(QColor(Qt::white)),
        vertex_color(QColor(Qt::yellow)),
        background_color(QColor(Qt::black)){};

  int perspective_mode;
  int vertex_size;
  int edge_width;
  int line_mode;
  int vertex_mode;
  double aspect_ratio;
  double max_coordinate;
  QColor background_color;
  QColor edge_color;
  QColor vertex_color;
};

/**
 * @brief Widget in which the loaded 3D model is rendered.
 */
class OpenGLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  OpenGLWidget(QWidget* parent = nullptr, MainWidget* mw_ptr = nullptr,
               s21::Controller* controller_ptr = nullptr);

  void setMainWidgetPtr(MainWidget* ptr) { main_widget_ptr_ = ptr; }

  void setControllerPtr(s21::Controller* ptr) { controller_ = ptr; }

  SettingState setting;

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
