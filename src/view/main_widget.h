#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "../controller/controller.h"

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
