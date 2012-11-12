#include "sources/headers/vue_profil_nouveau.h"
#include "ui_vue_profil_nouveau.h"

#include <QDebug>

VueProfilNouveau::VueProfilNouveau(QWidget *parent) :
	Vue(parent),
	_ui(new Ui::VueProfilNouveau)
{
	_ui->setupUi(this);
	connexionAffichage();
}

VueProfilNouveau::~VueProfilNouveau()
{
	delete _ui;
}

void VueProfilNouveau::onClicBoutonAnnuler()
{
	emit setVue("VueAccueil");
}

void VueProfilNouveau::connexionAffichage()
{
	connect(_ui->boutonAnnuler,SIGNAL(clicked()),this,
					SLOT(onClicBoutonAnnuler()));
}

QString VueProfilNouveau::toString()
{
	return QString("VueProfilNouveau");
}

