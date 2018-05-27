#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}
//定义了一个命名的空间。
class Widget : public QWidget//实际是选择了继承的是什么样的父类，即是说可以直接继承的有widget
        //dialog，还有mainconsole主控制台，哈哈。
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);//这个是避免隐式调用这样的构造函数来的，可以说有点弱。
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);//事件。

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
