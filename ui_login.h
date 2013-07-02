/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Sat Mar 30 17:57:28 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLineEdit *lineEdit_login_name;
    QLineEdit *lineEdit_login_pass;
    QPushButton *pushButton;
    QToolButton *toolButton_cancel;
    QToolButton *toolButton_about;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->setEnabled(true);
        login->resize(337, 318);
        lineEdit_login_name = new QLineEdit(login);
        lineEdit_login_name->setObjectName(QString::fromUtf8("lineEdit_login_name"));
        lineEdit_login_name->setGeometry(QRect(90, 102, 200, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        lineEdit_login_name->setFont(font);
        lineEdit_login_name->setStyleSheet(QString::fromUtf8("background-color:#46B9F0;\n"
"border:0;\n"
"color: rgb(255, 255, 255);"));
        lineEdit_login_pass = new QLineEdit(login);
        lineEdit_login_pass->setObjectName(QString::fromUtf8("lineEdit_login_pass"));
        lineEdit_login_pass->setGeometry(QRect(90, 178, 200, 31));
        lineEdit_login_pass->setFont(font);
        lineEdit_login_pass->setStyleSheet(QString::fromUtf8("background-color:#46B9F0;\n"
"border:0;\n"
"color: rgb(255, 255, 255);"));
        lineEdit_login_pass->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 250, 71, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{border:1px solid #46B9F0;background-color:#222; color:#fff;}\n"
"QPushButton:hover {background-color:#444; color:#46B9F0;}\n"
"QPushButton:pressed {background-color:#000; color:#fff;}"));
        toolButton_cancel = new QToolButton(login);
        toolButton_cancel->setObjectName(QString::fromUtf8("toolButton_cancel"));
        toolButton_cancel->setGeometry(QRect(260, 250, 41, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(true);
        font2.setWeight(75);
        toolButton_cancel->setFont(font2);
        toolButton_cancel->setStyleSheet(QString::fromUtf8("QToolButton{border:1px solid #FF3300;background-color:#222; color:#fff;}\n"
"QToolButton:hover {background-color:#444; color:#FF3300;}\n"
"QToolButton:pressed {background-color:#000; color:#fff;}"));
        toolButton_about = new QToolButton(login);
        toolButton_about->setObjectName(QString::fromUtf8("toolButton_about"));
        toolButton_about->setGeometry(QRect(40, 250, 61, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        toolButton_about->setFont(font3);
        toolButton_about->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_about->setStyleSheet(QString::fromUtf8("border:0;\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 337, 318));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/image/image/login.png);"));
        label_2 = new QLabel(login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 40, 71, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(20);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->raise();
        lineEdit_login_name->raise();
        lineEdit_login_pass->raise();
        pushButton->raise();
        toolButton_cancel->raise();
        toolButton_about->raise();
        label_2->raise();

        retranslateUi(login);
        QObject::connect(toolButton_cancel, SIGNAL(clicked()), login, SLOT(close()));

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        lineEdit_login_name->setText(QString());
        pushButton->setText(QApplication::translate("login", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        toolButton_cancel->setText(QApplication::translate("login", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        toolButton_about->setText(QApplication::translate("login", "\345\257\206\347\240\201\350\257\264\346\230\216", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("login", "\347\231\273  \345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
