#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //董涛分配空间，不能指定福对象
    //通过信号与草的方式实现线程的启动
    //没有指定福对象在关闭的时候注意内存泄漏
    myt = new mythread();

    //创建子线程
    thread = new QThread(this);

    //吧自定义得线程加入子线程总
    myt->moveToThread(thread);

    //处理子线程的信号
    connect(myt, &mythread::mySignal, this, &Widget::dealSignal);

    //处理产生的开始信号
    connect(this, &Widget::startThread, myt, &mythread::mytimeout);

    //打印现在的线程号， 即为父线程号
    qDebug() << "Fathear Thread"<< QThread::currentThreadId();

    //当线程还在运行但是关闭窗口的时候不会关闭子进程
    connect(this, &QWidget::destroyed, this, &Widget::dealclose);

    //connect 第五个参数的作用， 只有在多线程的时候才有意义
    //connect有三个方式 ，自动，直接，队列
    //默认的时候
    // 如果是多线程， 是使用队列
    // 如果是单线程， 是使用直接的方式
    //队列的方式 ： 槽函数所在线程和接受者一样
    //直接的方式 ： 槽函数所在线程和发送者一样


}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealclose()
{
    on_pushButtonstop_clicked();
    delete myt;
}

void Widget::on_pushButtonstrat_clicked()
{

    //判断线程是否在运行
    if(thread->isRunning() == true)
    {
        return;
    }

    //启动线程，但是没有启动线程处理函数
    myt->setisStop(false);
    thread->start();

    //不能直接调用线程处理函数，
    //否则线程处理函数还是处理当前线程下工作
    //智能通过信号和草的方式来调用
    emit startThread();
}

void Widget::dealSignal()
{
    //用于处理子线程产生的mysignal信号观察子线程是否启动
    static int i = 0;
    i++;

    ui->lcdNumber->display(i);
}

void Widget::on_pushButtonstop_clicked()
{
    //判断线程是否在运行
    if(thread->isRunning() == false)
    {
        return;
    }
    //仅仅用这两个不能关闭线程
    //quit()函数会等待线程处理函数运行完之后在退出
    //不能解决死循环问题
    //wait是用于资源回收
    //不能强制退出会导致内存问题
    myt->setisStop(true);
    thread->quit();
    thread->wait();
}
