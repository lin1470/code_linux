#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //这个也是一个widget,窗口.
    Widget w;
    //窗口默认是隐藏的,只能人为的显示
    w.show();
    // 程序一直执行,里面是一个循环不断运行
    a.exec();
    return 0;
}
