#include "widget.h"
#include "ui_widget.h"
#include<QString>
#include<QDebug>
#include"sure.h"
#include"warning.h"

int pay=0;
int money=100;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
   // qDebug()<<str;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    pay=pay*10+1;
  //  qDebug()<<value;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_2_clicked()
{
    pay=pay*10+2;
  //  qDebug()<<value;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_3_clicked()
{
    pay=pay*10+3;
   // qDebug()<<value;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_4_clicked()
{
    pay=pay*10+4;
  //  qDebug()<<value;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_5_clicked()
{
   pay=pay*10+5;
   // qDebug()<<pay;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_6_clicked()
{
    pay=pay*10+6;
   // qDebug()<<value;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_7_clicked()
{
    pay=pay*10+7;
  //  qDebug()<<value;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_8_clicked()
{
    pay=pay*10+8;
  //  qDebug()<<value;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_9_clicked()
{
    pay=pay*10+9;
    //qDebug()<<value;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_10_clicked()
{
    pay=pay*10+0;
    //qDebug()<<value;
    ui->display->setText(QString::number(pay));
}

void Widget::on_pushButton_11_clicked()
{
    Sure ensure;
    if(ensure.exec()==QDialog::Accepted)
    {
    if(pay>money)
       // ui->display->setText("unsuccessfuly:not enough money");
       {
        Warning warning;
        warning.exec();
        }
       // ui->display->setText("hah");
    else
    {
        money-=pay;
        ui->money->setText(QString::number(money));
        ui->display->setText("");
    }

    pay=0;
    }

}
