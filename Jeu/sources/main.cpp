#include <QtGui/QApplication>
#include "qwitkwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWITKWindow w;
    w.show();
    
    return a.exec();
}
