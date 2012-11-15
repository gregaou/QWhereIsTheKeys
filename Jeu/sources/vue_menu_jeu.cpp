#include "sources/headers/vue_menu_jeu.h"
#include "ui_vue_menu_jeu.h"


#include <QDebug>

VueMenuJeu::VueMenuJeu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueMenuJeu)
{

	_ui->setupUi(this);
	_ui->labelProfilNom->setText("plop");
	connexionAffichage();
}

VueMenuJeu::~VueMenuJeu()
{
	delete _ui;
}

void VueMenuJeu::onClicBoutonNouvellePartie()
{
	emit setVue("VueNouveauJeu");
}

void VueMenuJeu::onClicBoutonChargerPartie()
{
	//emit setVue("VueChargerPartie");
}

void VueMenuJeu::onClicBoutonCreerPartieMultijoueur()
{
	emit setVue("VueNouveauJeu");
}

void VueMenuJeu::onClicBoutonRejoindrePartieMultijoueur()
{
	emit setVue("VueNouveauJeu");
}

void VueMenuJeu::onClicBoutonQuitterMenuJeu()
{
	emit setVue("VueAccueil");
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

