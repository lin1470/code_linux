#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QColorDialog>
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
    QColor color=QColorDialog::getColor(Qt::red,this,tr("从此被否定"),QColorDialog::ShowAlphaChannel);
    qDebug()<<"color:"<<color;
    /*QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);//显示alpha选项
    dialog.exec();//以模态的方式运行对话框
    QColor color=dialog.currentColor();
    qDebug()<<"color:"<<color;//输出颜色的信息*/
}



void Widget::on_pushButton_7_clicked()
{
    bool ok;
    // 获取字符串
    QString string = QInputDialog::getText(this,tr("输入字符串对话框"),
              tr("请输入用户名："),QLineEdit::Normal,tr("admin"),&ok);
    if(ok) qDebug() << "string:"<<string;

    // 获取整数
    int value1 = QInputDialog::getInt(this,tr("输入整数对话框"),
              tr("请输入-1000到1000之间的数值"),100,-1000,1000,10,&ok);
    if(ok) qDebug() << "value1:"<<value1;

    // 获取浮点数
    double value2 = QInputDialog::getDouble(this,tr("输入浮点数对话框"),
              tr("请输入-1000到1000之间的数值"),0.00,-1000,1000,2,&ok);
    if(ok) qDebug() << "value2:"<<value2;

    // 获取条目
    QStringList items;
    items << tr("条目1") << tr("条目2");
    QString item = QInputDialog::getItem(this,tr("输入条目对话框"),
                               tr("请选择一个条目"),items,0,true,&ok);
    if(ok) qDebug() << "item:"<<item;
}
