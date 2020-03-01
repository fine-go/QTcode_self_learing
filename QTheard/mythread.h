#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>


class Mythread : public QThread
{
    Q_OBJECT
public:
    explicit Mythread(QObject *parent = nullptr);

signals:
    void isDone();

public slots:

protected:
    //QThread 线程处理函数， 虚函数， 不能直接调用，通过start间接调用
    void run() override;
};

#endif // MYTHREAD_H
