#include "sources/headers/vue_chargement_jeu.h"
#include "ui_vue_chargement_jeu.h"
#include <qsignalmapper.h>

VueChargementJeu::VueChargementJeu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueChargementJeu),
	_mJeu(ModelJeu::getInstance())
{

	_ui->setupUi(this);

	_ui->labelChoixNiveau->setText(_mJeu->getNomProfil()+
																 " ! Voici la liste des niveaux débloqués !");
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

void VueChargementJeu::onclicBoutonNiveau(int choixNiveau)
{
	_mJeu->setNiveauSelectionne(choixNiveau);  // affiche 0 pour 1, 1 pour 2, etc... vérifer le modelJeu
	// A changer pour pouvoir charger les parties
	emit setVue(VueNouveauJeu::toString());
}

void VueChargementJeu::connexionAffichage()
{
	connect(_ui->boutonRetour,SIGNAL(clicked()),this,
					SLOT(onClicBoutonRetour()));
}

QString VueChargementJeu::toString()
{
	return QString("VueChargementJeu");
}

void VueChargementJeu::actualiseListeNiveaux()
{
	int column = 0, lineIndex = 0, line = 0;
	int indexActuel = column+lineIndex;

	QList<QPushButton*> boutons;
	QSignalMapper *signalMapper = new QSignalMapper(this);
	connect(signalMapper, SIGNAL(mapped(int)), this,
					SLOT(onclicBoutonNiveau(int)));


	int dernierNiveauTermine = 99;//_mJeu->getDernierNiveauTermine();

	while(indexActuel <= dernierNiveauTermine){
		if(column%6 == 0)
		{
			line++;
			lineIndex+=column;
			column=0;
		}
		boutons.append(new QPushButton(QString::number(indexActuel+1),0));
		_ui->gridLayoutChargerJeu->addWidget(
																boutons.at(indexActuel),line,column);
		signalMapper->setMapping(boutons[indexActuel], indexActuel);
		connect(boutons[indexActuel], SIGNAL(clicked()), signalMapper,
																											SLOT(map()));

		column++;
		indexActuel = column+lineIndex;
	}

}
