#include "mybutton.h"
#include <QDebug>
myButton::myButton(QWidget *parent) : QPushButton(parent)
{

}

myButton::~myButton()
{
    qDebug() << "我的按钮被释放了";
}
