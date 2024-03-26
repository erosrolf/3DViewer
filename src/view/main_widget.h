#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QColorDialog>

#include "../controller/controller.h"


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

private slots:
    void on_background_btn_clicked();

    void on_vertexes_color_btn_clicked();

    void on_edges_color_btn_clicked();

    void on_vertexScaleSlider_actionTriggered(int action);

    void on_edgeScaleSlider_actionTriggered(int action);

    void on_vertex_mode_box_activated(int index);

    void on_edge_mode_box_activated(int index);

    void on_perspective_mode_box_activated(int index);

private:
    Ui::MainWidget *ui;
    s21::Controller controller;
};
#endif // MAINWIDGET_H
