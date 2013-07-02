#include "aboutpass.h"
#include "ui_aboutpass.h"

AboutPass::AboutPass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutPass)
{
    ui->setupUi(this);
}

AboutPass::~AboutPass()
{
    delete ui;
}
