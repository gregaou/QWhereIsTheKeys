#include "sources/headers/vue_chargement_jeu.h"
#include "ui_vue_chargement_jeu.h"

VueChargementJeu::VueChargementJeu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueChargementJeu),
	_mJeu(ModelJeu::getInstance())
{

	_ui->setupUi(this);

	_ui->labelChoixNiveau->setText(_mJeu->getNomProfil()+" ! Voici la liste des niveaux débloqués !");
	_ui->labelChoixNiveau2->setText("Veuillez Cliquer sur le niveau voulu.");
	actualiseListeNiveaux();
	connexionAffichage();

}

VueChargementJeu::~VueChargementJeu()
{
	delete _ui;
}

void VueChargementJeu::onClicBoutonRetour()
{
	emit setVue(VueMenuJeu::toString());
}


void VueChargementJeu::connexionAffichage()
{
}

QString VueChargementJeu::toString()
{
	return QString("VueChargementJeu");
}

void VueChargementJeu::actualiseListeNiveaux()
{
}
