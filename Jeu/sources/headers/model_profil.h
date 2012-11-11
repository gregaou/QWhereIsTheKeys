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
		*	 \fn    ModelProfil();
		*
		*  Constructeur de la classe ModelProfil
		*/
	ModelProfil();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
};

#endif // MODEL_PROFIL_H
