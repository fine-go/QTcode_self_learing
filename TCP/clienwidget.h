#ifndef CLIENWIDGET_H
#define CLIENWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ClienWidget;
}

class ClienWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClienWidget(QWidget *parent = nullptr);
    ~ClienWidget();

    QTcpSocket *tcpSocket;
    QString gettime();

private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonsend_clicked();

    void on_pushButtonclose_clicked();

private:
    Ui::ClienWidget *ui;
};

#endif // CLIENWIDGET_H
