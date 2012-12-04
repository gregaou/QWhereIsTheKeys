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
	QGraphicsScene* _scene; /**< Scene des niveaux */
	/**
		*  \fn    ModelNiveau()
		*  \brief Constructeur
		*/
	ModelNiveau(){}
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
	/**
		*  \fn    setScene(QGraphicsScene *scene)
		*  \brief Mutateur de la donnée membre _scene
		*  \param scene la scene des niveaux
		*/
	void setScene(QGraphicsScene *scene);
	/**
		*  \fn    QGraphicsScene* getScene()
		*  \brief Accesseur de la donnée membre _scene
		*  \return La scene des niveaux
		*/
	QGraphicsScene* getScene();
	/**
		*  \fn    void chargerNiveaux()
		*  \brief Charge les niveaux dans la liste des niveaux
		*/
	void chargerNiveaux();
};



#endif // MODEL_NIVEAU_H
