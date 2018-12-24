#include <QtGui/QApplication>
#include "przyklczasy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Przyklczasy w;
    w.show();
    return a.exec();
}
