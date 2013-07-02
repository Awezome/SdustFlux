#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>
#include <aboutpass.h>
#include "widget.h"
#include <QDir>
#include <QProcess>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Popup|Qt::Tool);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setFixedSize(337,319);

    file_name=QDir::homePath()+"/"+Config::file;
    ui->pushButton->setDefault(true);
    ui->lineEdit_login_name->setFocus();
}

login::~login(){
    delete ui;
}

void login::mousePressEvent(QMouseEvent * event){
    if (event->button() == Qt::LeftButton){
         dragPosition = event->globalPos() - frameGeometry().topLeft();
         //globalPos()获取根窗口的相对路径，frameGeometry().topLeft()获取主窗口左上角的位置
         event->accept();   //鼠标事件被系统接收
    }
}

void login::mouseMoveEvent(QMouseEvent * event){
    if (event->buttons() == Qt::LeftButton){
         move(event->globalPos()-dragPosition);//移动窗口
         event->accept();
    }
}

void login::closeEvent(QCloseEvent *){
    //emit to_show_face_widget();
}

void login::on_toolButton_about_clicked()
{
   AboutPass *show_this=new AboutPass(this);
   show_this->show();
}

void login::on_toolButton_cancel_clicked()
{
    this->close();
    QApplication::quit();
}

void login::on_pushButton_clicked()
{
    QString input_name=this->ui->lineEdit_login_name->text();
    QString input_pass=this->ui->lineEdit_login_pass->text();
    if(input_name.isEmpty()||input_pass.isEmpty()){
        QMessageBox::warning(this,tr("错误"),tr("用户名或密码不能为空!"),QMessageBox::Yes);
        return;
    }
    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
       return;
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_8);
    out <<input_name<<input_pass;

    QApplication::quit();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}
