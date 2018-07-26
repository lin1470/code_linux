/********************************************************************************
** Form generated from reading UI file 'sure.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURE_H
#define UI_SURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_sure
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *sure)
    {
        if (sure->objectName().isEmpty())
            sure->setObjectName(QString::fromUtf8("sure"));
        sure->resize(400, 300);
        pushButton = new QPushButton(sure);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 190, 80, 29));
        pushButton_2 = new QPushButton(sure);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 190, 80, 29));
        textEdit = new QTextEdit(sure);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(100, 70, 161, 91));
        textEdit->setFrameShape(QFrame::NoFrame);

        retranslateUi(sure);
        QObject::connect(pushButton, SIGNAL(clicked()), sure, SLOT(reject()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), sure, SLOT(accept()));

        QMetaObject::connectSlotsByName(sure);
    } // setupUi

    void retranslateUi(QDialog *sure)
    {
        sure->setWindowTitle(QApplication::translate("sure", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("sure", "cancel", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("sure", "ok", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("sure", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\303\246\302\226\302\207\303\246\302\263\302\211\303\251\302\251\302\277\303\247\302\255\302\211\303\245\302\256\302\275\303\245\302\276\302\256\303\247\302\261\302\263\303\251\302\273\302\221'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600; font-style:italic; color:#aa0000;\">\347\241\256\345\256\232\345\220\227\357\274\237</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sure: public Ui_sure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURE_H
