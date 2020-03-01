#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_mywidget=new MyWidget;
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(btnClicked()));
    connect(m_mywidget,SIGNAL(sendData(MyData)),this,SLOT(receiverData(MyData)),Qt::QueuedConnection);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::btnClicked()
{
    m_mywidget->show();
}

void Widget::receiverData(MyData var)
{
    ui->lineEdit->setText(var.str);
}
