#ifndef WIDGET_H
#define WIDGET_H
#include <QUdpSocket>

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void dealData();
    QString gettime();

private slots:
    void on_pushButtonsend_clicked();

    void on_pushButtonclose_clicked();

private:

    QUdpSocket *udpSocket; //udp 套接字
    Ui::Widget *ui;
};
#endif // WIDGET_H
