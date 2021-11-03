#include "PgrExport.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PgrExport w;
    w.show();
    return a.exec();
}
