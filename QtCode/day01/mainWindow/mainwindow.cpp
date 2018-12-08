#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //获取原来的菜单
    QMenuBar *menu = menuBar();
    //在菜单中添加文件的菜单
    QMenu *pFile = menu -> addMenu("文件");
    QAction *pNew = pFile->addAction("新建");
    // 添加一条分割线.
    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("打开");
    connect(pNew,&QAction::triggered,
            []()
             {
                qDebug() << "新建被按下了!";
             }
    );
    connect(pOpen,&QAction::triggered,
            []()
             {
                qDebug() << "新建被按下了!";
             }
    );
    // 创建一个工具栏
    QToolBar *toolBar = addToolBar("toolBar");
    //往工具栏添加动作
    toolBar -> addAction(pNew);
    QPushButton *b1 = new QPushButton(this);
    b1->setText("- -");
    // 添加控件
    toolBar->addWidget(b1);
    connect(b1,&QPushButton::clicked,
            [=]()
    {
        b1->setText("hello b1");
    });
    // 状态栏的添加
    QStatusBar *sBar = statusBar();
    sBar->addWidget(new QLabel("label",this));
    sBar->addPermanentWidget(new QLabel("right",this));
    // 核心控件
    setCentralWidget(new QTextEdit(this));

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    dock->setWidget(new QTextEdit(this));

}



MainWindow::~MainWindow()
{

}
