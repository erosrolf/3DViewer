#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QFileDialog>
#include <QWidget>

#include "../controller/controller.h"

// #include <QColorDialog>

// #include <QMainWindow>
// #include <QPixmap>
// #include <QScreen>
// #include <QSettings>
// #include <QTimer>

// #include "qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

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

 private:
  s21::Controller* controller_;
  Ui::MainWidget* ui;
};
#endif  // MAINWIDGET_H
