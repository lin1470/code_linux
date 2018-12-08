#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QCompleter>
#include <QStringList>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->lineEdit->setEchoMode(QLineEdit::Password);
    QString str = ui->lineEdit->text();
    qDebug() << str;
    QStringList list;
    list << "hello" << "waorld" << "How are you";
    QCompleter *com = new QCompleter(list,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);

    ui->labelEdit->setText("- -");
    //设置图片
    ui->labelImage->setPixmap(QPixmap(":/image/butterfly1.png"));
    ui->labelEdit->setScaledContents(true);
    //创建动画
    QMovie *myMovie = new QMovie(":/image/mario.gif");
    //设置动画
    ui->labelgif->setMovie(myMovie);
    ui->labelgif->setScaledContents(true);
    myMovie->start();

    //设置html
    ui->labelUrl->setText("<h1><a href =\"https:www.baidu.com\">"
                          "百度一下</a></h1>");
    ui->labelUrl->setOpenExternalLinks(true);

    //数码管
    ui->lcdNumber->display(123);
    //进度条
    ui->progressBar->setMaximum(200);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(100);
    /*最小值, 最大值和当前值*/


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static int i =0;
    ui->stackedWidget->setCurrentIndex(++i %5);
}
