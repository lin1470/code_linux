#include "hellodialog.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloDialog w;
    w.show();
    //cout<<"hhehehe"<<endl;
    return a.exec();
}
