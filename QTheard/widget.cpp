#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mytimer = new QTimer(this);

    //创建线程对象，分配空间，指定对象
    mythread = new Mythread(this);
    connect(mytimer, &QTimer::timeout, this, &Widget::timeOut);

    connect(mythread, &Mythread::isDone, this, &Widget::dealDone);

    connect(this, &Widget::destroyed, this, &Widget::stopThread);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::dealDone()
{
    qDebug() << "is over";
    mytimer->stop();
}
void Widget::timeOut()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void Widget::stopThread()
{
    //停止线程
    mythread->quit();
    //等待线程完成工作后关闭
    mythread->quit();
}

void Widget::on_pushButton_clicked()
{
    //如果定时器没有工作
    if(mytimer->isActive() == false)
    {
        mytimer->start(100);
    }

    //模拟负载较大的情况下的数据多线程处理
    mythread->start();
}
