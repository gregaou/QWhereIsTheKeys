#include "sources/headers/vue_accueil.h"
#include "ui_vue_accueil.h"


VueAccueil::VueAccueil(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueAccueil)
{
	_ui->setupUi(this);

	connexionAffichage();
}

VueAccueil::~VueAccueil()
{
	delete _ui;
}

void VueAccueil::onClicBoutonNouveauProfil()
{
	emit setVue("VueProfilNouveau");
}

void VueAccueil::connexionAffichage()
{
	connect(_ui->boutonQuitter,SIGNAL(clicked()),_qwitk,SLOT(close()));
	connect(_ui->boutonNouveauProfil,SIGNAL(clicked()),this,
					SLOT(onClicBoutonNouveauProfil()));
}

QString VueAccueil::toString()
{
	return QString("VueAccueil");
}
