/**
 * \file	  model_profil.h
 * \brief	  Structure de donnée représentant une collection de profils de joueurs.
 * \author    BOSSOLA Grégory
 * \version   1.0
 * \date      11/11/12
 */
#ifndef MODEL_PROFIL_H
#define MODEL_PROFIL_H
#include <QList>
#include <QFile>
#include <QDir>
#include <QAbstractListModel>
#include <QTextStream>
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
	/**
		*  \brief Constructeur
		*	 \fn    ModelProfil()
		*
		*  Constructeur de la classe ModelProfil
		*/
	ModelProfil();
public:
	static const QString UrlFichierSauvegarde; /**< Url du fichier de sauvegarde */
	/**
		*  \brief Retourne les profils joueur
		*	 \fn    bool chargerProfils()
		*	 \return Vrai le fichier de sauvegarde existe sinon Faux
		*/
	bool chargerProfils();
	/**
		*  \brief Sauvegarde les profils dans le fichier
		*	 \fn    static bool sauverProfils()
		*	 \return Vrai les profils sont sauvegardés sinon Faux
		*/
	bool sauverProfils();
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
		*	 \fn    QList<Profil> getList() const
		*  \return Liste des profils
		*/
	QList<Profil> getList() const;
	/**
		*  \brief Retourne le profil à l'indice i si il existe sinon  un profil vide
		*	 \fn    Profil getProfil(int i) const
		*  \return Profil à la position i
		*/
	Profil getProfil(int i) const;
	/**
		*  \brief Supprime le profil à l'indice i si il existe
		*	 \fn    void supprimerProfil(int i)
		*  \param i Identifiant du profil a supprimer
		*  \param p Profil a insérer
		*/
	void supprimerEtRemplacerProfil(int i, Profil p);
	Profil getProfilByName(QString nom) const;
	int getIdProfilByName(QString nom) const;
};

#endif // MODEL_PROFIL_H
