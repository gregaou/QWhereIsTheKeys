#include "sources/headers/vue_jeu_niveau_termine.h"
#include "ui_vue_jeu_niveau_termine.h"

VueJeuNiveauTermine::VueJeuNiveauTermine(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueJeuNiveauTermine),
	_mJeu(ModelJeu::getInstance()),
	_mNiveau(ModelNiveau::getInstance())
{
	_ui->setupUi(this);
	if(_mJeu->getNiveauSelectionne() == _mNiveau->getNbNiveau()-1)
	{
		_ui->boutonNiveauSuivant->hide();
		_ui->lTemps->hide();
		connect(_ui->boutonRetourMenu,SIGNAL(clicked()),this,
						SLOT(onClicBoutonRetourMenu()));
		_ui->lTitre->setText("Jeu terminé !");
	}
	else
	{
		_mJeu->setNiveauSelectionne(_mJeu->getNiveauSelectionne()+1);
		connexionAffichage();
	}
}

VueJeuNiveauTermine::~VueJeuNiveauTermine()
{
	delete _ui;
}

void VueJeuNiveauTermine::onClicBoutonRetourMenu()
{
	emit setVue(VueJeuMenu::toString());
}

void VueJeuNiveauTermine::onclicBoutonNiveauSuivant()
{
	emit setVue(VueJeu::toString());
}

void VueJeuNiveauTermine::connexionAffichage()
{
	connect(_ui->boutonRetourMenu,SIGNAL(clicked()),this,
					SLOT(onClicBoutonRetourMenu()));
	connect(_ui->boutonNiveauSuivant,SIGNAL(clicked()),this,
					SLOT(onclicBoutonNiveauSuivant()));
	_ui->lTemps->setText(_ui->lTemps->text().append(_mJeu->getTempsNiveau().toString("hh:mm:ss:zzz")));
}

QString VueJeuNiveauTermine::toString()
{
	return QString("VueJeuNiveauTermine");
}
