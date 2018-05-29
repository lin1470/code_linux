
#include<QtGui>

int main(int argc,char *argv[])
{
    QApplication a(argc,argv);
    //在代码中可以使用中文的字符串
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QWidget *widget=new QWidget(0,Qt::Dialog|Qt::FramelessWindowHint);//新建一个类对象，默认parent参数是零，所以它是一个窗口
    //设置窗口标题
    widget ->setWindowTitle(QObject::tr("我是widget"));
    //新建QLABEL对象，默认参数是零，所以还是窗口。
    QLabel *label =new QLabel(0,Qt::SplashScreen|Qt::WindowStaysOnTopHint);
    label ->setWindowTitle(QObject::tr("我是label"));
    label ->setText(QObject::tr("我是一个窗口"));
    label ->resize(180,200);
    QLabel *label2 =new QLabel(widget);
    label2 ->setText(QObject::tr("label:我不是一个独立的窗口，只是widget的一个部件"));
    label2 ->resize(250,20);
    label ->setWindowState(Qt::WindowFullScreen);
    label ->show();
    widget ->show();
    int ret=a.exec();
    delete label;
    delete widget;
    return ret;
}
