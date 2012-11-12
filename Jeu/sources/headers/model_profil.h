/**
 * \file	  model_profil.h
 * \brief	  Structure de donnée représentant une collection de profils de joueurs.
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */
#ifndef MODEL_PROFIL_H
#define MODEL_PROFIL_H
#include <QList>
#include <QFile>
#include <QAbstractlistmodel>
#include "singleton.h"
#include "profil.h"
/**
 * \class ModelProfil
 * \brief Structure de donnée représentant une collection de profils de joueurs.
 */
class ModelProfil : public Singleton<ModelProfil>, public QAbstractListModel
{
	friend class Singleton<ModelProfil>;
private:
	QList<Profil> _profils; /**< Collection de profils de joueurs */
public:
	/**
		*  \brief Constructeur
		*	 \fn    ModelProfil()
		*
		*  Constructeur de la classe ModelProfil
		*/
	ModelProfil();
	/**
		*  \brief Desstructeur
		*	 \fn    ~ModelProfil()
		*
		*  Desstructeur de la classe ModelProfil
		*/
	~ModelProfil() {}
	/**
		*  \brief Retourne les profils joueur
		*	 \fn    QList<Profil> chargerProfils(QString urlFichier)
		*	 \param urlFichier Localisation du fichier
		*  \return Liste des profils joueurs
		*
		*  Desstructeur de la classe ModelProfil
		*/
	QList<Profil> chargerProfils(QString urlFichier);
	/**
		*  \brief Compte le nombre de profil
		*	 \fn    int rowCount(const QModelIndex & parent = QModelIndex()) const
		*  \return Nombre de profil
		*/
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	/**
		*  \brief Compte le nombre de donnée d'un profil
		*	 \fn    int columnCount(const QModelIndex &parent) const
		*  \return Nombre de donnée d'un profil
		*/
	int columnCount(const QModelIndex &parent) const;
	/**
		*  \brief Retourne la donnée stockée à index
		*	 \fn    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
		*  \return Donnée stockée à index
		*/
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	/**
		*  \brief Retourne le nom de la section
		*	 \fn    QVariant headerData(int section, Qt::Orientation orientation, int role) const
		*  \return Nom de la section (Nom)
		*/
	QVariant headerData(int section, Qt::Orientation orientation,
	int role) const;
	/**
		*  \brief Insère un nouveau profil vide
		*	 \fn    bool insertRow(int row, const QModelIndex &parent)
		*  \return Vrai si réussite | Faux si echec
		*/
	bool insertRow(int row, const QModelIndex &parent);
	/**
		*  \brief Supprime un profil d'index row
		*	 \fn    bool removeRow(int row, const QModelIndex &parent)
		*  \return Vrai si réussite | Faux si echec
		*/
	bool removeRow(int row, const QModelIndex &parent);
	/**
		*  \brief Affecte un nom a un profil d'index index
		*	 \fn    bool setData(const QModelIndex &index, const QVariant &value, int role)
		*  \return Vrai si réussite | Faux si echec
		*/
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	/**
		*  \brief Retourne la liste des profils
		*	 \fn    QList<Profil> getList()
		*  \return Liste des profils
		*/
	QList<Profil> getList();
};

#endif // MODEL_PROFIL_H
