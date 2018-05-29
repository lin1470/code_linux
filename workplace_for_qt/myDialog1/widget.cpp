#include "widget.h"
#include "ui_widget.h"
#include<QDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);//这是一个构造器来的
    /*QDialog* dialog=new QDialog(this);
    dialog->setModal(true);
    dialog->show();*/
    //connect(ui->showChildButton,SIGNAL(clicked()),this,SLOT(showChildDialog()));
    /*QDialog dialog(this);
    dialog.exec();这个是模态对话框*/

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_showChildButton_clicked()
{
    QDialog *dialog =new QDialog (this);
    dialog->show();
}
