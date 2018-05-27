#include "dialog.h"
#include <QApplication>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    cout<<"厉害了我的哥啊"<<endl;

    return a.exec();
}
