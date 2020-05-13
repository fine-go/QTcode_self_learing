#include "widget.h"
#include <QtGui>

FaderWidget::FaderWidget(QWidget *parent)
        : QWidget(parent)
{

    startColor = Qt::green;

    currentAlpha = 255;
    fadeTimes = 10000;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(update()));


    setAttribute(Qt::WA_DeleteOnClose);
    timer->start(1000);
}




void FaderWidget::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    QColor currentColor = startColor;
    currentColor.setAlpha(currentAlpha);
    painter.fillRect(rect(), currentColor);

    currentAlpha -= 255 * timer->interval() / fadeTimes;
    if (currentAlpha <= 0)
    {
        timer->stop();
        close();
    }
}
