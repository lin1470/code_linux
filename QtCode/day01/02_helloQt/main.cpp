#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc,argv);

    QWidget w;
    //w.show();
    w.setWindowTitle(QString("主要看气质神经病"));
//    w.show();
    QPushButton b;
    b.setText("按钮");
    //b.show();
    /*
     * 如果不指定父对象,对象和对象(窗口和窗口)是没有关系的
     * a指定b为它的父对象,a放在b的上面
     * 指定父对象,有两种方式:
     * 1.setParent
     * 2.通过构造函数传参
     * 指定父对象,只需要显示父对象,子对象会自动显示.
     */
     b.setParent(&w);
     b.move(100,100);


     QPushButton b1(&w);
     b1.setText("hhh");
      w.show();
     app.exec();
     return 0;
}
