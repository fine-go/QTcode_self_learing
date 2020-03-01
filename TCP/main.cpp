#include "severwidget.h"
#include "clienwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SeverWidget w;
    w.show();

    ClienWidget w2;
    w2.show();
    return a.exec();
}
