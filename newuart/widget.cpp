#include "widget.h"
#include "ui_widget.h"
#include <QLayout>

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_serialPort = new QSerialPort();

    initUI();

    m_portNameList = getPortNameList();

    m_PortNameComboBox->addItems(m_portNameList);

    connect(m_OpenPortButton,&QPushButton::clicked,this,&Widget::openPort);

}

Widget::~Widget()
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
    }
    delete m_serialPort;

    delete ui;
}

void Widget::initUI()
{
    this->setWindowTitle("码农小明 test QSerialPort");


    m_OpenPortButton = new QPushButton();
    m_OpenPortButton->setText("打开串口");

    m_PortNameComboBox  = new QComboBox();

    QHBoxLayout *m_layout = new QHBoxLayout();

    m_layout->addWidget(m_PortNameComboBox);
    m_layout->addWidget(m_OpenPortButton);

    this->setLayout(m_layout);
}

QStringList Widget::getPortNameList()
{
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        qDebug()<<"serialPortName:"<<info.portName();
    }
    return m_serialPortName;
}

void Widget::openPort()
{
    if(m_serialPort->isOpen())//如果串口已经打开了 先给他关闭了
    {
        m_serialPort->clear();
        m_serialPort->close();
    }


    m_serialPort->setPortName(m_PortNameComboBox->currentText());//当前选择的串口名字

    if(!m_serialPort->open(QIODevice::ReadWrite))//用ReadWrite 的模式尝试打开串口
    {
        qDebug()<<"打开失败!";
        return;
    }
    qDebug()<<"串口打开成功!";

    m_serialPort->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);//设置波特率和读写方向
    m_serialPort->setDataBits(QSerialPort::Data8);      //数据位为8位
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
    m_serialPort->setParity(QSerialPort::NoParity); //无校验位
    m_serialPort->setStopBits(QSerialPort::OneStop); //一位停止位

    connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(receiveInfo()));
}

//接收到单片机发送的数据进行解析
void Widget::receiveInfo()
{
    qDebug() << "dakai";
    QByteArray info = m_serialPort->readAll();

    qDebug()<<"receive info:"<<info;

}

