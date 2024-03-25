#include "main_widget.h"


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
