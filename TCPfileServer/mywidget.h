#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class myWidget; }
QT_END_NAMESPACE

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();

private:
    Ui::myWidget *ui;

    QTcpServer *myTcpSever = nullptr;
    QTcpSocket *myTcpSocket = nullptr;

    QTimer *mytimer;

    qint64 recvsize = 0;
    qint64 filesize = 0;
    bool head_flag = false;

    QString filename;

    QFile *file;

};
#endif // MYWIDGET_H
