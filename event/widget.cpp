#include "widget.h"
#include "ui_widget.h"
#include  <QDebug>
#include "myb.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    time_Id_1 = this->startTimer(1000);
    time_Id_2 = this->startTimer(500);

    connect(ui->pushButton, &myb::clicked,

            [=]()
            {
                qDebug()<<"按钮被按下";
            });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == time_Id_1){
    static int sta;
    ui->time_1->setText( QString("<center><h1>Time Out: %1</h1></center>").arg(sta++));
    if (sta == 5)
        this->killTimer(time_Id_1);
    }

    else if(e->timerId() == time_Id_2)
    {
        static int sta_2;
        ui->label_2->setText( QString("<center><h1>Time Out: %1</h1></center>").arg(sta_2++));
        if (sta_2 == 10)
            this->killTimer(time_Id_2);
    }


}
