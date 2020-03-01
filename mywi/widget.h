#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mywidget.h"

class MyWidget;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void btnClicked();
    void receiverData(MyData var);

private:
    Ui::Widget *ui;

    MyWidget *m_mywidget;
};

#endif // WIDGET_H
