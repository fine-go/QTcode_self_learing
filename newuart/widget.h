#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QPushButton>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void initUI();

    QStringList getPortNameList();//获取所有可用的串口列表

    void openPort();//打开串口
public slots:
    void receiveInfo();
private:
    Ui::Widget *ui;
    QSerialPort* m_serialPort; //串口类
    QStringList m_portNameList;

    QComboBox* m_PortNameComboBox;
    QPushButton* m_OpenPortButton;
};

#endif // WIDGET_H

