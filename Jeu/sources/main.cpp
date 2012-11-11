#include <QtGui/QApplication>
#include "sources/headers/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWhereIsTheKeysWindows w;
    w.show();
    
    return a.exec();
}
