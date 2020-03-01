#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //QPainter p(this);

    //创建绘图对象
    QPainter p;
    //指定当前窗口为绘图设备
    p.begin(this);

    //绘图操作
    //画背景图
    //p.drawPixmap(0, 0, width(), height(), QPixmap("../Image/line.jpg"));
    //p.drawPixmap(rect(),QPixmap("../Image/line.jpg") );

    //创建一个画笔
    QPen pen;
    //设置线宽
    pen.setWidth(5);
    //pen.setColor(Qt::red);
    pen.setColor( QColor(255, 0, 0));
    //设置风格
    pen.setStyle(Qt::DashDotDotLine);

    QBrush brush;
    brush.setColor(Qt::blue);
   // brush.setStyle(Qt::LinearGradientPattern);
    //把画笔交给画家
    p.setPen(pen);


    //画一条直线
    p.drawLine(50,50, 150, 50);
    p.drawLine(50,50, 50, 150);
    p.setBrush(brush);
    //画矩形
    p.drawRect(150, 150, 50, 50);

    //画圆
    p.drawEllipse(QPoint(150, 150), 150, 50);
    p.drawEllipse(QPoint(250, 350), 150, 50);

    // 画一个图案
    p.drawPixmap(x, 200,150, 150, QPixmap("../Image/icecream.jpg"));
    //结束绘图
    p.end();
}

void Widget::on_pushButton_clicked()
{
    x += 20;

    if (x>this->width())
    {
        x=0;
    }

    update();
}
