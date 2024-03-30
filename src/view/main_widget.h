#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QColorDialog>
#include <QFileDialog>
#include <QSettings>
#include <QWidget>

#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

/**
 * @brief Main application window class
 */
class MainWidget : public QWidget {
  Q_OBJECT

 public:
  MainWidget(QWidget* parent = nullptr, s21::Controller* controller = nullptr);
  ~MainWidget();

  void openFileBtnClicked();
  void moveUpBtnClicked();
  void moveDownBtnClicked();
  void moveLeftBtnClicked();
  void moveRightBtnClicked();
  void zoomInClicked();
  void zoomOutClicked();
  void screenshotBtnClicked();
  void onXRotateSliderReleased();
  void onYRotateSliderReleased();
  void onZRotateSliderReleased();
  void onXRotateValueChanged(int value);
  void onYRotateValueChanged(int value);
  void onZRotateValueChanged(int value);

  void onBackgroundColorClicked();
  void onVertexesColorClicked();
  void onEdgesColorClicked();
  void onVertexScaleSliderSliderMoved(int action);
  void onEdgeScaleSliderSliderMoved(int action);
  void onVertexModeSettingsCurrentIndexChanged(int index);
  void onEdgeModeSettingsCurrentIndexChanged(int index);
  void onPerspectiveSettingsCurrentIndexChanged(int index);

  void writeSettings();
  void readSettings();

 private:
  Ui::MainWidget* ui;
  s21::Controller* controller_;
  int prev_val_x_rotate_;
  int prev_val_y_rotate_;
  int prev_val_z_rotate_;
};
#endif  // MAINWIDGET_H
