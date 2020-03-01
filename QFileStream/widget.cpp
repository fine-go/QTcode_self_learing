
#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QFile>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ <<":" << __LINE__<<"]"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeDate();
    readDate();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readDate()
{
    QFile file("../text.txt");

    bool isok = file.open(QIODevice::ReadOnly);
    if(isok == true)
    {
        QDataStream stream(&file);
        QString str;
        int a;
        stream >>str>>a;
        //qDebug() << str.toUtf8().data() << a;
        cout << str<< a;

        file.close();
    }

}

void Widget::writeDate()
{
    QFile file("../text.txt");

    bool isok = file.open(QIODevice::WriteOnly);
    if(isok == true)
    {
        //关联文件和文件流
        //写入文件就是向文件流里面输入数据
        QDataStream stream(&file);

        stream<<QString(" 主要靠气质") << 132;

        file.close();

    }
}
