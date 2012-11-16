#include "sources/headers/profil.h"

const QString Profil::_sep = "*|*";

Profil::Profil()
{
	_nom = "";
	_resultatsNiveaux.clear();
}

Profil::Profil(QString nom)
{
	_nom = nom;
	_resultatsNiveaux.clear();
}

QString Profil::getNom() const
{
	return _nom;
}

QMap<int, int> Profil::getResultatsNiveaux() const
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

bool Profil::operator ==(const Profil & p)
{
	return (_nom == p.getNom());
}

void Profil::fromString(QString str)
{
	QStringList list(str.split(Profil::_sep, QString::SkipEmptyParts));
	int i;
	if(!list.isEmpty())
	{
		_nom = list.takeFirst();
		while(!list.isEmpty())
		{
			i = list.takeFirst().toInt();
			_resultatsNiveaux[i] = list.takeFirst().toInt();
		}
	}
}

QString Profil::toString()
{
	QString strProfil(_nom);
	QMapIterator<int, int> i(_resultatsNiveaux);
	while(i.hasNext())
	{
		i.next();
		strProfil += (Profil::_sep + i.key() + Profil::_sep + i.value());
	}
	return strProfil;
}
