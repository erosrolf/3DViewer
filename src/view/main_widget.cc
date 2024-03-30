#include "main_widget.h"

#include <QFileDialog>
#include <QPushButton>
#include <QString>

#include "./ui_main_widget.h"
#include "controller/controller.h"

MainWidget::MainWidget(QWidget *parent, s21::Controller *controller)
    : QWidget(parent), controller_(controller), ui(new Ui::MainWidget) {
  ui->setupUi(this);
  readSettings();

  ui->gl_widget->setMainWidgetPtr(this);
  ui->gl_widget->setControllerPtr(controller_);
  ui->settings_tab_gr->setTabIcon(0, QIcon(":/vertex_24x24.png"));
  ui->settings_tab_gr->setTabIcon(1, QIcon(":/cube_24x24.png"));
  ui->settings_tab_gr->setTabIcon(2, QIcon(":/palette_24x24.png"));

  connect(ui->open_file_btn, &QPushButton::clicked, this,
          &MainWidget::openFileBtnClicked);
  connect(ui->move_up_btn, &QPushButton::clicked, this,
          &MainWidget::moveUpBtnClicked);
  connect(ui->move_down_btn, &QPushButton::clicked, this,
          &MainWidget::moveDownBtnClicked);
  connect(ui->move_left_btn, &QPushButton::clicked, this,
          &MainWidget::moveLeftBtnClicked);
  connect(ui->move_right_btn, &QPushButton::clicked, this,
          &MainWidget::moveRightBtnClicked);
  connect(ui->zoom_in, &QPushButton::clicked, this, &MainWidget::zoomInClicked);
  connect(ui->zoom_out, &QPushButton::clicked, this,
          &MainWidget::zoomOutClicked);
  connect(ui->move_forward_btn, &QPushButton::clicked, this,
          &MainWidget::zoomInClicked);
  connect(ui->move_back_btn, &QPushButton::clicked, this,
          &MainWidget::zoomOutClicked);
  connect(ui->x_rotate_slider, &QSlider::sliderReleased, this,
          &MainWidget::onXRotateSliderReleased);
  connect(ui->y_rotate_slider, &QSlider::sliderReleased, this,
          &MainWidget::onYRotateSliderReleased);
  connect(ui->z_rotate_dial, &QSlider::sliderReleased, this,
          &MainWidget::onZRotateSliderReleased);
  connect(ui->x_rotate_slider, &QSlider::valueChanged, this,
          &MainWidget::onXRotateValueChanged);
  connect(ui->y_rotate_slider, &QSlider::valueChanged, this,
          &MainWidget::onYRotateValueChanged);
  connect(ui->z_rotate_dial, &QDial::valueChanged, this,
          &MainWidget::onZRotateValueChanged);
  connect(ui->screenshot_btn, &QPushButton::clicked, this,
          &MainWidget::screenshotBtnClicked);

  connect(ui->background_btn, &QPushButton::clicked, this,
          &MainWidget::onBackgroundColorClicked);
  connect(ui->vertexes_color_btn, &QPushButton::clicked, this,
          &MainWidget::onVertexesColorClicked);
  connect(ui->edges_color_btn, &QPushButton::clicked, this,
          &MainWidget::onEdgesColorClicked);
  connect(ui->vertex_scale_slider, &QSlider::sliderMoved, this,
          &MainWidget::onVertexScaleSliderSliderMoved);
  connect(ui->edge_scale_slider, &QSlider::sliderMoved, this,
          &MainWidget::onEdgeScaleSliderSliderMoved);
  connect(ui->vertex_mode_box, &QComboBox::currentIndexChanged, this,
          &MainWidget::onVertexModeSettingsCurrentIndexChanged);
  connect(ui->edge_mode_box, &QComboBox::currentIndexChanged, this,
          &MainWidget::onEdgeModeSettingsCurrentIndexChanged);
  connect(ui->perspective_mode_box, &QComboBox::currentIndexChanged, this,
          &MainWidget::onPerspectiveSettingsCurrentIndexChanged);
}

MainWidget::~MainWidget() {
  writeSettings();
  delete ui;
}

void MainWidget::openFileBtnClicked() {
  QString f_name = QFileDialog::getOpenFileName(this, "Выбор файла", "",
                                                "OBJ files (*.obj)");
  ui->obj_path_line->setText(f_name);
  if (ui->obj_path_line->text().size() > 0) {
    QByteArray ba = f_name.toLocal8Bit();
    char *input = ba.data();
    controller_->openNewObj(input);
    if (controller_->objIsValid()) {
      ui->vert_counter->setText(
          QString::number(controller_->getObjVertexes().size()) + " ");
      ui->poly_counter->setText(
          QString::number(controller_->getObjPolygons().size()) + " ");
      controller_->objCentering();
    } else {
      ui->vert_counter->setText("0 ");
      ui->poly_counter->setText("0 ");
      ui->obj_path_line->setText("Incorrect .obj file");
    }
  }
}

