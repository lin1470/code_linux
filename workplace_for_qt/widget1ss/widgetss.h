#ifndef WIDGETSS_H
#define WIDGETSS_H

#include <QWidget>

namespace Ui {
class Widgetss;
}

class Widgetss : public QWidget
{
    Q_OBJECT

public:
    explicit Widgetss(QWidget *parent = 0);
    ~Widgetss();

private slots:
    void on_display_dialog_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widgetss *ui;
};

#endif // WIDGETSS_H
