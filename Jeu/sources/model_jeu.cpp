#include "sources/headers/model_jeu.h"

ModelJeu::ModelJeu() : _profils(ModelProfil::getInstance()){}

void ModelJeu::setIdProfil(int id)
{
	_idProfil = id;
}
void ModelJeu::setNiveauSelectionne(int niveauSelectionne)
{
	_niveauSelectionne = niveauSelectionne;
}

int ModelJeu::getNiveauSelectionne()
{
	return _niveauSelectionne;
}

void ModelJeu::setTempsNiveau(QTime temps)
{
	_tempsNiveau = temps;
}

QTime ModelJeu::getTempsNiveau()
{
	return _tempsNiveau;
}

QString ModelJeu::getNomProfil()
{
	return _profils->getProfil(_idProfil).getNom();
}

int ModelJeu::getDernierNiveauTermine()
{
	Profil p;
	QMap<int, QTime> resultatsNiveaux;
	p = _profils->getProfil(_idProfil);
	resultatsNiveaux = p.getResultatsNiveaux();
	return resultatsNiveaux.count();
}

bool ModelJeu::ajouterScore(int idNiveau, QTime temps)
{
	_profils->getProfil(_idProfil).ajouterResultatNiveau(idNiveau, temps);
	return true;
}
