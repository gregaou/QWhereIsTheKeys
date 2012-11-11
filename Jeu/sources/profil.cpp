#include "sources/headers/profil.h"

Profil::Profil(QString nom)
{
	_nom = nom;
	_resultatsNiveaux.clear();
}

QString Profil::getNom()
{
	return _nom;
}

QMap<int, int> Profil::getResultatsNiveaux()
{
	return _resultatsNiveaux;
}

int Profil::getResultat(int idNiveau)
{
	if(!_resultatsNiveaux.contains(idNiveau))
		return 0;
	return _resultatsNiveaux[idNiveau];
}

int Profil::getTempsTotal()
{
	int total = 0;
	foreach(int v, _resultatsNiveaux)
		total += v;
	return total;
}

void Profil::setNom(QString nom)
{
	_nom = nom;
}

void Profil::ajouterResultatNiveau(int idNiveau, int temps)
{
	_resultatsNiveaux.insert(idNiveau, temps);
}
