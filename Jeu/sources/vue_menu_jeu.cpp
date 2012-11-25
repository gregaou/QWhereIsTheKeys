#include "sources/headers/vue_menu_jeu.h"
#include "ui_vue_menu_jeu.h"

VueMenuJeu::VueMenuJeu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueMenuJeu),
	_mJeu(ModelJeu::getInstance())
{

	_ui->setupUi(this);

	_ui->labelProfilNom->setText(_mJeu->getNomProfil());

	connexionAffichage();
}

VueMenuJeu::~VueMenuJeu()
{
	delete _ui;
}

void VueMenuJeu::onClicBoutonNouvellePartie()
{
	emit setVue(VueJeu::toString());
}

void VueMenuJeu::onClicBoutonChargerPartie()
{
	emit setVue(VueChargementJeu::toString());
}

void VueMenuJeu::onClicBoutonCreerPartieMultijoueur()
{
	emit setVue(VueNouveauJeu::toString());
}

void VueMenuJeu::onClicBoutonRejoindrePartieMultijoueur()
{
	emit setVue(VueNouveauJeu::toString());
}

void VueMenuJeu::onClicBoutonQuitterMenuJeu()
{
	_mJeu->kill();
	emit setVue(VueAccueil::toString());
}


void VueMenuJeu::connexionAffichage()
{
	connect(_ui->boutonNouvellePartie,SIGNAL(clicked()),
					SLOT(onClicBoutonNouvellePartie()));
	connect(_ui->boutonChargerPartie,SIGNAL(clicked()),this,
					SLOT(onClicBoutonChargerPartie()));
	connect(_ui->boutonCreerPartieMultijoueur,SIGNAL(clicked()),this,
					SLOT(onClicBoutonCreerPartieMultijoueur()));
	connect(_ui->boutonRejoindrePartieMultijoueur,SIGNAL(clicked()),this,
					SLOT(onClicBoutonRejoindrePartieMultijoueur()));
	connect(_ui->boutonQuitterMenuJeu,SIGNAL(clicked()),this,
					SLOT(onClicBoutonQuitterMenuJeu()));
}

QString VueMenuJeu::toString()
{
	return QString("VueMenuJeu");
}

