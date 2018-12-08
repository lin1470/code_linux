#include "mywidget.h"
#include <QPushButton>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    /*
     * 父窗口是相对于原点
     * 原点: 屏幕左上方
     * x: 往右递增
     * y: 从上往下递增
     */
    resize(500,500);
     move(0,0);
     QPushButton *b = new QPushButton(this);
     b->setText("@ @");
     b->move(100,100);
     b->resize(100,100);

     /*
      * 子窗口相对于父窗口的原点.
      */
     QPushButton *b1 = new QPushButton(b);
     b1->setText("- -");
     b1->move(20,20);
     b1->resize(20,20);

     /*
      * 检测对象被自动释放
      */
     myButton *b2 = new myButton(this);
     b2->setText("b2");
    /*
     * 一般的c++中,如果没有手动释放那个分配的内存空间的话,那么是无法自动释放的
     * 尽管你是程序运行结束后,这个程序的内存会自动的销毁,但是不会自动调用析构函数
     * 要有两点:
     * 1.指定父对象. 2. 直接或者间接继承QOject.
     */

}

myWidget::~myWidget()
{

}
