#include "widget.h"
#include "ui_widget.h"
#include<QHBoxLayout>
#include<QGridLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
   /* // 新建水平布局管理器
    QHBoxLayout *layout = new QHBoxLayout;

    // 向布局管理器中添加部件
    layout->addWidget(ui->fontComboBox);
    layout->addWidget(ui->textEdit);

    // 设置部件间的间隔
    layout->setSpacing(50);

    // 设置布局管理器到边界的距离，四个参数顺序是左，上，右，下
    layout->setContentsMargins(0,0,50,100);

    // 将这个布局设置为MyWidget类的布局
    setLayout(layout);
    QGridLayout *layout = new QGridLayout;

    // 添加部件，从第0行0列开始，占据1行2列
    layout->addWidget(ui->fontComboBox,0,0,1,3);

    // 添加部件，从第0行2列开始，占据1行1列
    layout->addWidget(ui->pushButton,0,3,1,1);

    // 添加部件，从第1行0列开始，占据1行3列
    layout->addWidget(ui->textEdit,1,0,1,4);

    setLayout(layout);*/
}

Widget::~Widget()
{
    delete ui;
}
