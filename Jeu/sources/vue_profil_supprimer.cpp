#include "sources/headers/vue_profil_supprimer.h"
#include "ui_vue_profil_supprimer.h"

VueProfilSupprimer::VueProfilSupprimer(QWidget *parent) :
	VueProfil(parent),
	_ui(new Ui::VueProfilSupprimer)
{
	_ui->setupUi(this);
	connexionAffichage();
}

VueProfilSupprimer::~VueProfilSupprimer()
{
	delete _ui;
}

void VueProfilSupprimer::onClicBoutonRetour()
{
	emit setVue("VueAccueil");
}

void VueProfilSupprimer::connexionAffichage()
{
	connect(_ui->boutonRetour,SIGNAL(clicked()),this,
					SLOT(onClicBoutonRetour()));
}

QString VueProfilSupprimer::toString()
{
	return QString("VueProfilSupprimer");
}

