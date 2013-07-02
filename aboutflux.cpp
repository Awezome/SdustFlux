#include "aboutflux.h"
#include "ui_aboutflux.h"

AboutFlux::AboutFlux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutFlux){
    ui->setupUi(this);
    this->setFixedSize(300,310);
    this->setWindowTitle(tr("关于快通流量查询工具"));
}

AboutFlux::~AboutFlux(){
    delete ui;
}
