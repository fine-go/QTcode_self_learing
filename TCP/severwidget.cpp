#include "severwidget.h"
#include "ui_severwidget.h"
#include <QDateTime>

SeverWidget::SeverWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SeverWidget)
{
    ui->setupUi(this);

    setWindowTitle("服务器8888");

    tcpServer = nullptr;
    tcpSocket = nullptr;

    //监听套接字,指定福对想，自动回收空间
    tcpServer = new QTcpServer(this);

    //bind 和 listen,
    tcpServer->listen(QHostAddress::Any, 8888);

    //产生连接后tcpServer产生newconnection信号
    //在槽函数中得到监听套接字
    connect(tcpServer, &QTcpServer::newConnection,

            [=]()
            {
                //在槽函数中得到监听套接字
                tcpSocket = tcpServer->nextPendingConnection();

                //huoqu对方的ip和端口
                QString ip = tcpSocket->peerAddress().toString();
                quint16 port = tcpSocket->peerPort();

                QString time = gettime();
                QString temp = QString(time+"->(%1, %2)：成功连接").arg(ip).arg(port);
                ui->textEditread->setText(temp);

                connect(tcpSocket, &QTcpSocket::readyRead,
                        [=]()
                        {
                           QByteArray bit =  tcpSocket->readAll();
                           QString temp = QString(bit);
                           ui->textEditread->append("收到: "+gettime()+temp);
                            }
                        );

              }
         );
    resize(500, 300);
}

SeverWidget::~SeverWidget()
{
    delete ui;
}

QString SeverWidget::gettime()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("hh:mm::ss.zzz    ");

    return current_date;

}
void SeverWidget::on_pushButtonsend_clicked()
{
    if (tcpSocket == nullptr)
    {
        return ;
    }

    //获取编辑区内容
    QString str = ui->textEditWrite->toPlainText();

    QString temp = QString(gettime()+str);
    //QString -> char *
    tcpSocket->write(temp.toUtf8().data());
    ui->textEditread->append("发送: " + temp);
}

void SeverWidget::on_pushButtonclose_clicked()
{
    if (tcpSocket == nullptr)
    {
        return ;
    }
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    ui->textEditread->append("已断开连接");
    tcpSocket = nullptr;
}
