#include "serverwidget.h"
#include "ui_serverwidget.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QTimer>

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);


    //创建监听套接字
    TcpServer = new QTcpServer(this);

    //开始监听
    TcpServer->listen(QHostAddress::Any, 8888);

    //连接之前两个按钮都不能按
    ui->pushButtonFile->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);

    //设定标题
    this->setWindowTitle("服务器端口: 8888");
    resize(500, 400);
    move(900, 200);
    mytimer = new QTimer(this);
    ui->progressBar->setValue(0);


    //如果有人连接成功触发newconnection信号
    connect(TcpServer, &QTcpServer::newConnection,
            [=]()
            {
                //去除建立好链解的套接字
                TcpSocket = TcpServer->nextPendingConnection();

                //获取建立好连接的对方的Ip和port，并显示在界面上
                QString ip = TcpSocket->peerAddress().toString();
                quint16  port =TcpSocket->peerPort();
                QString temp = QString("连接成功 [%1, %2]").arg(ip).arg(port);
                ui->textEdit->append(temp);

                ui->pushButtonFile->setEnabled(true);

            }
        );

    connect(mytimer, &QTimer::timeout,
            [=]()
            {
                   mytimer->stop();
                   senddate();
            }
            );


}

ServerWidget::~ServerWidget()
{
    delete ui;
}

//选择文件时候穿件文件对象并且创建对话框
void ServerWidget::on_pushButtonFile_clicked()
{
    //先选择并创建文件对话框
    QString file_path = QFileDialog::getOpenFileName(this, "open", "../");

    if(file_path.isEmpty() == false)
    {
        //打开文件
        //读取文件信息， 文件名字和文件大小
        //只读方式打开文件

        filename.clear();
        filesize = 0;

        QFileInfo info(file_path);

        filename = info.fileName();
        filesize = info.size();

        //已经发送文件大小为 0
        sendsize = 0;

        //以只读方式打开文件
        file = new QFile(file_path);

        //判断是否争取打开
        bool isok = file->open(QIODevice::ReadOnly);
        if(isok == false)
        {
            qDebug() << "只读方式打开文件失败 80";

        }

        //显示文件信息
        QString  temp = QString("成功打开文件 【文件名称 %1， 文件大小 %2】");

        ui->pushButtonFile->setEnabled(false);
        ui->pushButtonSend->setEnabled(true);


    }
    else
    {
        qDebug() <<"选择文件出错  62";
    }



}

void ServerWidget::on_pushButtonSend_clicked()
{
    //发送文件信息
    QString Head = QString ("%1**%2").arg(filename).arg(filesize);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(filesize/1024);

    //发送文件头
    qint64 len = TcpSocket->write(Head.toUtf8());

    if (len > 0)
    {
        //为避免出现黏包问题用定时器调用senddate函数
        mytimer->start(20);

    }
    else{
        qDebug() << "头部信息发送失败";

        file->close();
        ui->pushButtonFile->setEnabled(true);
        ui->pushButtonSend->setEnabled(false);
    }
}


void ServerWidget::senddate()
{
    qint64 len = 0;
    do{
        char buf[1024 * 4] = {0};
        len = file->read(buf, sizeof(buf));
        //读多少发多少
        len = TcpSocket->write(buf, len);

        //发送的数据要累加
        sendsize += len;

    }while(len > 0);

    connect(TcpSocket, &QTcpSocket::readyRead,
                [=]()
                {
                    QByteArray buf = TcpSocket->readAll();
                    if(QString(buf) == "file done")
                    {
                        //文件接收完毕
                        ui->textEdit->append("完成接收");
                        file->close();
                        TcpSocket->disconnectFromHost();
                        TcpSocket->close();
                    }
                    else
                    {
                        qDebug() << buf;
                        qint64 size = buf.toInt();
                        qDebug() << size;
                        ui->progressBar->setValue(size/1024);
                    }
                }
        );

//    if (sendsize == filesize)
//    {
//        //文件发送完毕的操作
//        file->close();

//        //把客户端断开
//        TcpSocket->disconnectFromHost();
//        TcpSocket->close();

//        QString temp = QString ("文件成功发送，与客户端断开连接");
//        ui->textEdit->append(temp);
//    }
}


