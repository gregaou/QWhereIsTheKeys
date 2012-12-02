/**
 * \file	  model_niveau.h
 * \brief	  Structure de donnée représentant les niveaux.
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      01/12/12
 */
#ifndef MODEL_NIVEAU_H
#define MODEL_NIVEAU_H

#include "sources/headers/niveau.h"
#include "sources/headers/singleton.h"
/**
 * \class ModelNiveau
 * \brief Structure de donnée représentant les niveaux.
 */
class ModelNiveau : public Singleton<ModelNiveau>
{
	friend class Singleton<ModelNiveau>;
private:
	QList<Niveau*> _niveaux; /**< Liste des niveaux */
	/**
		*  \fn    ModelNiveau()
		*  \brief Constructeur
		*/
	ModelNiveau() {}
public:
	/**
		*  \fn    void ajouterUnNiveau(Niveau *n)
		*  \param n niveau a ajouter
		*  \brief Ajoute un niveau dans la liste des niveaux
		*/
	void ajouterUnNiveau(Niveau *n);
	/**
		*  \fn    QList<Niveau*> getNiveau()
		*  \brief Retourne la liste des niveaux
		*  \return La liste des niveaux
		*/
	QList<Niveau*> getNiveaux();
};



#endif // MODEL_NIVEAU_H
