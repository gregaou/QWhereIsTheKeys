#include "sources/headers/profil.h"

Profil::Profil(QString nom)
{
	this->_nom = nom;
	this->_resultatsNiveaux->clear();
}

QString Profil::getNom()
{
	return this->_nom;
}

QMap Profil::getResultatsNiveaux()
{
	return this->_resultatsNiveaux;
}

int Profil::getResultat(int idNiveau)
{
	if(!this->_resultatsNiveaux->contains(idNiveau))
		return 0;
	return this->_resultatsNiveaux[idNiveau];
}

int Profil::getTempsTotal()
{
	int total = 0;
	foreach(int v, this->_resultatsNiveaux)
		total += v;
	return total;
}

void Profil::setNom(QString nom)
{
	this->_nom = nom;
}

void Profil::ajouterResultatNiveau(int idNiveau, int temps)
{
	this->_resultatsNiveaux->insert(idNiveau, temps);
}
