#include "sources/headers/vue_profil_nouveau.h"
#include "ui_vue_profil_nouveau.h"

VueProfilNouveau::VueProfilNouveau(QWidget *parent) :
	VueProfil(parent),
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

void VueProfilNouveau::onClicBoutonValider()
{
	// Vérifier champs pseudo
	ajouterProfil(_ui->nomProfil->text());
}

void VueProfilNouveau::ajouterProfil(QString nom)
{
	QList<Profil> list = _profils->getList();
	Profil p(nom);

	if(!list.contains(p))
	{
		_profils->insertRow(list.size(),QModelIndex());

		QModelIndex index = _profils->index(list.size());
		_profils->setData(index,nom,Qt::EditRole);
	}
	else
	{
		QMessageBox::information(this,"Profil existant",
														 QString("Le profil \"%1\" existe déjà !").
														 arg(nom));
	}
}

void VueProfilNouveau::connexionAffichage()
{
	connect(_ui->boutonAnnuler,SIGNAL(clicked()),this,
					SLOT(onClicBoutonAnnuler()));
	connect(_ui->boutonValider,SIGNAL(clicked()),this,
					SLOT(onClicBoutonValider()));
}

QString VueProfilNouveau::toString()
{
	return QString("VueProfilNouveau");
}

