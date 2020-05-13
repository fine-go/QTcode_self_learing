#ifndef FADEWIDGET_H
#define FADEWIDGET_H

#include <QWidget>

class QColor;
class QTimer;

class FaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FaderWidget(QWidget *parent = nullptr);

    void start();

protected:
    void paintEvent(QPaintEvent *event);

private:

    QColor startColor;
    int currentAlpha;
    int fadeTimes;
    QTimer *timer;
};

#endif  // FADER_H
