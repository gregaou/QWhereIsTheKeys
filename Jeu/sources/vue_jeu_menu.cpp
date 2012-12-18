#include "sources/headers/vue_jeu_menu.h"
#include "ui_vue_jeu_menu.h"

VueJeuMenu::VueJeuMenu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueJeuMenu),
	_mJeu(ModelJeu::getInstance())
{

	_ui->setupUi(this);

	_ui->labelProfilNom->setText(_mJeu->getNomProfil());

	connexionAffichage();
}

VueJeuMenu::~VueJeuMenu()
{
	delete _ui;
}

void VueJeuMenu::onClicBoutonNouvellePartie()
{
	_mJeu->setNiveauSelectionne(0);
	emit setVue(VueJeu::toString());
}

void VueJeuMenu::onClicBoutonChargerPartie()
{
	emit setVue(VueJeuCharger::toString());
}

void VueJeuMenu::onClicBoutonQuitterMenuJeu()
{
	_mJeu->kill();
	emit setVue(VueAccueil::toString());
}


void VueJeuMenu::connexionAffichage()
{
	connect(_ui->boutonNouvellePartie,SIGNAL(clicked()),
					SLOT(onClicBoutonNouvellePartie()));
	connect(_ui->boutonChargerPartie,SIGNAL(clicked()),this,
					SLOT(onClicBoutonChargerPartie()));
	connect(_ui->boutonQuitterMenuJeu,SIGNAL(clicked()),this,
					SLOT(onClicBoutonQuitterMenuJeu()));
}

QString VueJeuMenu::toString()
{
	return QString("VueJeuMenu");
}