void MainWidget::moveUpBtnClicked() {
  controller_->objMoveUp(0.5);
  ui->gl_widget->update();
}

void MainWidget::moveDownBtnClicked() {
  controller_->objMoveDown(0.5);
  ui->gl_widget->update();
}

void MainWidget::moveLeftBtnClicked() {
  controller_->objMoveToLeft(0.5);
  ui->gl_widget->update();
}

void MainWidget::moveRightBtnClicked() {
  controller_->objMoveToRight(0.5);
  ui->gl_widget->update();
}

void MainWidget::zoomInClicked() {
  controller_->objZoom(1.1);
  ui->gl_widget->update();
}

void MainWidget::zoomOutClicked() {
  controller_->objZoom(0.9);
  ui->gl_widget->update();
}

void MainWidget::onXRotateSliderReleased() {
  prev_val_x_rotate_ = 0;
  ui->x_rotate_slider->setSliderPosition(0);
}

void MainWidget::onYRotateSliderReleased() {
  prev_val_y_rotate_ = 0;
  ui->y_rotate_slider->setSliderPosition(0);
}

void MainWidget::onZRotateSliderReleased() {
  prev_val_z_rotate_ = 0;
  ui->z_rotate_dial->setSliderPosition(0);
}

void MainWidget::onXRotateValueChanged(int value) {
  if (controller_->objIsValid()) {
    if (value < prev_val_x_rotate_) {
      controller_->objRotateAroundX(5);
    } else if (value) {
      controller_->objRotateAroundX(-5);
    }
    prev_val_x_rotate_ = value;
    ui->gl_widget->update();
  }
}

void MainWidget::onYRotateValueChanged(int value) {
  if (controller_->objIsValid()) {
    if (value < prev_val_y_rotate_) {
      controller_->objRotateAroundY(5);
    } else if (value) {
      controller_->objRotateAroundY(-5);
    }
    prev_val_y_rotate_ = value;
    ui->gl_widget->update();
  }
}

void MainWidget::onZRotateValueChanged(int value) {
  if (controller_->objIsValid()) {
    if (value < prev_val_z_rotate_) {
      controller_->objRotateAroundZ(5);
    } else if (value) {
      controller_->objRotateAroundZ(-5);
    }
    prev_val_z_rotate_ = value;
    ui->gl_widget->update();
  }
}
void MainWidget::onBackgroundColorClicked() {
  QColor background = QColorDialog::getColor();
  if (background.isValid()) {
    ui->gl_widget->setting.background_color = background;
    ui->gl_widget->update();
  }
}

void MainWidget::onVertexesColorClicked() {
  QColor vertexes_color = QColorDialog::getColor();
  if (vertexes_color.isValid()) {
    ui->gl_widget->setting.vertex_color = vertexes_color;
    ui->gl_widget->update();
  }
}

void MainWidget::onEdgesColorClicked() {
  QColor edges_color = QColorDialog::getColor();
  if (edges_color.isValid()) {
    ui->gl_widget->setting.edge_color = edges_color;
    ui->gl_widget->update();
  }
}

void MainWidget::onVertexScaleSliderSliderMoved(int action) {
  ui->gl_widget->setting.vertex_size = action;
  ui->gl_widget->update();
}

void MainWidget::onEdgeScaleSliderSliderMoved(int action) {
  ui->gl_widget->setting.edge_width = action;
  ui->gl_widget->update();
}

void MainWidget::onVertexModeSettingsCurrentIndexChanged(int index) {
  ui->gl_widget->setting.vertex_mode = index;
  ui->gl_widget->update();
}

void MainWidget::onEdgeModeSettingsCurrentIndexChanged(int index) {
  ui->gl_widget->setting.line_mode = index;
  ui->gl_widget->update();
}

void MainWidget::onPerspectiveSettingsCurrentIndexChanged(int index) {
  ui->gl_widget->setting.perspective_mode = index;
  ui->gl_widget->update();
}

void MainWidget::screenshotBtnClicked() {
  QFileDialog dialogPhoto(this);
  QString screenshot_name =
      dialogPhoto.getSaveFileName(this, "Save as...", "Screenshot",
                                  "BMP (*.bmp);; JPEG(*.jpeg) ;; PNG(*.png)");
  if (!screenshot_name.isEmpty()) {
    controller_->screenshot(*ui->gl_widget, screenshot_name);
  }
}

