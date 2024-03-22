#include "main_widget.h"
#include "./ui_main_widget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->renderSettingsTabGroup->setTabIcon(0, QIcon(":/vertex_24x24.png"));
    ui->renderSettingsTabGroup->setTabIcon(1, QIcon(":/cube_24x24.png"));
    ui->renderSettingsTabGroup->setTabIcon(2, QIcon(":/palette_24x24.png"));

}

MainWidget::~MainWidget()
{
    delete ui;
}
