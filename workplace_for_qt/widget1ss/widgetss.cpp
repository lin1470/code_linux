#include "widgetss.h"
#include "ui_widgetss.h"
#include<QDialog>
#include "dialog.h"
#include"ui_dialog.h"

Widgetss::Widgetss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widgetss)
{
    ui->setupUi(this);
}

Widgetss::~Widgetss()
{
    delete ui;
}

void Widgetss::on_display_dialog_clicked()
{
    QDialog dialog;
    dialog.exec();
}

void Widgetss::on_pushButton_clicked()
{
    close();
   Dialog dlg;
   if(dlg.exec()==QDialog::Accepted)
       show();
}
