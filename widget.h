#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include "login.h"
#include <qtsoap.h>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include <QMenu>
#include "dao.h"
#include "config.h"
#include "plotter.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget{
    Q_OBJECT

public:
    void contextMenuEvent(QContextMenuEvent *);
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void face_creat();
    login *show_login;
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
private slots:
    void slotAbout();
    void slotQuit();
    void slotLogout();

    void slotUpdate(QNetworkReply *reply);

    void slotUser();
    void slotDay();
    void slotBill();
    void slotMonth();
    void slotFlag();

    void slotFluxDay();
    void slotChangelog();
    void slotHomepage();
private:
    dao *a;

    Ui::Widget *ui;
    QPoint dragPosition;

    QtSoapHttpTransport *http;

    void getUpdate();

    void delLoginFile();

    Plotter *plotter;
    QMenu *trayMenu;
    void Tray_Menu();
};

#endif // WIDGET_H
