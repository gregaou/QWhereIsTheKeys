/**
 * \file			collision_oj.h
 * \brief			Chaîne de responsabilité gérant les collisions
 * \author    PACHY Ravi
 * \version   1.0
 * \date      01/12/12
 */

#ifndef COLLISION_OJ_HEROS_H
#define COLLISION_OJ_HEROS_H

#include "sources/headers/vue_jeu.h"
#include "sources/headers/collision_oj.h"

class VueJeu;

class CollisionOjHeros : public CollisionOj
{
public:
	/**
		*  \fn    CollisionOjHeros ()
		*  \brief Constructeur
		*/
	CollisionOjHeros(VueJeu* vueJeu);

	/**
		*  \fn    virtual void gererCollision(ObjetJeu* oj1, ObjetJeu* oj2) = 0
		*  \param oj1 premier ObjetJeu
		*  \param oj2 deuxieme ObjetJeu
		*  \brief GÃ¨re la collision entre deux ObjetJeu
		*/
	void gererCollision(ObjetJeu* oj1, ObjetJeu* oj2);

	/**
		*  \fn    static QString toString ()
		*  \brief Retourne le nom de la classe
		*/
	static QString toString() { return QString("CollisionOjHeros"); }
private:
	VueJeu* _view; /**< Vue Graphique du jeu */
	/**
		*  \fn    void collisionEntre(OjHeros *h, OjPlateforme *p);
		*  \param h Pointeur vers OjHeros
		*  \param p Pointeur vers OjPlateforme
		*  \brief DÃ©finit le comportement d'une collision entre un OjHeros et un OjPlateforme
		*/
	void collisionEntre(OjHeros *h, OjPlateforme *p);
};

#endif // COLLISION_OJ_HEROS_H
