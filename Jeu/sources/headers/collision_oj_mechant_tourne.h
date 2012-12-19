/**
 * \file			collision_oj_mechant_tourne.h
 * \brief			gestion des collisions d'un objet jeu méchant tourne
 * \author    MAHE Yannick
 * \version   1.0
 * \date      10/12/2012
 */

#ifndef COLLISION_OJ_MECHANT_TOURNE_H
#define COLLISION_OJ_MECHANT_TOURNE_H



#include "sources/headers/collision_oj.h"

class CollisionOjMechantTourne : public CollisionOj
{
public:
		/**
				*  \fn    CollisionOjMechantTourne ()
				*  \brief Constructeur
				*/
		CollisionOjMechantTourne() : CollisionOj("OjMechantTourne") {}

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
		static QString toString() { return QString("CollisionOjMechantTourne"); }

private:
		/**
				*  \fn    void collisionEntre(OjGarde *h, OjPlateforme *p);
				*  \param s Pointeur vers OjMechantTourne
				*  \param p Pointeur vers OjPlateforme
				*  \brief Définit le comportement d'une collision entre un OjGarde et un OjPlateforme
				*/
		void collisionEntre(OjMechantTourne *s, OjPlateforme *p);

};




#endif // COLLISION_OJ_MECHANT_TOURNE_H
