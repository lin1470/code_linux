#include "widget.h"
#include "ui_widget.h"
#include<QPainter>//注意这个是一定得要包含在里面的

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
    painter.drawLine(QPoint(0,0),QPoint(100,100));
   // painter.drawArc(rectangle, startAngle, spanAngle);
    QPen pen(Qt::red,5,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(pen);//五个参数对应的分别是：画刷，线宽，画笔风格，画笔端点风格，画笔链接风格
    QRectF rectangle(70.0,40.0,80.0,60.0);//这个是指定绘制圆弧的矩形的左上角的坐标和长和宽来的
    int startAngle=30*16;//开始的角度
    int spanAngle=120*16;//旋转的角度
    painter.drawArc(rectangle,startAngle,spanAngle);
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawRect(160,20,50,40);
    QBrush brush(QColor(0,0,255),Qt::Dense4Pattern);
    painter.setBrush(brush);
    painter.drawEllipse(220,20,50,50);
    brush.setTexture(QPixmap("../myDrawing/yafeilinux.png"));//这个是设置那个图形填充的纹理的
    //重新使用画刷
    painter.setBrush(brush);
    //定义四个点
    static const QPointF points[4] = {
        QPointF(270.0, 80.0),
        QPointF(300.0, 10.0),
        QPointF(350.0, 30.0),
        QPointF(390.0, 70.0)
    };
    //使用四个点绘制多边形
    painter.drawPolygon(points, 4);

}
