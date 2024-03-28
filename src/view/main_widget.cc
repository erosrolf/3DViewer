#include "main_widget.h"

#include <QFileDialog>
#include <QPushButton>
#include <QString>

#include "./ui_main_widget.h"
#include "controller/controller.h"

MainWidget::MainWidget(QWidget *parent, s21::Controller *controller)
    : QWidget(parent), controller_(controller), ui(new Ui::MainWidget) {
  ui->setupUi(this);
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

  connect(ui->background_btn, &QPushButton::clicked, this, &MainWidget::onBackgroundColorClicked);
  connect(ui->vertexes_color_btn, &QPushButton::clicked, this, &MainWidget::onVertexesColorClicked);
  connect(ui->edges_color_btn, &QPushButton::clicked, this, &MainWidget::onEdgesColorClicked);
  connect(ui->vertexScaleSlider, &QSlider::sliderMoved, this, &MainWidget::onVertexScaleSliderSliderMoved);
  connect(ui->edgeScaleSlider, &QSlider::sliderMoved, this, &MainWidget::onEdgeScaleSliderSliderMoved);
  connect(ui->vertex_mode_box, &QComboBox::currentIndexChanged, this, &MainWidget::onVertexModeSettingsCurrentIndexChanged);
  connect(ui->edge_mode_box, &QComboBox::currentIndexChanged, this, &MainWidget::onEdgeModeSettingsCurrentIndexChanged);
  connect(ui->perspective_mode_box, &QComboBox::currentIndexChanged, this, &MainWidget::onPerspectiveSettingsCurrentIndexChanged);
}

MainWidget::~MainWidget() { delete ui; }

void MainWidget::openFileBtnClicked() {
  QString fName = QFileDialog::getOpenFileName(this, "Выбор файла", "",       "OBJ files (*.obj)");
  ui->obj_path_line->setText(fName);
  if (ui->obj_path_line->text().size() > 0) {
    QByteArray ba = fName.toLocal8Bit();
    char *inpt = ba.data();
    controller_->openNewObj(inpt);
    if (controller_->objIsValid()) {
      ui->vert_counter->setText(QString::number(controller_->getObjVertexes().size()) + " ");
      ui->poly_counter->setText(QString::number(controller_->getObjPolygons().size()) + " ");
    } else {
      ui->vert_counter->setText("0 ");
      ui->poly_counter->setText("0 ");
      ui->obj_path_line->setText("ERROR");
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
  prevValXRotate_ = 0;
  ui->x_rotate_slider->setSliderPosition(0);
}

void MainWidget::onYRotateSliderReleased() {
  prevValYRotate_ = 0;
  ui->y_rotate_slider->setSliderPosition(0);
}

void MainWidget::onZRotateSliderReleased() {
  prevValZRotate_ = 0;
  ui->z_rotate_dial->setSliderPosition(0);
}

void MainWidget::onXRotateValueChanged(int value) {
  if (controller_->objIsValid()) {
    if (value < prevValXRotate_) {
      controller_->objRotateAroundX(20);
    } else if (value) {
      controller_->objRotateAroundX(-20);
    }
    prevValXRotate_ = value;
    ui->gl_widget->update();
  }
}

void MainWidget::onYRotateValueChanged(int value) {
  if (controller_->objIsValid()) {
    if (value < prevValYRotate_) {
      controller_->objRotateAroundY(20);
    } else if (value) {
      controller_->objRotateAroundY(-20);
    }
    prevValYRotate_ = value;
    ui->gl_widget->update();
  }
}

void MainWidget::onZRotateValueChanged(int value) {
  if (controller_->objIsValid()) {
    if (value < prevValZRotate_) {
      controller_->objRotateAroundZ(20);
    } else if (value) {
      controller_->objRotateAroundZ(-20);
    }
    prevValZRotate_ = value;
    ui->gl_widget->update();
  }
}
void MainWidget::onBackgroundColorClicked() {
    QColor background = QColorDialog::getColor();
    if (background.isValid()) {
        ui->gl_widget->backgroundColor = background;
        ui->gl_widget->update();
    }
}

void MainWidget::onVertexesColorClicked() {
    QColor vertexesColor = QColorDialog::getColor();
    if (vertexesColor.isValid()) {
        ui->gl_widget->vertexColor = vertexesColor;
        ui->gl_widget->update();
    }
}

void MainWidget::onEdgesColorClicked() {
    QColor edgesColor = QColorDialog::getColor();
    if (edgesColor.isValid()) {
        ui->gl_widget->edgeColor = edgesColor;
        ui->gl_widget->update();
    }
}

void MainWidget::onVertexScaleSliderSliderMoved(int action) {
    ui->gl_widget->vertexSize = action;
    ui->gl_widget->update();
}

void MainWidget::onEdgeScaleSliderSliderMoved(int action) {
    ui->gl_widget->edgeWidth = action;
    ui->gl_widget->update();
}

void MainWidget::onVertexModeSettingsCurrentIndexChanged(int index) {
    ui->gl_widget->vertexMode = index;
    ui->gl_widget->update();
}

void MainWidget::onEdgeModeSettingsCurrentIndexChanged(int index) {
    ui->gl_widget->lineMode = index;
    ui->gl_widget->update();
}

void MainWidget::onPerspectiveSettingsCurrentIndexChanged(int index) {
    ui->gl_widget->perspectiveMode = index;
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
