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
	emit setVue("VueNouvellePartie");
}

void VueMenuJeu::onClicBoutonChargerPartie()
{
	emit setVue("VueChargerPartie");
}

void VueMenuJeu::onClicBoutonCreerPartieMultijoueur()
{
	emit setVue("VueCreerPartieEnLigne");
}

void VueMenuJeu::onClicBoutonRejoindrePartieMultijoueur()
{
	emit setVue("VueRejoindrePartieEnLigne");
}

void VueMenuJeu::connexionAffichage()
{
	connect(_ui->boutonNouvellePartie,SIGNAL(clicked()),
					SLOT(onClicBoutonNouvellePartie()));
	connect(_ui->boutonChargerPartie,SIGNAL(clicked()),this,
					SLOT(onClicBoutonChargerPartie()));
	connect(_ui->boutonCreerPartieMultijoueur,SIGNAL(clicked()),this,
					SLOT(onClicCreerPartieMultijoueur()));
	connect(_ui->boutonRejoindrePartieMulti,SIGNAL(clicked()),this,
					SLOT(onClicBoutonRejoindrePartieMultijoueur()));
}

QString VueMenuJeu::toString()
{
	return QString("VueMenuJeu");
}

