#include "sources/headers/model_jeu.h"

ModelJeu::ModelJeu() : _profils(ModelProfil::getInstance()){}

void ModelJeu::setIdProfil(int id)
{
	_idProfil = id;
}

int ModelJeu::getDernierNiveauTermine()
{
	Profil p;
	QMap<int, int> resultatsNiveaux;
	p = _profils->getProfil(_idProfil);
	resultatsNiveaux = p.getResultatsNiveaux();
	return resultatsNiveaux.count();
}

bool ModelJeu::ajouterScore(int idNiveau, int temps)
{
	_profils->getProfil(_idProfil).ajouterResultatNiveau(idNiveau, temps);
	return true;
}
