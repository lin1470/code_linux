#include "sure.h"
#include "ui_sure.h"

Sure::Sure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sure)
{
    ui->setupUi(this);
}

Sure::~Sure()
{
    delete ui;
}

