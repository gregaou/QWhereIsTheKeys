/**
 * \file	  niveau.h
 * \brief	  Structure de donnée représentant un niveau.
 * \author    BUISSON Fabien
 * \version   1.0
 * \date      01/12/12
 */

#ifndef NIVEAU_H
#define NIVEAU_H
/**
 * \class niveau
 * \brief Structure de donnée représentant un niveau.
 */
#include <QList>
#include <QGraphicsScene>
#include "macro_sprite.h"
#include "sources/headers/collision_oj.h"
/**
 * \class Niveau
 * \brief Structure de donnée représentant un niveau.
 */
class Niveau
{
private:
	QList<ObjetJeu*> _objets; /**< Liste des objets du niveau */
	CollisionOj *_cOj; /**< Chaîne de responsabilité traitant les collisions*/
public:
	/**
		*  \fn    Niveau(QGraphicsScene *scene)
		*  \param scene la scene qui contiendra le niveau
		*  \brief Constructeur
		*/
	Niveau(QGraphicsScene *scene);
	/**
		*  \brief Retourne l'objet représentant le héros
		*	 \fn    OjHeros* getHeros()
		*	 \return L'objet représentant le héros
		*/
	OjHeros *getHeros();
	/**
		*  \brief Retourne les objets du niveau(plateformes, ennemis...)
		*	 \fn    QList<ObjetJeu *> getObjets()
		*	 \return Une liste contenant les objets du niveau
		*/
	QList<ObjetJeu*> getObjets();
	/**
		*  \brief Ajoute un objet au niveau
		*	 \fn    void addObject(ObjetJeu* obj)
		*  \param obj l'objet que l'on veut ajouter au niveau
		*/
	void addObject(ObjetJeu* obj);
};

#endif // NIVEAU_H
