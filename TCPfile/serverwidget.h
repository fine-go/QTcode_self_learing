#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

    void senddate();

private slots:
    void on_pushButtonFile_clicked();

    void on_pushButtonSend_clicked();

private:
    Ui::ServerWidget *ui;


    QTcpServer *TcpServer;
    QTcpSocket *TcpSocket;

    QFile *file;

    QString filename;
    qint64 filesize;

    qint64 sendsize;
    QTimer *mytimer;

};
#endif // SERVERWIDGET_H
