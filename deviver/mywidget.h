#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QPaintDevice>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include <QTimer>

#define lineNum 60

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = nullptr);
    ~myWidget();
private:
    Ui::myWidget *ui;

    QPainter *myPainter = nullptr;
    QTimer *myTimer = nullptr;

    bool flag = false;
    bool flag_finish = false;
    double V = 12.0;
    void scan();
    int x;
    int y;
    double angle;

    QPainter myPainerLine[lineNum];
    QPen myPenLine[lineNum];
    QLineF myLine[lineNum];
    int flag_status = 1;
    double timer = 0.2;
    QColor startColor = Qt::green;
    int currentAlpha = 255;


protected:
    void paintEvent(QPaintEvent *);




};

#endif // MYWIDGET_H
