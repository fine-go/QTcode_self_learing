#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //分配空间指定父对象
     udpSocket = new QUdpSocket(this);

     //绑定
     udpSocket->bind(8888);

     setWindowTitle("8888");

     //当对方发送消息是触发readyread信号

     connect(udpSocket, &QUdpSocket::readyRead, this, &Widget::dealData);
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::gettime()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("hh:mm::ss.zzz");

    return current_date;
}

void Widget::dealData()
{
    char str[1024] = {0};
    QHostAddress cliaddr; // 对方端口
    quint16 port; //对方地址
    qint64 len = udpSocket->readDatagram(str, sizeof(str), &cliaddr, &port );

    if(len > 0)
    {
        //格式化显示内容
        QString text = QString(gettime()+" -> 收到: [%1, %2] %3").arg(cliaddr.toString()).arg(port).arg(str);
        ui->textEditRead->append(text);
    }

}

void Widget::on_pushButtonsend_clicked()
{
    //获取对方的ip和端口
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toInt();


    //判断是不是空

    if (ip != nullptr && port !=0)
    {
        //获取编辑区的内容

        QString send_date = ui->textEditWrite->toPlainText();

        //给指定的ip发送数据

        udpSocket->writeDatagram(send_date.toUtf8(), QHostAddress(ip), port);

        //在窗口上显示

        QString temp = QString( gettime()+" -> 发送: "+send_date);
        ui->textEditRead->append(temp);

    }

}

void Widget::on_pushButtonclose_clicked()
{
    if (udpSocket == nullptr)
    {
        return;
    }

    udpSocket->close();
}
