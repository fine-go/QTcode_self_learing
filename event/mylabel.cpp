#include "mylabel.h"
#include <QLabel>
#include <QMouseEvent>


MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}
void MyLabel:: enterEvent(QEvent *event)
{
    QString text = QString("<center><h1>Mouse enter</h1></center>");

    this->setText(text);
}

void MyLabel:: leaveEvent(QEvent *event)
{
    QString text = QString("<center><h1>Mouse leave</h1></center>");

    this->setText(text);
}


//鼠标按下的时候发生改变
void MyLabel::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    
    QString text = QString("<center><h1>Mouse Press: (%1, %2)</h1></center>").arg(x).arg(y);

    //this->setText(text);

}

//鼠标移动的时候发生改变
void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    QString text = QString("<center><h1>Mouse Move: (%1, %2)</h1></center>").arg(x).arg(y);

    //this->setText(text);
}

//鼠标释放的时候发生改变
void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    QString text = QString("<center><h1>Mouse Release: (%1, %2)</h1></center>").arg(x).arg(y);

    //this->setText(text);
}
