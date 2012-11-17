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

void VueChargementJeu::onClicBoutonNiveau1()
{
	emit setVue(VueNouveauJeu::toString());
}

void VueChargementJeu::onClicBoutonNiveau2()
{
	emit setVue(VueNouveauJeu::toString());
}

void VueChargementJeu::onClicBoutonNiveau3()
{
	emit setVue(VueNouveauJeu::toString());
}

void VueChargementJeu::onClicBoutonNiveau4()
{
	emit setVue(VueNouveauJeu::toString());
}

void VueChargementJeu::onClicBoutonNiveau5()
{
	emit setVue(VueNouveauJeu::toString());
}

void VueChargementJeu::onClicBoutonRetour()
{
	emit setVue(VueMenuJeu::toString());
}


void VueChargementJeu::connexionAffichage()
{
	connect(_ui->boutonNiveau1,SIGNAL(clicked()),
					SLOT(onClicBoutonNiveau1()));
	connect(_ui->boutonNiveau2,SIGNAL(clicked()),this,
					SLOT(onClicBoutonNiveau2()));
	connect(_ui->boutonNiveau3,SIGNAL(clicked()),this,
					SLOT(onClicBoutonNiveau3()));
	connect(_ui->boutonNiveau4,SIGNAL(clicked()),this,
					SLOT(onClicBoutonNiveau4()));
	connect(_ui->boutonNiveau5,SIGNAL(clicked()),this,
					SLOT(onClicBoutonNiveau5()));
	connect(_ui->boutonRetour,SIGNAL(clicked()),this,
					SLOT(onClicBoutonRetour()));
}

QString VueChargementJeu::toString()
{
	return QString("VueChargementJeu");
}

void VueChargementJeu::actualiseListeNiveaux()
{
	//en attendant, on test les acces aux niveaux en modifiant i manuellement.
	int i = 0;   //_mJeu->getDernierNiveauTermine();

	if(i>=1){
		_ui->boutonNiveau2->setEnabled(1);
		if(i>=2){
			_ui->boutonNiveau3->setEnabled(1);
			if(i>=3){
				_ui->boutonNiveau4->setEnabled(1);
				if(i>=4){
					_ui->boutonNiveau5->setEnabled(1);
				}
			}
		}
	}
}
