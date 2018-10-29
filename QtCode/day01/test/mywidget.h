#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT //信号与槽的时候需要使用.

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // MYWIDGET_H
