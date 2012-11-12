#include <QtGui/QApplication>
#include <QDebug>
#include "sources/headers/qwitk.h"
#include "sources/headers/model_profil.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWITK w;
    w.show();

    return a.exec();
}
