#include "mywidget.h"
#include "ui_mywidget.h"
#include <QTcpServer>
#include <QMessageBox>


myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);

    //创建监听套接字
    myTcpSever = new QTcpServer(this);

    //开始监听
    myTcpSever->listen(QHostAddress::Any, 8888);

    //设定标题
    this->setWindowTitle("服务器端口: 8888");
    resize(500, 400);
    move(900, 200);
    ui->progressBar->setValue(0);
    mytimer = new QTimer(this);
    head_flag = false;
    //如果有人连接成功触发newconnection信号
    connect(myTcpSever, &QTcpServer::newConnection,
            [=]()
            {
                //去除建立好链解的套接字
                myTcpSocket = myTcpSever->nextPendingConnection();

                //获取建立好连接的对方的Ip和port，并显示在界面上
                QString ip = myTcpSocket->peerAddress().toString();
                quint16  port =myTcpSocket->peerPort();
                QString temp = QString("连接成功 [%1, %2]").arg(ip).arg(port);
                ui->textEditread->append(temp);
                connect(myTcpSocket, &QTcpSocket::readyRead,
                        [=]()
                        {
                             //ui->textEditread->append("get the single of ");
                            //获取文件信息
                            QByteArray buf = myTcpSocket->readAll();

                            if (false == head_flag)
                            {
                                ui->textEditread->append("get the single of head");
                                head_flag = true;
                                //第一次读取头部信息
                                //解析头部信息
                                //初始化文件
                                //打开文件并写入
                                filename = QString(buf).section("**", 0, 0);
                                filesize = QString(buf).section("**", 1, 1).toInt();
                                QString temp = QString("接收文件 文件名称: %1, 文件大小: %2M").arg(filename).arg(filesize/(1024*1024));
                                //QMessageBox::information(this, "信息", temp,
                                //                                     QMessageBox::Yes|QMessageBox::No);

                                ui->textEditread->append("接收文件");
                                ui->textEditread->append("正在接收文件....");
                                recvsize = 0;

                                ui->progressBar->setMinimum(0);
                                ui->progressBar->setMaximum(filesize/1024);
                                ui->progressBar->setValue(0);

                                //打开文件
                                file = new QFile(filename);

                                bool isok = file->open(QIODevice::WriteOnly);
                                if(isok == false)
                                {
                                    qDebug() << "打开文件失败 40";
                                }

                            }


                            else// 读取信息写文件
                            {
                                ui->textEditread->append("get the single of data");
                                qint64 len = file->write(buf);

                                if(len > 0)
                                {
                                    recvsize += len;
                                    QString str = QString::number(recvsize);

                                    myTcpSocket->write(str.toUtf8().data());
                                }

                                ui->progressBar->setValue(recvsize/1024);

                                if(recvsize == filesize)
                                {

                                    mytimer->start(10);

                                }
                            }
                        }
                        );
            }
    );



    connect(mytimer, &QTimer::timeout,
            [=]()
            {
                mytimer->stop();
                file->close();

                myTcpSocket->write("file done");
                ui->textEditread->append("成功接收文件");

                QMessageBox::information(this, "完成", "文件节收完成");

                myTcpSocket->disconnectFromHost();
                myTcpSocket->close();
            }
            );


}

myWidget::~myWidget()
{
    delete ui;
}
