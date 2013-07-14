#include "widget.h"
#include "ui_widget.h"
#include <QTextCodec>
#include <QDebug>
#include <QMessageBox>
#include <QProcess>
#include <QDir>
#include <QNetworkReply>
#include <QDesktopServices>
#include "dao.h"

Widget::Widget(QWidget *parent) : QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    a=new dao();

    connect(a, SIGNAL(signalUser()), this, SLOT(slotUser()));
    connect(a, SIGNAL(signalDay()), this, SLOT(slotDay()));
    connect(a, SIGNAL(signalBill()), this, SLOT(slotBill()));
    connect(a, SIGNAL(signalMonth()), this, SLOT(slotMonth()));
    connect(a, SIGNAL(signalFlag()), this, SLOT(slotFlag()));

    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //setWindowFlags(Qt::WindowMinimizeButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setFixedSize(418,270);

    this->setWindowTitle(tr("快通流量查询工具 ")+Config::title);
    this->ui->label_update->setText(tr("快通流量查询工具 ")+Config::title);

    show_login=new login();

    face_creat();
    Tray_Menu();
    //getUpdate();
}

Widget::~Widget(){
    delete ui;
}
void Widget::mousePressEvent(QMouseEvent * event){
    if (event->button() == Qt::LeftButton){
         dragPosition = event->globalPos() - frameGeometry().topLeft();
         //globalPos()获取根窗口的相对路径，frameGeometry().topLeft()获取主窗口左上角的位置
         event->accept();   //鼠标事件被系统接收
    }
}

void Widget::mouseMoveEvent(QMouseEvent * event){
    if (event->buttons() == Qt::LeftButton){
         move(event->globalPos()-dragPosition);//移动窗口
         event->accept();
    }
}

void Widget::slotFlag(){
    if(a->getFlag().link){
        if(a->getFlag().flag){
            this->show();
        }else{
            QMessageBox::warning(this,tr("错误"),tr("用户名或名密错误!"),QMessageBox::Yes);
            show_login->show();
        }
    }else{
        QMessageBox::warning(this,tr("错误"),tr("无法连接服务器!"),QMessageBox::Yes);
    }
}

void Widget::face_creat(){
    QFile file(QDir::homePath()+"/"+Config::file);
    if(!file.open(QIODevice::ReadOnly)){
        show_login->show();
        return;
    }

    QString name,pass;
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_8);
    in>>name>>pass;

    qDebug()<<name<<"  "<<pass;
    a->setAccount(name,pass);
}

void Widget::slotFluxDay(){
    plotter->show();
}

void Widget::slotQuit(){
    this->close();
    QApplication::quit();
}

void Widget::slotHomepage(){
    QDesktopServices::openUrl(QUrl(Config::homepage));
}

void Widget::slotChangelog(){
    QDesktopServices::openUrl(QUrl(Config::changelog));
}

void Widget::getUpdate(){
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    connect(nam, SIGNAL(finished(QNetworkReply*)),this, SLOT(slotUpdate(QNetworkReply*)));

    QUrl url("http://192.168/flux/update.php?ver="+Config::ver);
    QNetworkReply* reply = nam->get(QNetworkRequest(url));
    //reply->abort();
}

void Widget::slotUpdate(QNetworkReply *reply){
    QString string = QString::fromUtf8(reply->readAll());

    if(string!="1"){
        ui->label_update->setText(string);
    }
    ui->label_update->setTextFormat(Qt::RichText);
    ui->label_update->setOpenExternalLinks(true);
}

void Widget::delLoginFile(){
    QFile file(QDir::homePath()+"/"+Config::file);
    if(file.exists()){
        if(file.remove()){
            QMessageBox::information(this,tr("注销成功"),tr("注销成功，点击重新登录!"),QMessageBox::Yes);
            QApplication::quit();
            QProcess::startDetached(qApp->applicationFilePath(), QStringList());
        }
    }
}

void Widget::slotLogout(){
    QApplication::setQuitOnLastWindowClosed(false);
    QMessageBox message(QMessageBox::NoIcon, "注销", "注销将清除现保存的密码，确定要注销？", QMessageBox::Yes | QMessageBox::No);
    if(message.exec() == QMessageBox::Yes){
        delLoginFile();
    }else{
        return ;
    }
}

