#include "widget.h"
#include <QApplication>
#include"dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Dialog dialog;
    if(dialog.exec()==QDialog::Accepted)
    {
        w.move(350,50);
        w.show();
        return a.exec();
    }

}
