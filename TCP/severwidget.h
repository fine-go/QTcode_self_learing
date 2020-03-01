#ifndef SEVERWIDGET_H
#define SEVERWIDGET_H

#include <QWidget>
#include <QTcpServer> //监听套接字
#include <QTcpSocket> //建立好连接的通信套接字


QT_BEGIN_NAMESPACE
namespace Ui { class SeverWidget; }
QT_END_NAMESPACE

class SeverWidget : public QWidget
{
    Q_OBJECT

public:
    SeverWidget(QWidget *parent = nullptr);
    ~SeverWidget();
    static QString gettime();

private slots:
    void on_pushButtonsend_clicked();

    void on_pushButtonclose_clicked();

private:
    Ui::SeverWidget *ui;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;


};
#endif // SEVERWIDGET_H
