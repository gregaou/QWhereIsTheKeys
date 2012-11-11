#include <QtGui/QApplication>
#include "mainwindow.h"
#include "monserveur.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    MonServeur server;
    server.startServer();

    return a.exec();
}
