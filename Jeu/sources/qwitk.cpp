#include "sources/headers/qwitk.h"
#include "ui_qwitk.h"

QWITK::QWITK(QWidget *parent) :
	QMainWindow(parent),
	_ui(new Ui::QWITK),
	_vueFactory(VueFactory::getInstance())
{
	_ui->setupUi(this);
	setVue("dsfsd");
}

QWITK::~QWITK()
{
	delete _ui;
}

void QWITK::setVue(QString nom)
{
	_ui->centralWidget = _vueFactory->getVue(nom,this);
}
