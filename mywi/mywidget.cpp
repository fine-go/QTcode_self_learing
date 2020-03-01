#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(textChanged(QString)));

    qRegisterMetaType<MyData>();
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::textChanged(QString str)
{
    MyData myData;
    myData.str=str;
    sendData(myData);
}
