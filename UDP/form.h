#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    void dealDate();
    QString gettime();
private slots:
    void on_pushButtonsend_clicked();

    void on_pushButtonclose_clicked();

private:
    Ui::Form *ui;
    QUdpSocket *udpSocket;
};

#endif // FORM_H
