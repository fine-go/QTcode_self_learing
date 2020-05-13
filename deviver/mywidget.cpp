#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include "QtCore/qmath.h"


# define pi 360
static int t=1;
myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    myPainter = new QPainter(this);
    this->setWindowTitle("雷达站");
    resize(400, 400);
    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout, this, &myWidget::scan);
    myTimer->start(int(timer*1000));
}

myWidget::~myWidget()
{

    delete ui;
}

void myWidget::paintEvent(QPaintEvent *)
{
    //第一次绘图，画出背景表格和显示出角度等信息
    // 将背景设为黑色
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::black);
    this->setPalette(palette);
    myPainter->begin(this);
    //定义画笔
    QPen myPen;
    myPen.setWidth(5);
    myPen.setColor(Qt::green);
    myPainter->setPen(myPen);
    //设置圆心坐标
    int w = this->width();
    int h = this->height();
    x = w/2;
    y = int(h*0.9);
    qDebug() <<QString("x = %1").arg(x);
    qDebug() <<QString("y = %1").arg(y);
    //画圆
    int startAngle = 0 * 16;
    int spanAngle = 180 * 16;
    int R_max = 0;
    for(int i = 1;i<5;i++)
    {
        int R = y/4*i;
        //qDebug() <<QString("R = %1").arg(R);
        QRectF rectangle(x-R, y-R, 2*R,2*R );
        myPainter->drawArc(rectangle, startAngle, spanAngle);
        myPainter->setFont(QFont("myFont",18 ));
        QString s = QString::number(10*i, 10);
        qDebug() << s;
        myPainter->drawText(x+R-8, y+25,QString(s));
        myPainter->drawText(x-R+8, y+25,QString(s));
        if(i == 3)
            R_max = R;
    }
    //画射线，每30度分
    for(int i = 0;i<7;i++)
    {
        QLineF myLine;
        myLine.setP1(QPoint(x, y));
        myLine.setAngle(30*i);
        myPainter->drawLine(myLine);
    }
    for(int i = 0;i<7;i++)
    {
        QString s = QString::number(30*i, 10);
       // qDebug() << s;
        QPointF o(x+((R_max*1.05)*qCos(qDegreesToRadians(30.0*i-2))) , y-((R_max*1.05)*qSin(qDegreesToRadians(30.0*i-2))));
       // qDebug() << o;
        myPainter->drawText(o,s);
    }
    myPainter->end();
    //表示已经把背景画完
    flag_finish = true;

    currentAlpha = 255;
    for(int i=0;i<lineNum;i++)
    {
      QColor currentColor = startColor;
      currentColor.setAlpha(currentAlpha);

      currentAlpha -= int(255/lineNum) ;
      //i = 0时表示的是最前面的线
      myPainerLine[i].begin(this);
      myPenLine[i].setWidth(5);
      myPenLine[i].setColor(currentColor);
      myPainerLine[i].setPen(myPenLine[i]);
      myLine[i].setP1(QPoint(x,y));
      angle = V*timer*t - 0.4*i*flag_status;
      myLine[i].setAngle(angle);
      myPainerLine[i].drawLine(myLine[i]);
      myPainerLine[i].end();
    }

}

void myWidget::scan()
{
    if(flag_finish)
    {
        static bool num = false;//false 表示0--180 true表示180--0
        if(angle >180 or angle <0)
        {
            if(angle > 180)
            {
                num = true;
                flag_status = -1;
            }
            if(angle < 0)
            {
                num = false;
                flag_status = 1;
            }
        }
        if(!num){
            t++;
        }
        else {
            t--;
        }
    }
   qDebug() <<QString("t = %1").arg(t);
    update();
}
