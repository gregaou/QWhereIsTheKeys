#include "sources/headers/vue_credit.h"
#include "ui_vue_credit.h"

VueCredit::VueCredit(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueCredit)
{

	_ui->setupUi(this);

	connexionAffichage();
}

VueCredit::~VueCredit()
{
	delete _ui;
}

void VueCredit::onClicBoutonRetourMenu()
{
	emit setVue(VueAccueil::toString());
}

void VueCredit::connexionAffichage()
{
	connect(_ui->bouton,SIGNAL(clicked()),this,SLOT(onClicBoutonRetourMenu()));
}

QString VueCredit::toString()
{
	return QString("VueCredit");
}
