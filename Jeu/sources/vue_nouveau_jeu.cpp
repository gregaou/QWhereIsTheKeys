#include "sources/headers/vue_nouveau_jeu.h"
#include "ui_vue_nouveau_jeu.h"

VueNouveauJeu::VueNouveauJeu(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueNouveauJeu)
{

	_ui->setupUi(this);
	connexionAffichage();
}

VueNouveauJeu::~VueNouveauJeu()
{
	delete _ui;
}

void VueNouveauJeu::onClicBoutonRetour()
{
	emit setVue(VueMenuJeu::toString());
}


void VueNouveauJeu::connexionAffichage()
{
	connect(_ui->boutonRetour,SIGNAL(clicked()),
					SLOT(onClicBoutonRetour()));
}

QString VueNouveauJeu::toString()
{
	return QString("VueNouveauJeu");
}
