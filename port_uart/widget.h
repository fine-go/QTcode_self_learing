#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonOpen_clicked();
    
    void on_pushButtonSend_clicked();

    void recive();

    void on_pushButtonClose_clicked();

private:
    Ui::Widget *ui;
    QSerialPort *myserial;

};
#endif // WIDGET_H
