#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSqlDatabase>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印支持的数据库的驱动
    qDebug()<< QSqlDatabase::drivers();


}

Widget::~Widget()
{
    delete ui;
}

