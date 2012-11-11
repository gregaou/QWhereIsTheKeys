#include "qwitk.h"
#include "ui_qwitk.h"

QWITK::QWITK(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWITK)
{
    ui->setupUi(this);
}

QWITK::~QWITK()
{
    delete ui;
}
