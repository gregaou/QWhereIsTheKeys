#include <QtGui/QApplication>
#include "sources/headers/qwitk.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWITK w;
    w.show();
    
    return a.exec();
}
