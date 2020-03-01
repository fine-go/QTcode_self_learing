#include "mythread.h"

Mythread::Mythread(QObject *parent) : QThread(parent)
{

}


void Mythread::run()
{
    sleep(5);

    emit isDone();
}
