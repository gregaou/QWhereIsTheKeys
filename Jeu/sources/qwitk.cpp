#include "sources/headers/qwitk.h"
#include "ui_qwitk.h"

QWITK::QWITK(QWidget *parent) :
	QMainWindow(parent),
	_ui(new Ui::QWITK),
	_vueFactory(VueFactory::getInstance()),
	_vue(0)
{
	_ui->setupUi(this);

	setVue();
}

QWITK::~QWITK()
{
	delete _ui;
}

void QWITK::setVue(QString nom)
{
	if(_vue) {
		_vue->deleteLater();
		_vue = 0;
	}
	_vue = _vueFactory->getVue(nom,this);
	connexionVue();
	setCentralWidget(_vue);
	_vue->setFocus();
}

void QWITK::connexionVue()
{
	connect(_vue,SIGNAL(setVue(QString)),this,SLOT(setVue(QString)));
}
