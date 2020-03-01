#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class mythread : public QObject
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr);

    //线程处理函数
    void mytimeout();
    void setisStop( bool flag = true);

public: signals:
    void  mySignal();

public slots:
protected:
    bool isStop;

};

#endif // MYTHREAD_H
