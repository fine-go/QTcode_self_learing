#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    mytimer = new QTimer(this);

    connect(mytimer, &QTimer::timeout,

            [=]()
            {
                static int i = 0;
                i++;
                ui->lcdNumber->display(i);
            }
            );

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if (mytimer->isActive() == false)
        mytimer->start(100);
}

void Widget::on_close_clicked()
{
    if(true == mytimer->isActive())
        mytimer->stop();
}
