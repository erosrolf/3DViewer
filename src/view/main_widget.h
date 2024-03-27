#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QFileDialog>
#include <QColorDialog>
#include <QWidget>

#include "../controller/controller.h"


//#include <QMainWindow>
//#include <QPixmap>
//#include <QScreen>
//#include <QSettings>
//#include <QTimer>

//#include "qgifimage.h"

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

 private slots:
  void onBackgroundColorClicked();
  void onVertexesColorClicked();
  void onEdgesColorClicked();
  void onVertexScaleSliderSliderMoved(int action);
  void onEdgeScaleSliderSliderMoved(int action);
  void onVertexModeSettingsCurrentIndexChanged(int index);
  void onEdgeModeSettingsCurrentIndexChanged(int index);
  void onPerspectiveSettingsCurrentIndexChanged(int index);

 private:
  Ui::MainWidget *ui;
  s21::Controller* controller_;
};
#endif  // MAINWIDGET_H
