#include "widget.h"
#include "ui_widget.h"
#include<QDialog>
#include"dialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)//in fact, this expression is creating a instance for widget
{
    ui->setupUi(this);
    //QDialog dialog(this);//create a instance of QDialog
  //  dialog.show();//show this dialog in the widget
    /*QDialog *dialog=new QDialog(this);
    dialog->setWindowModality(Qt::WindowModal);
    dialog->show();*/
    //connect(ui->showChildButton,SIGNAL(clicked()),this,SLOT(showChildDialog()));
    //ui is a instance of widget, showChildButton is a member of widget,which was created in qt_designer.

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_showChildButton_clicked()
{
    QDialog *dialog=new QDialog(this);
    dialog->show();
}

void Widget::on_pushButton_2_clicked()
{
    close();
}

