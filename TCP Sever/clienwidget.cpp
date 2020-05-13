#include "clienwidget.h"
#include "ui_clienwidget.h"
#include <QDateTime>

ClienWidget::ClienWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClienWidget)
{
    ui->setupUi(this);
    tcpSocket = nullptr;

    setWindowTitle("客户端");
    //分配空间指定福对象
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::connected,
            [=]()

            {
              QString temp = gettime();
              ui->textEditRead->setText(temp+"成功和服务器连接");
            }
           );

    connect(tcpSocket, &QTcpSocket::readyRead,
            [=]()
            {
                QString array =QString (tcpSocket->readAll());
                QString temp = QString("收到: "+ gettime()+"->"+array);

                tcpSocket->write(temp.toUtf8().data());
                ui->textEditRead->append(temp);
            }
            );

    resize(500, 300);

}

ClienWidget::~ClienWidget()
{
    delete ui;
}

void ClienWidget::on_pushButtonConnect_clicked()
{
    //获取ip和port
    QString ip = ui->lineEditIP->text();

    quint16 port = ui->lineEditPort->text().toInt();

    //主动服务器连接
    tcpSocket->connectToHost(ip, port);

}

void ClienWidget::on_pushButtonsend_clicked()
{
    if(tcpSocket == nullptr)
    {
        return;
    }

    //获取编辑框内容
    QString send_data = ui->textEditWrite->toPlainText();
    send_data = gettime() + send_data;
    tcpSocket->write(send_data.toUtf8().data());
    ui->textEditRead->append("发送 ："+send_data);
}

QString ClienWidget::gettime()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("hh:mm::ss.zzz    ");

    return current_date;

}

void ClienWidget::on_pushButtonclose_clicked()
{
    if (tcpSocket == nullptr)
    {
        return;
    }

    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
