/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Jul 2 12:08:04 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_acc_val;
    QLabel *label_acc;
    QLabel *label_name;
    QLabel *label_name_val;
    QLabel *label_group;
    QLabel *label_group_val;
    QLabel *label_flux_val;
    QLabel *label_flux_val_2;
    QLabel *label_update;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_remainder;
    QLabel *label_remainder_val;
    QLabel *label_passsum;
    QLabel *label_passper;
    QLabel *label_passper_val;
    QLabel *label_passsum_val;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setEnabled(true);
        Widget->resize(418, 270);
        label_acc_val = new QLabel(Widget);
        label_acc_val->setObjectName(QString::fromUtf8("label_acc_val"));
        label_acc_val->setGeometry(QRect(110, 70, 101, 19));
        label_acc_val->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: #fff;"));
        label_acc = new QLabel(Widget);
        label_acc->setObjectName(QString::fromUtf8("label_acc"));
        label_acc->setGeometry(QRect(60, 70, 41, 19));
        label_acc->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: #fff;"));
        label_name = new QLabel(Widget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(240, 70, 61, 19));
        label_name->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: #fff;"));
        label_name_val = new QLabel(Widget);
        label_name_val->setObjectName(QString::fromUtf8("label_name_val"));
        label_name_val->setGeometry(QRect(290, 70, 71, 19));
        label_name_val->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #fff;"));
        label_group = new QLabel(Widget);
        label_group->setObjectName(QString::fromUtf8("label_group"));
        label_group->setGeometry(QRect(60, 100, 51, 20));
        label_group->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: #fff;"));
        label_group_val = new QLabel(Widget);
        label_group_val->setObjectName(QString::fromUtf8("label_group_val"));
        label_group_val->setGeometry(QRect(110, 100, 121, 20));
        label_group_val->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: #fff;"));
        label_flux_val = new QLabel(Widget);
        label_flux_val->setObjectName(QString::fromUtf8("label_flux_val"));
        label_flux_val->setGeometry(QRect(50, 176, 121, 20));
        label_flux_val->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_flux_val_2 = new QLabel(Widget);
        label_flux_val_2->setObjectName(QString::fromUtf8("label_flux_val_2"));
        label_flux_val_2->setGeometry(QRect(235, 176, 131, 20));
        label_flux_val_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_flux_val_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_update = new QLabel(Widget);
        label_update->setObjectName(QString::fromUtf8("label_update"));
        label_update->setEnabled(true);
        label_update->setGeometry(QRect(46, 225, 211, 16));
        label_update->setStyleSheet(QString::fromUtf8("color: #fff;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(44, 170, 331, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        progressBar->setFont(font);
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 418, 270));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/image/image/show.png);"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 20, 221, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_remainder = new QLabel(Widget);
        label_remainder->setObjectName(QString::fromUtf8("label_remainder"));
        label_remainder->setGeometry(QRect(240, 100, 61, 19));
        label_remainder->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: #fff;"));
        label_remainder_val = new QLabel(Widget);
        label_remainder_val->setObjectName(QString::fromUtf8("label_remainder_val"));
        label_remainder_val->setGeometry(QRect(290, 100, 71, 19));
        label_remainder_val->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #fff;"));
        label_passsum = new QLabel(Widget);
        label_passsum->setObjectName(QString::fromUtf8("label_passsum"));
        label_passsum->setGeometry(QRect(240, 130, 61, 19));
        label_passsum->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: #fff;"));
        label_passper = new QLabel(Widget);
        label_passper->setObjectName(QString::fromUtf8("label_passper"));
        label_passper->setGeometry(QRect(60, 130, 81, 20));
        label_passper->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: #fff;"));
        label_passper_val = new QLabel(Widget);
        label_passper_val->setObjectName(QString::fromUtf8("label_passper_val"));
        label_passper_val->setGeometry(QRect(110, 130, 121, 20));
        label_passper_val->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: #fff;"));
        label_passsum_val = new QLabel(Widget);
        label_passsum_val->setObjectName(QString::fromUtf8("label_passsum_val"));
        label_passsum_val->setGeometry(QRect(290, 130, 71, 19));
        label_passsum_val->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #fff;"));
        label->raise();
        label_acc_val->raise();
        label_acc->raise();
        label_name->raise();
        label_name_val->raise();
        label_group->raise();
        label_group_val->raise();
        label_update->raise();
        progressBar->raise();
        label_flux_val_2->raise();
        label_flux_val->raise();
        label_2->raise();
        label_remainder->raise();
        label_remainder_val->raise();
        label_passsum->raise();
        label_passper->raise();
        label_passper_val->raise();
        label_passsum_val->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label_acc_val->setText(QString());
        label_acc->setText(QApplication::translate("Widget", "\350\264\246\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_name->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_name_val->setText(QString());
        label_group->setText(QApplication::translate("Widget", "\345\245\227\351\244\220\357\274\232", 0, QApplication::UnicodeUTF8));
        label_group_val->setText(QString());
        label_flux_val->setText(QApplication::translate("Widget", "null", 0, QApplication::UnicodeUTF8));
        label_flux_val_2->setText(QApplication::translate("Widget", "null", 0, QApplication::UnicodeUTF8));
        label_update->setText(QApplication::translate("Widget", "Loading...", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("Widget", "\345\277\253\351\200\232\346\265\201\351\207\217\346\237\245\350\257\242\345\267\245\345\205\267 V4.0", 0, QApplication::UnicodeUTF8));
        label_remainder->setText(QApplication::translate("Widget", "\345\211\251\344\275\231\357\274\232", 0, QApplication::UnicodeUTF8));
        label_remainder_val->setText(QString());
        label_passsum->setText(QApplication::translate("Widget", "\350\266\205\345\207\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_passper->setText(QApplication::translate("Widget", "\350\266\205\350\277\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_passper_val->setText(QString());
        label_passsum_val->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
