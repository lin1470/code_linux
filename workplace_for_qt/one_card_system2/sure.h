#ifndef SURE_H
#define SURE_H

#include <QDialog>

namespace Ui {
class sure;
}

class Sure : public QDialog
{
    Q_OBJECT

public:
    explicit Sure(QWidget *parent = 0);
    ~Sure();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sure *ui;
};

#endif // SURE_H
