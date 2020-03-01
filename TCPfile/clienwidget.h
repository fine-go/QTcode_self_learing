#ifndef CLIENWIDGET_H
#define CLIENWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>

namespace Ui {
class ClienWidget;
}

class ClienWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClienWidget(QWidget *parent = nullptr);
    ~ClienWidget();

private slots:
    void on_pushButtonConnect_clicked();

private:
    Ui::ClienWidget *ui;

    QTcpSocket *TcpSocket;

    QFile *file;

    QString filename;
    qint64 filesize;

    qint64 recvsize;

    bool head_flag;
    QTimer *mytimer;

};

#endif // CLIENWIDGET_H
