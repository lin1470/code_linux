#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mybutton.h"
class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
};

#endif // MYWIDGET_H
