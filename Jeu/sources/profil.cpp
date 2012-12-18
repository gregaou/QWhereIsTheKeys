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

QMap<int, QTime> Profil::getResultatsNiveaux() const
{
	return _resultatsNiveaux;
}

QTime Profil::getResultat(int idNiveau)
{
	if(!_resultatsNiveaux.contains(idNiveau))
		return QTime();
	return _resultatsNiveaux[idNiveau];
}

QTime Profil::getTempsTotal()
{
	QTime total;
	foreach(QTime v, _resultatsNiveaux)
		total.addSecs(v.hour() * 3600 + v.minute() * 60 + v.second());
	return total;
}

void Profil::setNom(QString nom)
{
	_nom = nom;
}

void Profil::setResultatsNiveaux(QMap<int,QTime> resultatsNiveaux)
{
	_resultatsNiveaux = resultatsNiveaux;
}

void Profil::ajouterResultatNiveau(int idNiveau, QTime temps)
{
	_resultatsNiveaux.insert(idNiveau, temps);
}

bool Profil::operator ==(const Profil & p)
{
	return (_nom == p.getNom());
}

Profil* Profil::fromString(QString str)
{
	QStringList list(str.split(Profil::_sep, QString::SkipEmptyParts));
	Profil *p = new Profil();
	int i;
	if(!list.isEmpty())
	{
		p->_nom = list.takeFirst();
		while(!list.isEmpty())
		{
			i = list.takeFirst().toInt();
			p->_resultatsNiveaux[i] = QTime::fromString(list.takeFirst());
		}
	}
	return p;
}

QString Profil::toString()
{
	QString strProfil(_nom);
	QMapIterator<int, QTime> i(_resultatsNiveaux);
	while(i.hasNext())
	{
		i.next();
		strProfil += (_sep + QString::number(i.key()) + _sep +
									i.value().toString());
	}
	return strProfil;
}
