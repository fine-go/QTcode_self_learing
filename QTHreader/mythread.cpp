#include "mythread.h"
#include <QThread>
#include <QDebug>

mythread::mythread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

void mythread::mytimeout()
{

    while(isStop == false)
    {
        QThread::sleep(1);
        emit mySignal();
        qDebug() << QThread::currentThreadId();
    }
}

void mythread::setisStop(bool flag)
{
    isStop = flag;
}
