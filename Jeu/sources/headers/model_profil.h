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
#include <QAbstractListModel>
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
	static const QString UrlFichierSauvegarde; /**< Url du fichire de sauvegarde */
	/**
		*  \brief Constructeur
		*	 \fn    ModelProfil()
		*
		*  Constructeur de la classe ModelProfil
		*/
	ModelProfil();
	/**
		*  \brief Destructeur
		*	 \fn    ~ModelProfil()
		*
		*  Destructeur de la classe ModelProfil
		*/
	~ModelProfil() {}
	/**
		*  \brief Retourne les profils joueur
		*	 \fn    bool chargerProfils()
		*	 \return Vrai le fichier de sauvegarde existe sinon Faux
		*/
	bool chargerProfils();
	/**
		*  \brief Retourne le profil joueur d'identifiant nom
		*	 \fn    bool chargerProfil(QString nom)
		*  \param nom Chaine de caractère représentant le nom du profil à charger
		*	 \return Vrai le profil existe sinon Faux
		*/
	bool chargerProfil(QString nom);
	/**
		*  \brief S
		*	 \fn    bool sauverProfil(Profil profil)
		*  \param profil Profil à sauvegarder
		*	 \return Vrai le profil est sauvegardé sinon Faux
		*/
	bool sauverProfil(Profil profil);
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
};

#endif // MODEL_PROFIL_H
