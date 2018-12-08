#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>
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

    // 利用自定义的指针函数来重载信号以区分不同参数的信号类型.
//    void (SubWidget::*sigFunc1)() = &SubWidget::mySignal;
//    void (SubWidget::*sigFunc2)(int,QString) = &SubWidget::mySignal;
//    connect(&w,sigFunc1,this,&MainWidget::dealSub);
//    connect(&w,sigFunc2,this,&MainWidget::dealSub2);

    /*
     * qt4的信号重载比较方便,但是相应的,出现错误的编译不检查只能运行时出现错误.
     * 而且槽函数必须有关键字的修饰.
     *
     */

    connect(&w,SIGNAL(mySignal()),this,SLOT(dealSub()));
    connect(&w,SIGNAL(mySignal(int,QString)),this,SLOT(dealSub2(int,QString)));

    /*
     * 因为这两个SIGNAL和SLOT是宏定义来的,编译的时候只会进行宏替换的运算,而不会进行语法的检查,所以
     * 当出现出现错误的时候只能等待到运行错误的时候才能发现,而且运行错误的时候还不是报错,只能是一个提示
     * 而已,所以在用的时候为了代码的健壮性,应该尽量使用qt5的信号绑定来使用.
     */

    /*
     * lambda表达式,匿名函数
     * c++新增特性,项目文件:CONFIG += C++11
     * 配合信号使用,非常方便.
     */
    QPushButton *b4 = new QPushButton(this);
    b4->setText("lambda表达式");
    b4->move(150,150);
    int a =100,b =101;
    /*
     * 注意:
     * = 是以传值的方式把外部变量和类内成员传进去,但是不能够进行修改,如果要修改的话得用关键字mutale
     * & 以引用方式把外部变量传进去
     * this 把类中所有成员变量以引用传进去
     */
    connect(b4,&QPushButton::clicked,this,
            [=](bool checked) mutable
    {
        a =101;
        qDebug() << "check is " << checked << endl;
        qDebug() << a << b << endl;
        qDebug() << "hello the b4" << endl;
    });
    /*
     * 按钮引发的是一个信号的发送函数,其实发送信号的是信号本身的部件的发送的,就是那个
     * emit signal();
     */
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
void MainWidget::dealSub2(int a,QString str)
{
    qDebug()<< a << str.toUtf8().data() << endl;

}
