#include "clienwidget.h"
#include "ui_clienwidget.h"
#include <QMessageBox>
#include <QProgressBar>
#include <QDebug>

ClienWidget::ClienWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClienWidget)
{
    ui->setupUi(this);

    //创建通讯套接字
    TcpSocket = new QTcpSocket(this);

    setWindowTitle("客户端");
    resize(500, 400);
    move(200, 200);

    head_flag = false;

    //初始化进度条
    ui->progressBar->setValue(0);
    mytimer = new QTimer(this);

    connect(TcpSocket, &QTcpSocket::readyRead,
            [=]()
            {
                //获取文件信息
                QByteArray buf = TcpSocket->readAll();

                if (false == head_flag)
                {
                    head_flag = true;
                    //第一次读取头部信息
                    //解析头部信息
                    //初始化文件
                    //打开文件并写入
                    filename = QString(buf).section("**", 0, 0);
                    filesize = QString(buf).section("**", 1, 1).toInt();
                    QString temp = QString("接收文件 文件名称: %1, 文件大小: %2M").arg(filename).arg(filesize/(1024*1024));
//                    QMessageBox::information(this, "信息", temp,
//                                                         QMessageBox::Yes|QMessageBox::No);

                    ui->textEdit->append("接收文件");
                    ui->textEdit->append("正在接收文件....");
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

                    qint64 len = file->write(buf);

                    if(len > 0)
                    {
                        recvsize += len;
                        QString str = QString::number(recvsize);

                        TcpSocket->write(str.toUtf8().data());
                    }

                    ui->progressBar->setValue(recvsize/1024);

                    if(recvsize == filesize)
                    {

                        mytimer->start(10);

                    }
                }
            }
            );

    connect(mytimer, &QTimer::timeout,
            [=]()
            {
                mytimer->stop();
                file->close();

                TcpSocket->write("file done");
                ui->textEdit->append("成功接收文件");

                QMessageBox::information(this, "完成", "文件节收完成");

                TcpSocket->disconnectFromHost();
                TcpSocket->close();
            }
            );

}


ClienWidget::~ClienWidget()
{
    delete ui;
}

void ClienWidget::on_pushButtonConnect_clicked()
{
    QString ip = ui->lineEditIp->text();
    quint16  port = ui->lineEditPort->text().toInt();

    TcpSocket->connectToHost(ip, port);

}
