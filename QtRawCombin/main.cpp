#include "QtRawCombin.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtRawCombin w;
    w.show();
    return a.exec();
}
