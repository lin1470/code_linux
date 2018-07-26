#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>
#include<QInputDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QColor color=QColorDialog::getColor(Qt::black,this,tr("颜色对话框"),QColorDialog::ShowAlphaChannel);
    qDebug()<<"color:"<<color;

}

void Widget::on_pushButton_2_clicked()
{
   //    QString filenames=QFileDialog::getOpenFileName(this,tr("文件对话框"),"/",tr("图片文件(*png *jpg;;文件文本(*txt)"));
    QString filenames=QFileDialog::getSaveFileName(this,tr("文本对话框"),"/",tr("图片文件(*png *jpg)"));
    qDebug()<<"filename:"<<filenames;
}

void Widget::on_pushButton_3_clicked()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok
                                    ,this);
    if(ok)
        ui->pushButton_3->setFont(font);
    else qDebug()<<tr("没有选择字体！");

}

void Widget::on_pushButton_4_clicked()
{
    bool ok;
    QString string=QInputDialog::getText(this,tr("输入字符串对话框"),tr("请输入用户名:"),QLineEdit::Normal,
                                         tr("admin"),&ok);
    if(ok) qDebug()<<"string:"<<string;
    //获取整数。
    int value1=QInputDialog::getInt(this,tr("请输入整数对话框"),tr("请输入-1000到1000之间的数值"),
                                    100,-1000,1000,10,&ok);
    if(ok) qDebug()<<"value1"<<value1;
    double value2=QInputDialog::getDouble(this,tr("请输入整数对话框"),tr("请输入-1000到1000之间的数值"),
                                          0.00,-1000,1000,2,&ok);
    if(ok) qDebug()<<"value2"<<value2;
    QStringList items;
    items<<"item1"<<"item2"
                    "";
    //获取条目
    QString item=QInputDialog::getItem(this,"the dialog of input","selete a item of this list please",items,0,true,&ok);
    if(ok) qDebug()<<"item"<<item;
}
