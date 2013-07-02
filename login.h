#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QFile>
#include <QMouseEvent>
#include "config.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
signals:
    void to_show_face_widget();
private slots:
    void on_toolButton_about_clicked();
    void on_toolButton_cancel_clicked();
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    QString file_name;
    QPoint dragPosition;
protected:
    void closeEvent(QCloseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // LOGIN_H
