#include "widget.h"
//导入widget.h头文件
#include <QApplication>
//导入应用程序类，qt的头文件没有.h后缀
int main(int argc, char *argv[])
{
    //创建一个应用程序类，有且只有一个应用程序类,不同于窗口类
    QApplication a(argc, argv);

    //创建了一个窗口类对象，继承于MyWidget类
    Widget w;
    //窗口的创建是隐藏的需要展示出来
    w.show();
    //返回值？为什么不返回0
    //等待事件发生
    return a.exec();
}
