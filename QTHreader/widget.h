#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void dealSignal();
    void dealclose();

private slots:
    void on_pushButtonstrat_clicked();
    void on_pushButtonstop_clicked();

private: signals:
    void startThread(); //启动子线程的信号


private:
    Ui::Widget *ui;
    mythread *myt;
    QThread *thread;
};
#endif // WIDGET_H
