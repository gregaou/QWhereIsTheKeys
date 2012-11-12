#include "sources/headers/model_profil.h"

ModelProfil::ModelProfil() :
	QAbstractListModel()
{
	Profil p1("t1");
	Profil p2("t2");
	Profil p3("t3");
	_profils.push_back(p1);
	_profils.push_back(p2);
	_profils.push_back(p3);
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
	return false;
}

bool ModelProfil::setData(const QModelIndex &index, const QVariant &value,
	int role)
{
	if(index.isValid() && role == Qt::EditRole)
	{
		int row = index.row();
		Profil p;
		p.setNom(value.toString());
		_profils.replace(row, p);
		return true;
	}
	return false;
}

QList<Profil> ModelProfil::getList()
{
	return _profils;
}
