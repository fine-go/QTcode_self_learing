#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

struct MyData{
    QString str;
};

Q_DECLARE_METATYPE(MyData)

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

signals:
    void sendData(MyData myWidget);

public slots:
    void textChanged(QString str);

private:
    Ui::MyWidget *ui;
    QString m_str;
};


#endif // MYWIDGET_H
