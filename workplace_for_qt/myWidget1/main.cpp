#include "widget.h"
#include <QApplication>
#include"dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    Dialog dialog;
    /*if(dialog.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();   //if the butto of enter main program is buttoned, the enter main..
    }
    else return 0;  //else it will quit the whole haaha.

*/
   // dialog.exec();



    return a.exec();
}