void Widget::Tray_Menu(){
    QAction *Tray_flux_day = new QAction("月流量", this);
    //Tray_flux_day->setIcon(QIcon(":/image/image/checkmark.png"));
    connect(Tray_flux_day, SIGNAL(triggered(bool)), this, SLOT(slotFluxDay()));

    QAction *Tray_logout = new QAction("注销", this);
    Tray_logout->setIcon(QIcon(":/image/image/repeat.png"));
    connect(Tray_logout, SIGNAL(triggered(bool)), this, SLOT(slotLogout()));

    QAction *Tray_quit = new QAction("退出", this);
    Tray_quit->setIcon(QIcon(":/image/image/delete.png"));
    connect(Tray_quit, SIGNAL(triggered(bool)), this, SLOT(slotQuit()));

    QAction *Tray_homepage = new QAction("官方主页", this);
    //Tray_flux_day->setIcon(QIcon(":/image/image/checkmark.png"));
    connect(Tray_homepage, SIGNAL(triggered(bool)), this, SLOT(slotHomepage()));

    QAction *Tray_changelog = new QAction("更新日志", this);
    connect(Tray_changelog, SIGNAL(triggered(bool)), this, SLOT(slotChangelog()));

    trayMenu = new QMenu(this);//创建菜单
    trayMenu->addAction(Tray_flux_day);
    trayMenu->addSeparator();
    trayMenu->addAction(Tray_homepage);
    trayMenu->addAction(Tray_changelog);
    trayMenu->addSeparator();
    trayMenu->addAction(Tray_logout);
    trayMenu->addAction(Tray_quit);
}

void Widget::contextMenuEvent(QContextMenuEvent *){
    QCursor cur=this->cursor();
    trayMenu->exec(cur.pos()); //关联到光标
}

void Widget::slotUser(){
    ui->label_acc_val->setText(a->getUser().account);
    ui->label_name_val->setText(a->getUser().realName);
    ui->label_group_val->setText(a->getUser().groupName);
}
void Widget::slotDay(){
    QStringList annotateList;
    annotateList << QObject::tr("时间") << QObject::tr("流量");
    QStringList timeList;

    int begin=1;
    int getDayLength=a->getDay().length();
    for(int i=begin;i<getDayLength;i++){
        timeList.append(a->getDay().at(i).logDate);
    }

    int maxtemp=0;
    QList<double> valueList;
    for(int i=begin;i<getDayLength;i++){
        float aaa=a->getDay().at(i).totalFlux;
        valueList<<aaa;
        if(maxtemp<aaa)
            maxtemp=aaa;
    }

    plotter=new Plotter(maxtemp, 0, timeList, annotateList, valueList);
}
void Widget::slotBill(){

}
void Widget::slotMonth(){
    int flux_total=a->getMonth().total;
    int flux_used=a->getMonth().used;

    int fluxRemainder=flux_total-flux_used;
    ui->label_passper_val->setText(QString("%1").arg(a->getUser().pricePerMB)+tr("元/MB"));
    int pass=0;
    QString flux_shengyu=tr("剩余");
    if(fluxRemainder<0){
        ui->label_remainder->setText(tr("超出："));
        fluxRemainder=-fluxRemainder;
        flux_shengyu=tr("超出");
        pass=fluxRemainder;
    }
    ui->label_passsum_val->setText(QString("%1").arg(pass*a->getUser().pricePerMB)+tr("元"));
    ui->label_remainder_val->setText(QString::number((double)(fluxRemainder)/(double)1024,'d',2)+tr("G"));
    ui->label_flux_val->setText(tr("已用")+QString::number(flux_used)+tr("MB"));
    ui->label_flux_val_2->setText(flux_shengyu+QString::number(fluxRemainder)+tr("MB"));

    int fluxPercent=(double)flux_used/(double)flux_total*10;

    QString chunk_color;
    switch(fluxPercent){
        case 0:case 1:case 2:case 3:case 4:case 5:case 6:
            chunk_color="#46B9F0";
            break;
        case 7:case 8:
            chunk_color="#FFFF00";
            break;
        default:
            chunk_color="#FF3300";
            break;
    }
    ui->progressBar->setStyleSheet("QProgressBar::chunk {background-color: "+chunk_color+";}");

    if(flux_total<=flux_used)
        flux_used=flux_total;
    ui->progressBar->setRange(0,flux_total);
    ui->progressBar->setValue(flux_used);
}
