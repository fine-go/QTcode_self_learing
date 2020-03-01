#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
/*
 * 关于虚函数：
 *  1.虚函数只是个接口，用于抽象类实现子类的特殊方法的目的
 *  2.虚函数的实现机制由虚函数表实现，里面存放了了地址与函数的关系
 *  3.在子类继承基类的方法时，会将同名的方法隐藏，加入关键字virtual 时则为虚函数父类可具有子类的一些方法
 *  4.在虚函数的后面加上常数0则表示纯虚函数，纯虚函数不能被子类重载
 *  5.在子类虚函数的后面加上override则表示重载虚函数
*/

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
signals:

public slots:
};

#endif // MYLABEL_H
