#include "sources/headers/vue_profil_charger.h"
#include "ui_vue_profil_charger.h"

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


void VueProfilCharger::connexionAffichage()
{
	connect(_ui->boutonAnnuler,SIGNAL(clicked()),this,
					SLOT(onClicBoutonAnnuler()));
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

