#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include "../controller/controller.h"

//#include <QColorDialog>

//#include <QMainWindow>
//#include <QPixmap>
//#include <QScreen>
//#include <QSettings>
//#include <QTimer>

//#include "qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void openFileBtnClicked();

private:
    Ui::MainWidget *ui;
    s21::Controller controller;
};
#endif // MAINWIDGET_H
