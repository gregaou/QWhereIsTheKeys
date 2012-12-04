#ifndef COLLISION_OJ_MECHANT_SIMPLE_H
#define COLLISION_OJ_MECHANT_SIMPLE_H

#include "sources/headers/collision_oj.h"


// VERIFIER LES COMMENTAIRES !!


class CollisionOjMechantSimple : public CollisionOj
{
public:
	/**
		*  \fn    CollisionOjGarde ()
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
		*  \param s Pointeur vers OjGarde
		*  \param p Pointeur vers OjPlateforme
		*  \brief Définit le comportement d'une collision entre un OjGarde et un OjPlateforme
		*/
	void collisionEntre(OjMechantSimple *s, OjPlateforme *p);
	/**
		*  \fn    void collisionHeros(OjGarde *s, OjHeros *h);
		*  \param s Pointeur vers OjGarde
		*  \param h Pointeur vers OjHeros
		*  \brief Définit le comportement d'une collision entre un OjGarde et un OjHeros
		*/
	void collisionHeros(OjMechantSimple *s, OjHeros *h);

};


#endif // COLLISION_OJ_MECHANT_SIMPLE_H
