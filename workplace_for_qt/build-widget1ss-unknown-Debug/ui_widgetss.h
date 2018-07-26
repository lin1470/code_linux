/********************************************************************************
** Form generated from reading UI file 'widgetss.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSS_H
#define UI_WIDGETSS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widgetss
{
public:
    QPushButton *display_dialog;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *Widgetss)
    {
        if (Widgetss->objectName().isEmpty())
            Widgetss->setObjectName(QString::fromUtf8("Widgetss"));
        Widgetss->setWindowModality(Qt::ApplicationModal);
        Widgetss->resize(400, 300);
        display_dialog = new QPushButton(Widgetss);
        display_dialog->setObjectName(QString::fromUtf8("display_dialog"));
        display_dialog->setGeometry(QRect(120, 110, 80, 29));
        pushButton = new QPushButton(Widgetss);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 160, 80, 29));
        pushButton_2 = new QPushButton(Widgetss);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 170, 80, 29));
        label = new QLabel(Widgetss);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 40, 101, 21));

        retranslateUi(Widgetss);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Widgetss, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), Widgetss, SLOT(close()));

        QMetaObject::connectSlotsByName(Widgetss);
    } // setupUi

    void retranslateUi(QWidget *Widgetss)
    {
        Widgetss->setWindowTitle(QApplication::translate("Widgetss", "Widgetss", 0, QApplication::UnicodeUTF8));
        display_dialog->setText(QApplication::translate("Widgetss", "\346\230\276\347\244\272\344\270\200\344\270\252dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widgetss", "\351\207\215\346\226\260\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widgetss", "\351\200\200\345\207\272\347\250\213\345\272\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widgetss", "\344\275\240\345\245\275\350\277\231\346\230\257\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widgetss: public Ui_Widgetss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSS_H
