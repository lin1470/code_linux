#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);

signals:
    void mySignal();
    void mySignal(int,QString);
public slots:
    void sendSignal();
private:
    QPushButton b;
};

#endif // SUBWIDGET_H
