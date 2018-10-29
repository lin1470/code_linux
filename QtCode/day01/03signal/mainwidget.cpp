#include "mainwidget.h"
#include <QPushButton>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.move(100,100);
    b1.setText("close");
    b2 = new QPushButton(this);
    b2->move(200,290);
    b2->setText("我好惨的呀");
    resize(400,400);

    connect(&b1,&QPushButton::pressed,this,&MainWidget::close );
    /* &b1:信号发出者,指针类型
     * &QPushButton::pressed:处理的信号
     * this:信号接受者
     * 槽函数,信号处理函数
     */
    /* 自定义槽,普通函数的用法
     * 任意的成员函数,普通全局函数,静态函数
     * 槽函数徐娅和信号一直(参数和返回值)
     * 由于信号没有返回值,所以槽函数都没有返回值.
     */
    connect(b2,&QPushButton::released,this,&MainWidget::mySlot);
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);

    /* 信号:短信
     * 槽函数:接受短信的手机
     */
    setWindowTitle("老大");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);
// 显示子窗口
//    w.show();
    connect(&b3,&QPushButton::released,this,&MainWidget::displaySub);
    connect(&w,&SubWidget::mySignal,this,&MainWidget::dealSub);

}


MainWidget::~MainWidget()
{

}
void MainWidget::mySlot()
{
    b2->setText("123");
}
void MainWidget::displaySub()
{
    this->hide();
    w.show();
}
void MainWidget::dealSub()
{
    this->show();
    w.hide();
}
