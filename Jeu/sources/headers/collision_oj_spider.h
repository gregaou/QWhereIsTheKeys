#ifndef COLLISION_OJ_SPIDER_H
#define COLLISION_OJ_SPIDER_H

#include "sources/headers/collision_oj.h"

class CollisionOjSpider : public CollisionOj
{
public:
	/**
		*  \fn    CollisionOjSpider ()
		*  \brief Constructeur
		*/
	CollisionOjSpider() : CollisionOj("OjSpider") {}

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
	static QString toString() { return QString("CollisionOjSpider"); }

private:
	/**
		*  \fn    void collisionEntre(OjSpider *h, OjPlateforme *p);
		*  \param h Pointeur vers OjSpider
		*  \param p Pointeur vers OjPlateforme
		*  \brief Définit le comportement d'une collision entre un OjSpider et un OjPlateforme
		*/
	void collisionEntre(OjSpider *s, OjPlateforme *p);
	/**
		*  \fn    void collisionHeros(OjSpider *s, OjHeros *h);
		*  \param s Pointeur vers OjSpider
		*  \param h Pointeur vers OjHeros
		*  \brief Définit le comportement d'une collision entre un OjSpider et un OjHeros
		*/
	void collisionHeros(OjSpider *s, OjHeros *h);

};
#endif // COLLISION_OJ_SPIDER_H
