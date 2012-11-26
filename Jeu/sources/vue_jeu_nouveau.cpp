#include "sources/headers/vue_jeu_nouveau.h"
#include "ui_vue_jeu_nouveau.h"

VueJeuNouveau::VueJeuNouveau(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueJeuNouveau)
{

	_ui->setupUi(this);
	connexionAffichage();
}

VueJeuNouveau::~VueJeuNouveau()
{
	delete _ui;
}

void VueJeuNouveau::onClicBoutonRetour()
{
	emit setVue(VueJeuMenu::toString());
}


void VueJeuNouveau::connexionAffichage()
{
	connect(_ui->boutonRetour,SIGNAL(clicked()),
					SLOT(onClicBoutonRetour()));
}

QString VueJeuNouveau::toString()
{
	return QString("VueJeuNouveau");
}
