#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(900,600);
    w.move(50,50);
    w.show();


    return a.exec();
}
