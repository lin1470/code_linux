#include "mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *dia = mBar->addMenu("对话框");
    QAction *sdia = dia->addAction("静态对话框");
    QAction *fdia = dia->addAction("非静态对话框");
    QAction *about = dia->addAction("关于对话框");
    connect(sdia,&QAction::triggered,
            [=]()
    {
        QDialog dlg(this);
        dlg.exec();
    });
    connect(fdia,&QAction::triggered,
            [=]()
    {
        QDialog *p = new QDialog(this);
        p->setAttribute(Qt::WA_DeleteOnClose);
        p->show();
    });

    connect(about,&QAction::triggered,
            [=]()
    {

    });
    QAction *d4 = dia->addAction("问题对话框");
    connect(d4,&QAction::triggered,
            [=]()
    {
        int ret = QMessageBox::question(this,"question","Are you ok?");
        switch(ret)
        {
            case QMessageBox::Ok:
            qDebug() << "i am ok";
            break;
        case QMessageBox::No:
            qDebug() << "i am bad";
            break;
        default:
            break;
        }
    });
     QAction *d5 = dia->addAction("文件对话框");
     connect(d5,&QAction::triggered,
             [=]()
     {
         QString path = QFileDialog::getOpenFileName(
                     this,
                     "Open File",
                     "/home",
                     "source(*cpp *h;;Text(*.txt);;all(*.*)");
         qDebug()  << path;

     }
    );

}

MainWindow::~MainWindow()
{

}
