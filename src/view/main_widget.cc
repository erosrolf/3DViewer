#include "main_widget.h"

#include "./ui_main_widget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidget) {
  ui->setupUi(this);
  ui->settings_tab_gr->setTabIcon(0, QIcon(":/vertex_24x24.png"));
  ui->settings_tab_gr->setTabIcon(1, QIcon(":/cube_24x24.png"));
  ui->settings_tab_gr->setTabIcon(2, QIcon(":/palette_24x24.png"));

  connect(ui->open_file_btn, &QPushButton::clicked, this,
          &MainWidget::openFileBtnClicked);
}

void MainWidget::openFileBtnClicked() {
  QString fName = QFileDialog::getOpenFileName(this, "Выбор файла", "",
                                               "OBJ files (*.obj)");
  ui->obj_path_line->setText(fName);
  if (ui->obj_path_line->text().size() > 0) {
    QByteArray ba = fName.toLocal8Bit();
    char *inpt = ba.data();
    s21::Controller cont;
    s21::Obj obj = cont.openNewObj(inpt);
    if (obj.is_valid) {
      ui->counterVert->setValue(obj.vertexes.size());
      ui->counterPoly->setValue(obj.polygons.size());
    } else {
      ui->counterVert->clear();
      ui->counterPoly->clear();
      ui->obj_path_line->setText("ERROR");
    }
  }
}

MainWidget::~MainWidget() { delete ui; }

void MainWidget::on_background_btn_clicked()
{
    QColor background = QColorDialog::getColor();
    if (background.isValid()) {
        ui->widget->backgroundColor = background;
        ui->widget->update();
    }
}

void MainWidget::on_vertexes_color_btn_clicked()
{
    QColor vertexesColor = QColorDialog::getColor();
    if (vertexesColor.isValid()) {
        ui->widget->vertexColor = vertexesColor;
        ui->widget->update();
    }
}


void MainWidget::on_edges_color_btn_clicked()
{
    QColor edgesColor = QColorDialog::getColor();
    if (edgesColor.isValid()) {
        ui->widget->edgeColor = edgesColor;
        ui->widget->update();
    }
}


void MainWidget::on_vertexScaleSlider_actionTriggered(int action)
{
    ui->widget->vertexSize = action;
    ui->widget->update();
}


void MainWidget::on_edgeScaleSlider_actionTriggered(int action)
{
    ui->widget->edgeWidth = action;
    ui->widget->update();
}


void MainWidget::on_vertex_mode_box_activated(int index)
{
    ui->widget->vertexMode = index;
    ui->widget->update();
}


void MainWidget::on_edge_mode_box_activated(int index)
{
    ui->widget->lineMode = index;
    ui->widget->update();
}


void MainWidget::on_perspective_mode_box_activated(int index)
{
    ui->widget->perspectiveMode = index;
    ui->widget->update();
}

