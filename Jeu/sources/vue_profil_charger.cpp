#include "sources/headers/vue_profil_charger.h"
#include "ui_vue_profil_charger.h"

VueProfilCharger::VueProfilCharger(QWidget *parent) :
	VueProfil(parent),
	_ui(new Ui::VueProfilCharger)
{
	_ui->setupUi(this);
	connexionAffichage();
}

VueProfilCharger::~VueProfilCharger()
{
	delete _ui;
}

void VueProfilCharger::onClicBoutonAnnuler()
{
	emit setVue("VueAccueil");
}


void VueProfilCharger::connexionAffichage()
{
	connect(_ui->boutonAnnuler,SIGNAL(clicked()),this,
					SLOT(onClicBoutonAnnuler()));
}

QString VueProfilCharger::toString()
{
	return QString("VueProfilCharger");
}

