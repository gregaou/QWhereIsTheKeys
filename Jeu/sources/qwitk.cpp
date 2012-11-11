#include "sources/headers/qwitk.h"
#include "ui_qwitk.h"

QWITK::QWITK(QWidget *parent) :
    QMainWindow(parent),
		_ui(new Ui::QWITK)
{
		_ui->setupUi(this);
}

QWITK::~QWITK()
{
		delete _ui;
}

void QWITK::setVue(QString nom)
{

}
