 #include "sources/headers/model_profil.h"

const QString ModelProfil::UrlFichierSauvegarde = "sauvegarde/sauv.txt";

ModelProfil::ModelProfil() :
	QAbstractListModel()
{
	if(!chargerProfils())
	{
		/**
			*  \todo Warning : Fichier non disponible !
			*/
	}
}

bool ModelProfil::chargerProfils()
{
	QFile file(UrlFichierSauvegarde);
	if(!file.exists())
	{
		QDir d;
		d.mkdir(UrlFichierSauvegarde.split("/")[0]);
		file.open(QIODevice::Append);
		file.close();
	}
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;
	QTextStream in(&file);
	Profil *profil;
	QString str;
	while(!in.atEnd())
	{
		str = in.readLine();
		profil = Profil::fromString(str);
		this->insertRow(this->rowCount(), QModelIndex());
		QModelIndex index = this->index(this->rowCount() - 1);
		_profils.replace(index.row(), *profil);
		this->setData(index, profil->getNom(), Qt::DisplayRole);
	}
	file.close();
	return true;
}

bool ModelProfil::sauverProfils()
{
	QList<Profil> profils = getList();
	QFile file(ModelProfil::UrlFichierSauvegarde);
	if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return false;
	QTextStream out(&file);
	QString strProfil;
	if(profils.size() > 0)
		strProfil += profils[0].toString();
	for(int i = 1; i < profils.size(); i++)
		strProfil += ("\n" + profils[i].toString());
	out << strProfil;
	file.close();
	return (out.status() == QTextStream::WriteFailed);
}

int ModelProfil::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return _profils.size();
}

int ModelProfil::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return 1;
}

QVariant ModelProfil::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();
	if (index.row() >=  _profils.size() || index.row() < 0)
		return QVariant();
	if(role == Qt::DisplayRole && index.column() == 0)
		return _profils.at(index.row()).getNom();
	return QVariant();
}

QVariant ModelProfil::headerData(int section, Qt::Orientation orientation,
																 int role) const
{
	if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch(section)
		{
			case 0:
				return "Nom";
			default:
				return QVariant();
		}
	}
	return QVariant();
}

bool ModelProfil::insertRow(int row, const QModelIndex &parent)
{
	Q_UNUSED(parent);
	if(row == _profils.size())
	{
		Profil p;
		_profils.insert(row, p);
		return true;
	}
	return false;
}

bool ModelProfil::removeRow(int row, const QModelIndex &parent)
{
	Q_UNUSED(parent);
	if(row < _profils.size())
	{
		_profils.removeAt(row);
	}
	return sauverProfils();
}

bool ModelProfil::setData(const QModelIndex &index, const QVariant &value,
													int role)
{
	if(index.isValid())
	{
		int row = index.row();
		Profil p;
		p.setNom(value.toString());
		p.setResultatsNiveaux(getList().at(row).getResultatsNiveaux());
		_profils.replace(row, p);
		if(role == Qt::EditRole)
			return sauverProfils();
		return true;
	}
	return false;
}

QList<Profil> ModelProfil::getList() const
{
	return _profils;
}

Profil ModelProfil::getProfil(int i) const
{
	if(i >= 0 && i < _profils.size())
		return _profils[i];
	return Profil();
}

void ModelProfil::supprimerEtRemplacerProfil(int i, Profil p)
{
	if(i >= 0 && i < _profils.size())
		_profils[i] = p;
}

Profil ModelProfil::getProfilByName(QString nom) const
{
	QList<Profil> profils;
	profils = this->getList();
	for(int i = 0; i < profils.size(); i++)
	{
		if(profils.at(i).getNom() == nom)
			return profils.at(i);
	}
	Profil p;
	return p;
}

int ModelProfil::getIdProfilByName(QString nom) const
{
	QList<Profil> profils;
	profils = this->getList();
	for(int i = 0; i < profils.size(); i++)
	{
		if(profils.at(i).getNom() == nom)
			return i;
	}
	return -1;
}
