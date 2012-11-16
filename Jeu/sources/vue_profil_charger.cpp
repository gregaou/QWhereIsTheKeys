#include "sources/headers/vue_profil_charger.h"
#include "ui_vue_profil_charger.h"
#include "sources/headers/vue_menu_jeu.h"

#include <QDebug>

VueProfilCharger::VueProfilCharger(QWidget *parent) :
	VueProfil(parent),
	_ui(new Ui::VueProfilCharger)
{
	_ui->setupUi(this);
	connexionAffichage();
	chargerDonnees();
}

VueProfilCharger::~VueProfilCharger()
{
	delete _ui;
}

void VueProfilCharger::onClicBoutonAnnuler()
{
	emit setVue(VueAccueil::toString());
}

void VueProfilCharger::onClicBoutonValider()
{

	if(_ui->listProfils->currentIndex().row() != -1)
	{
		ModelJeu *jeu = ModelJeu::getInstance();
		jeu->setIdProfil(_profils->getIdProfilByName(
											 _ui->listProfils->currentIndex().data().toString()));

		emit setVue(VueMenuJeu::toString());
	}
}

void VueProfilCharger::connexionAffichage()
{
	connect(_ui->boutonAnnuler,SIGNAL(clicked()),this,
					SLOT(onClicBoutonAnnuler()));
	connect(_ui->boutonValider,SIGNAL(clicked()),this,
					SLOT(onClicBoutonValider()));
}

void VueProfilCharger::chargerDonnees()
{
	QSortFilterProxyModel *proxy = new QSortFilterProxyModel(this);
	proxy->setSourceModel(_profils);
	proxy->sort(0);
	_ui->listProfils->setModel(proxy);
}

QString VueProfilCharger::toString()
{
	return QString("VueProfilCharger");
}

