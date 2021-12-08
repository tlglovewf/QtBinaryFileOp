#include "NetControl.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetControl w;
    w.show();
    return a.exec();
}
