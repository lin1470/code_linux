#include "widgetss.h"
#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widgetss w;
    Dialog dialog;
    if(dialog.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();

    }
    else return 0;

    //return a.exec();
}
