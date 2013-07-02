/********************************************************************************
** Form generated from reading UI file 'aboutpass.ui'
**
** Created: Sat Mar 30 17:57:29 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTPASS_H
#define UI_ABOUTPASS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutPass
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *AboutPass)
    {
        if (AboutPass->objectName().isEmpty())
            AboutPass->setObjectName(QString::fromUtf8("AboutPass"));
        AboutPass->resize(293, 154);
        textBrowser = new QTextBrowser(AboutPass);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 271, 131));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        textBrowser->setFont(font);

        retranslateUi(AboutPass);

        QMetaObject::connectSlotsByName(AboutPass);
    } // setupUi

    void retranslateUi(QDialog *AboutPass)
    {
        AboutPass->setWindowTitle(QApplication::translate("AboutPass", "Dialog", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("AboutPass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\344\270\272\345\256\211\345\205\250\350\200\203\350\231\221\357\274\214\346\234\254\345\267\245\345\205\267\346\211\200\344\275\277\347\224\250\347\232\204\346\237\245\350\257\242\345\257\206\347\240\201\344\270\272\347\224\250\346\210\267\346\237\245\350\257\242\345\257\206\347\240\201\357\274\214\344\270\215\346\230\257\347\224\250\346\210\267\347\232\204\344\270\252\344\272\272\347\275\221\347\273\234\347\231\273\345\275\225\345\257\206\347\240\201\357\274\214\351\234\200\350\246\201\345"
                        "\210\260\351\235\222\345\262\233\345\277\253\351\200\232\351\200\232\350\256\257\346\234\211\351\231\220\345\205\254\345\217\270\346\217\220\344\276\233\347\232\204\351\241\265\351\235\242\350\277\233\350\241\214\350\256\276\347\275\256\343\200\202\347\275\221\345\235\200\344\270\272\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">http://10.200.255.0:8080/public/reg.aspx</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutPass: public Ui_AboutPass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTPASS_H
