#ifndef COLLISION_OJ_HEROS_H
#define COLLISION_OJ_HEROS_H

#include "sources/headers/collision_oj.h"

class CollisionOjHeros : public CollisionOj
{
public:
	/**
		*  \fn    CollisionOjHeros ()
		*  \brief Constructeur
		*/
	CollisionOjHeros() : CollisionOj("OjHeros") {}

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
	static QString toString() { return QString("CollisionOjHeros"); }

private:
	/**
		*  \fn    void collisionEntre(OjHeros *h, OjPlateforme *p);
		*  \param h Pointeur vers OjHeros
		*  \param p Pointeur vers OjPlateforme
		*  \brief Définit le comportement d'une collision entre un OjHeros et un OjPlateforme
		*/
	void collisionEntre(OjHeros *h, OjPlateforme *p);

};

#endif // COLLISION_OJ_HEROS_H
