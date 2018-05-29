#include "widget.h"
#include <QApplication>
#include<QTextCodec>//中文标题必须包含的库文件


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));//只有使用这个的语句才能很好的显示这个中文的标题
    Widget w;
    w.show();

    return a.exec();
}
