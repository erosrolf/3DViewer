#include "main_widget.h"
#include "./ui_main_widget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->settings_tab_gr->setTabIcon(0, QIcon(":/vertex_24x24.png"));
    ui->settings_tab_gr->setTabIcon(1, QIcon(":/cube_24x24.png"));
    ui->settings_tab_gr->setTabIcon(2, QIcon(":/palette_24x24.png"));

    connect(ui->open_file_btn, &QPushButton::clicked, this, &MainWidget::openFileBtnClicked);
}

void MainWidget::openFileBtnClicked() {

}

MainWidget::~MainWidget()
{
    delete ui;
}


