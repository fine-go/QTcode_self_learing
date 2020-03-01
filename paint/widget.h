#ifndef WIDGET_H
#define WIDGET_H

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

protected:
    //重写绘图时间
    //如果在窗口绘图，必须放在绘图事件里面实现
    //绘图事件内部自动调用，窗口需要重绘的时候（窗口的状态改变），
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    int x;
};
#endif // WIDGET_H
