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
#include <QAbstractitemmodel>
#include "singleton.h"
#include "profil.h"
/**
 * \class ModelProfil
 * \brief Structure de donnée représentant une collection de profils de joueurs.
 */
class ModelProfil : public Singleton<ModelProfil>, public QAbstractItemModel
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
	~ModelProfil();
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
		*  \brief Compte le nombre de donnée que comporte un profil
		*	 \fn    int columnCount(const QModelIndex &parent = QModelIndex()) const;
		*  \return Nombre de donnée que comporte un profil
		*/
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	/**
		*  \brief Retourne la donnée associée au rôle role et pour l'index index
		*	 \fn    QVariant data(const QModelIndex &index, int role) const
		*  \return Donnée associée au rôle role et pour l'index index
		*/
	QVariant data(const QModelIndex &index, int role) const;
};

#endif // MODEL_PROFIL_H
