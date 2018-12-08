#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("小弟");
    b.setParent(this);
    b.setText("切换到主窗口");
    connect(&b,&QPushButton::clicked,this,&SubWidget::sendSignal);
    resize(400,450);
}

void SubWidget::sendSignal()
{
    /*
     * 实际上发送信号的是子窗口的这个类
     */i
    emit mySignal();

    emit mySignal(4,"你好呀!");

}