void MainWidget::writeSettings() {
  QSettings settings("MySoft", "3DViewerSettings");
  float backgroundColor[4];
  float edgeColor[4];
  float vertexColor[4];
  backgroundColor[0] = ui->gl_widget->setting.background_color.redF();
  backgroundColor[1] = ui->gl_widget->setting.background_color.greenF();
  backgroundColor[2] = ui->gl_widget->setting.background_color.blueF();
  backgroundColor[3] = ui->gl_widget->setting.background_color.alphaF();
  edgeColor[0] = ui->gl_widget->setting.edge_color.redF();
  edgeColor[1] = ui->gl_widget->setting.edge_color.greenF();
  edgeColor[2] = ui->gl_widget->setting.edge_color.blueF();
  edgeColor[3] = ui->gl_widget->setting.edge_color.alphaF();
  vertexColor[0] = ui->gl_widget->setting.vertex_color.redF();
  vertexColor[1] = ui->gl_widget->setting.vertex_color.greenF();
  vertexColor[2] = ui->gl_widget->setting.vertex_color.blueF();
  vertexColor[3] = ui->gl_widget->setting.vertex_color.alphaF();
  settings.setValue("backgroundColorRed", backgroundColor[0]);
  settings.setValue("backgroundColorGreen", backgroundColor[1]);
  settings.setValue("backgroundColorBlue", backgroundColor[2]);
  settings.setValue("backgroundColorAlpha", backgroundColor[3]);
  settings.setValue("edgeColorRed", edgeColor[0]);
  settings.setValue("edgeColorGreen", edgeColor[1]);
  settings.setValue("edgeColorBlue", edgeColor[2]);
  settings.setValue("edgeColorAlpha", edgeColor[3]);
  settings.setValue("vertexColorRed", vertexColor[0]);
  settings.setValue("vertexColorGreen", vertexColor[1]);
  settings.setValue("vertexColorBlue", vertexColor[2]);
  settings.setValue("vertexColorAlpha", vertexColor[3]);
  settings.setValue("vertexSize", ui->gl_widget->setting.vertex_size);
  settings.setValue("edgeWidth", ui->gl_widget->setting.edge_width);
  settings.setValue("perspectiveMode", ui->gl_widget->setting.perspective_mode);
  settings.setValue("lineMode", ui->gl_widget->setting.line_mode);
  settings.setValue("vertexMode", ui->gl_widget->setting.vertex_mode);
  settings.sync();
}

void MainWidget::readSettings() {
  QSettings settings("MySoft", "3DViewerSettings");
  ui->gl_widget->setting.background_color.setRedF(
      settings.value("backgroundColorRed", 0).toFloat());
  ui->gl_widget->setting.background_color.setGreenF(
      settings.value("backgroundColorGreen", 0).toFloat());
  ui->gl_widget->setting.background_color.setBlueF(
      settings.value("backgroundColorBlue", 0).toFloat());
  ui->gl_widget->setting.background_color.setAlphaF(
      settings.value("backgroundColorAlpha", 1).toFloat());
  ui->gl_widget->setting.edge_color.setRedF(
      settings.value("edgeColorRed", 1).toFloat());
  ui->gl_widget->setting.edge_color.setGreenF(
      settings.value("edgeColorGreen", 1).toFloat());
  ui->gl_widget->setting.edge_color.setBlueF(
      settings.value("edgeColorBlue", 1).toFloat());
  ui->gl_widget->setting.edge_color.setAlphaF(
      settings.value("edgeColorAlpha", 1).toFloat());
  ui->gl_widget->setting.vertex_color.setRedF(
      settings.value("vertexColorRed", 1).toFloat());
  ui->gl_widget->setting.vertex_color.setGreenF(
      settings.value("vertexColorGreen", 1).toFloat());
  ui->gl_widget->setting.vertex_color.setBlueF(
      settings.value("vertexColorBlue", 1).toFloat());
  ui->gl_widget->setting.vertex_color.setAlphaF(
      settings.value("vertexColorAlpha", 1).toFloat());
  ui->gl_widget->setting.vertex_size = settings.value("vertexSize", 1).toInt();
  ui->gl_widget->setting.edge_width = settings.value("edgeWidth", 1).toFloat();
  ui->gl_widget->setting.perspective_mode =
      settings.value("perspectiveMode", 1).toInt();
  ui->gl_widget->setting.line_mode = settings.value("lineMode", 0).toInt();
  ui->gl_widget->setting.vertex_mode = settings.value("vertexMode", 0).toInt();
}
