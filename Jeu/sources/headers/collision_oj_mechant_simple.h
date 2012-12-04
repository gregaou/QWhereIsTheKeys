/**
 * \file			collision_oj_mechant_simple.h
 * \brief			gestion des collisions d'un objet jeu méchant simple
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      22/04/12
 */
#ifndef COLLISION_OJ_MECHANT_SIMPLE_H
#define COLLISION_OJ_MECHANT_SIMPLE_H

#include "sources/headers/collision_oj.h"

class CollisionOjMechantSimple : public CollisionOj
{
public:
	/**
		*  \fn    CollisionOjMechantSimple ()
		*  \brief Constructeur
		*/
	CollisionOjMechantSimple() : CollisionOj("OjMechantSimple") {}

	/**
		*  \fn    virtual void gererCollision(ObjetJeu* oj1, ObjetJeu* oj2) = 0
		*  \param oj1 premier ObjetJeu
		*  \param oj2 deuxieme ObjetJeu
		*  \brief Gère la collision entre deux ObjetJeu
		*/
	void gererCollision(ObjetJeu* oj1, ObjetJeu* oj2);

	/**
		*  \fn    static QString toString ()
		*  \brief Retourne le nom de la classe
		*/
	static QString toString() { return QString("CollisionOjMechantSimple"); }

private:
	/**
		*  \fn    void collisionEntre(OjGarde *h, OjPlateforme *p);
		*  \param s Pointeur vers OjMechantSimple
		*  \param p Pointeur vers OjPlateforme
		*  \brief Définit le comportement d'une collision entre un OjGarde et un OjPlateforme
		*/
	void collisionEntre(OjMechantSimple *s, OjPlateforme *p);

};


#endif // COLLISION_OJ_MECHANT_SIMPLE_H
