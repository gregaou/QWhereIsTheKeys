#include "sources/headers/vue_accueil.h"
#include "ui_vue_accueil.h"

#include <QDebug>

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
	emit setVue(VueProfilNouveau::toString());
}

void VueAccueil::onClicBoutonChargerProfil()
{
	emit setVue(VueProfilCharger::toString());
}

void VueAccueil::onClicBoutonSupprimerProfil()
{
	emit setVue(VueProfilSupprimer::toString());
}

void VueAccueil::connexionAffichage()
{
	connect(_ui->boutonQuitter,SIGNAL(clicked()),_qwitk,SLOT(close()));
	connect(_ui->boutonNouveauProfil,SIGNAL(clicked()),this,
					SLOT(onClicBoutonNouveauProfil()));
	connect(_ui->boutonChargerProfil,SIGNAL(clicked()),this,
					SLOT(onClicBoutonChargerProfil()));
	connect(_ui->boutonSupprimerProfil,SIGNAL(clicked()),this,
					SLOT(onClicBoutonSupprimerProfil()));
}

QString VueAccueil::toString()
{
	return QString("VueAccueil");
}
