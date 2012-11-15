#include "sources/headers/vue_profil_supprimer.h"
#include "ui_vue_profil_supprimer.h"

VueProfilSupprimer::VueProfilSupprimer(QWidget *parent) :
	VueProfil(parent),
	_ui(new Ui::VueProfilSupprimer)
{
	_ui->setupUi(this);
	connexionAffichage();
	chargerDonnees();
}

VueProfilSupprimer::~VueProfilSupprimer()
{
	delete _ui;
}

void VueProfilSupprimer::onClicBoutonRetour()
{
	emit setVue(VueAccueil::toString());
}

void VueProfilSupprimer::onClicBoutonSupprimer()
{
	supprimerProfil();
}

void VueProfilSupprimer::supprimerProfil()
{
	QListView * temp = static_cast<QListView*>(_ui->listProfils);
	QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>
																 (temp->model());
	QItemSelectionModel *selectionModel = temp->selectionModel();

	QModelIndexList indexs = selectionModel->selectedRows();
	QModelIndex index;
	QString nomsProfils;

	if ( indexs.size() == 0 )
		return;

	foreach (index, indexs)
	{
		int row = proxy->mapToSource(index).row();
		nomsProfils += _profils->getProfil(row).getNom() + "\n";

	}

	if(QMessageBox::question(this,"Voulez vous supprimer :",nomsProfils,
													 QMessageBox::Yes | QMessageBox::No) ==
		 QMessageBox::Yes)
	{
		foreach (index, indexs) {
			int row = proxy->mapToSource(index).row();
			_profils->removeRow(row,QModelIndex());
		}
		chargerDonnees();
	}

}

void VueProfilSupprimer::connexionAffichage()
{
	connect(_ui->boutonRetour,SIGNAL(clicked()),this,
					SLOT(onClicBoutonRetour()));
	connect(_ui->boutonSupprimer,SIGNAL(clicked()),this,
					SLOT(onClicBoutonSupprimer()));
}

QString VueProfilSupprimer::toString()
{
	return QString("VueProfilSupprimer");
}

void VueProfilSupprimer::chargerDonnees()
{
	QSortFilterProxyModel *proxy = new QSortFilterProxyModel(this);
	proxy->setSourceModel(_profils);
	proxy->sort(0);
	_ui->listProfils->setModel(proxy);
}

