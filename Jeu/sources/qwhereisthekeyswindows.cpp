#include "sources/headers/mainwindow.h"
#include "ui_mainwindow.h"

QWhereIsTheKeysWindows::QWhereIsTheKeysWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWhereIsTheKeysWindows)
{
    ui->setupUi(this);

    QUiLoader loader;
    QFile file(":ui/accueil.ui");
    file.open(QFile::ReadOnly);
    QWidget *myWidget = loader.load(&file, this);
    file.close();

    setCentralWidget(myWidget);


    QFile file2(":ui/jeu.ui");
    file2.open(QFile::ReadOnly);
    myWidget = loader.load(&file2, this);
    file2.close();
    setCentralWidget(myWidget);

}

QWhereIsTheKeysWindows::~QWhereIsTheKeysWindows()
{
    delete ui;
}
