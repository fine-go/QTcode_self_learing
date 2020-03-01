#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>

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


void Widget::on_pushButton_clicked()
{
    QFile file;
    file.setFileName("../data.txt");
    bool isOK = file.open(QIODevice::ReadOnly);
    if (true == isOK)
    {
        QTextStream stream(&file);

        //指定编码
        stream.setCodec();
        stream <<QString("主要看气质") << 250;

        file.close();
    }

}

void Widget::on_pushButton_2_clicked()
{

}
