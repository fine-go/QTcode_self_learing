#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FaderWidget w;
    w.show();

    return a.exec();
}
