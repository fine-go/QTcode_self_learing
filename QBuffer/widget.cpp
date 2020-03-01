#include "widget.h"
#include <QFile>
#include <QBuffer>
#include <QDebug>
#include <QDataStream>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QBuffer memerry;
    memerry.open(QIODevice::WriteOnly);
    memerry.write("11111");
    memerry.close();
    qDebug() << memerry.buffer();

    QByteArray array;
    QBuffer memerry1(&array);
    memerry1.open(QIODevice::WriteOnly);
    memerry1.write("主要靠气质");
    memerry1.close();
    qDebug() << QString(array);



    QBuffer memerry2;
    memerry2.open(QIODevice::WriteOnly);
    QDataStream stream;
    stream.setDevice(&memerry2);
    stream << QString("主要看气质") << 250;
    memerry2.close();
    qDebug() << memerry2.buffer();

    memerry2.open(QIODevice::ReadOnly);
    QDataStream out;
    out.setDevice(&memerry2);
    QString str;
    int a;
    out >> str >> a;
    memerry2.close();
    qDebug()<< str.toUtf8().data()<<a;

}

Widget::~Widget()
{
}

