#include "main_widget.h"

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

  connect(ui->open_file_btn, &QPushButton::clicked, this,&MainWidget::openFileBtnClicked);
  connect(ui->move_up_btn, &QPushButton::clicked, this, &MainWidget::moveUpBtnClicked);
  connect(ui->move_down_btn, &QPushButton::clicked, this, &MainWidget::moveDownBtnClicked);
  connect(ui->move_left_btn, &QPushButton::clicked, this, &MainWidget::moveLeftBtnClicked);
  connect(ui->move_right_btn, &QPushButton::clicked, this, &MainWidget::moveRightBtnClicked);

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

