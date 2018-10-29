#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);

signals:
    void mySignal();
public slots:
    void sendSignal();
private:
    QPushButton b;
};

#endif // SUBWIDGET_H
