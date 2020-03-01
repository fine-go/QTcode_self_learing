#include "widget.h"
#include "ui_widget.h"
#include <QTextEdit>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonSearch_clicked()
{
    //查找串口，显示在box里面
    //foreach 函数在C++标准中没有此关键字，此为QT的关键字
    //用法为foreach(变量，容器)，info里面存放了可用端口的信息
    ui->portName->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
       {
          ui->portName->addItem(info.portName());
       }
    //同时给串口对象分配空间
    myserial = new QSerialPort();

}

void Widget::on_pushButtonOpen_clicked()
{
    //打开串口
    //设置串口名
    myserial->setPortName(ui->portName->currentText());

    //设置波特率
    myserial->setBaudRate(ui->botelv->currentText().toInt());
    //设置校验位
    switch(ui->jiaoyanwei->currentIndex())
    {
        case 0:
        {
            myserial->setParity(QSerialPort::NoParity);
            break;
        }
    default:
        break;
    }
    //设置数据位
    switch (ui->databit->currentIndex())
    {
        case 0:
        {
            myserial->setDataBits(QSerialPort::Data8);
            break;
        }
    default:
        break;
    }
    //设置停止位
    switch(ui->stopbit->currentIndex())
    {
        case 0:
        {
            myserial->setStopBits(QSerialPort::OneStop);
            break;
        }
    default:
        break;
    }

    //设置流控制
    myserial->setFlowControl(QSerialPort::NoFlowControl);

    //设置串口名之后打开串口
    bool open_flag = myserial->open(QIODevice::ReadWrite);
    if(!open_flag)
    {
        ui->textEditRvcf->append("open fail");
    }
    else
    {
        myserial->setDataTerminalReady(true);
        //打开按钮和区域失效
        ui->portName->setEnabled(false);
        ui->botelv->setEnabled(false);
        ui->databit->setEnabled(false);
        ui->stopbit->setEnabled(false);
        ui->jiaoyanwei->setEnabled(false);

        ui->pushButtonOpen->setEnabled(false);
        ui->pushButtonSearch->setEnabled(false);

        connect(myserial, SIGNAL(readyRead()),this, SLOT(recive()));
      }

}

void Widget::on_pushButtonSend_clicked()
{
    //发送数据
    if(!myserial->isOpen())
        return;
    else
    {
        QByteArray temp = ui->textEditsend->toPlainText().toLatin1();
        qDebug() << temp;
        qint64 flag = myserial->write(temp);
        qDebug() << flag;
    }
}

void Widget::recive()
{
    //如何处理黏包问题
    qDebug() << "recive";
    //从接收缓冲区中读取数据
    QByteArray buffer = myserial->readAll();
    //从界面中读取以前收到的数据
   // QString recv = ui->textEditRvcf->toPlainText();
   // recv += QString(buffer);
   // //清空以前的显示
   // ui->textEditRvcf->clear();
    //重新显示
    ui->textEditRvcf->append(buffer);

}

void Widget::on_pushButtonClose_clicked()
{
    if(!myserial->isOpen())
        return;
    else
    {
        myserial->close();

        ui->portName->setEnabled(true);
        ui->botelv->setEnabled(true);
        ui->databit->setEnabled(true);
        ui->stopbit->setEnabled(true);
        ui->jiaoyanwei->setEnabled(true);

        ui->pushButtonOpen->setEnabled(true);
        ui->pushButtonSearch->setEnabled(true);
    }
}
