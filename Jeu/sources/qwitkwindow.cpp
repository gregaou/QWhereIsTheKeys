#include "qwitkwindow.h"
#include "ui_qwitkwindow.h"

QWITKWindow::QWITKWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWITKWindow)
{
    ui->setupUi(this);
}

QWITKWindow::~QWITKWindow()
{
    delete ui;
}
