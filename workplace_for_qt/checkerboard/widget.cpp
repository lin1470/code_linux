#include "widget.h"
#include "ui_widget.h"
#include<QPainter>

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
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
   QPen pen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
   painter.setPen(pen);
  // QBrush brush(QColor(0, 0, 255), Qt::Dense4Pattern);如果是单单画一个直线之类的是不需要用画刷的。
   QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190));
   //插入颜色
   linearGradient.setColorAt(0, Qt::yellow);
   linearGradient.setColorAt(0.5, Qt::red);
   linearGradient.setColorAt(1, Qt::green);
   //指定渐变区域以外的区域的扩散方式
   linearGradient.setSpread(QGradient::RepeatSpread);
   //使用渐变作为画刷
    painter.setPen(QPen(linearGradient,2));
   // painter.drawLine(QPoint(0,0),QPoint(0,100));
    for(int i=0;i<10;i++)
        painter.drawLine(QPoint(100*i,0),QPoint(100*i,600));
    for(int i=0;i<10;i++)
        painter.drawLine(QPoint(0,i*100),QPoint(900,i*100));
}
