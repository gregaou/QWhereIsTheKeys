/**
 * \file			collision_oj.h
 * \brief			Chaîne de responsabilité gérant les collisions
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      01/12/12
 */

#ifndef COLLISION_OJ_H
#define COLLISION_OJ_H

#include <QString>
#include "sources/headers/objet_jeu.h"
#include "sources/headers/oj_heros.h"
#include "sources/headers/oj_plateforme.h"
#include "sources/headers/oj_mechant_simple.h"
#include "sources/headers/oj_mechant_tourne.h"
#include "sources/headers/oj_clef.h"
#include "sources/headers/oj_fix_anime.h"
/**
 * \class CollisionOj
 * \brief Structure de la chaîne de responsabilité gérant les collisions
 */
class CollisionOj
{
public:
	/**
		*  \fn    CollisionOj ( QString name )
		*  \param name Nom de l'objet �  reconnaitre
		*  \brief Constructeur
		*/
	CollisionOj(QString name) : _nomObjet(name), _next(0) {}

	/**
		*  \fn    CollisionOj* setNext ( CollisionOj* next )
		*  \param next élément suivant
		*  \brief Set l'élément suivant de la chaîne de responsabilité
		*/
	CollisionOj* setNext(CollisionOj* next)
	{
		if(_next)
			_next->setNext(next);
		else
			_next = next;
		return next;
	}

	/**
		*  \fn    virtual void gererCollision(ObjetJeu* oj1, ObjetJeu* oj2) = 0
		*  \param oj1 premier ObjetJeu
		*  \param oj2 deuxieme ObjetJeu
		*  \brief Gère la collision entre deux ObjetJeu
		*/
	virtual void gererCollision(ObjetJeu* oj1, ObjetJeu* oj2) = 0;

	/**
		*  \fn    static QString toString ()
		*  \brief Retourne le nom de la classe
		*/
	static QString toString() { return QString("CollisionOj"); }

public slots:

	/**
		*  \fn    void collision(ObjetJeu* oj1, ObjetJeu* oj2)
		*  \param oj1 premier ObjetJeu
		*  \param oj2 deuxieme ObjetJeu
		*  \brief Vérifie le nom des objets et traite la collision si elle doit la traiter, sinon elle la passe �  la classe suivante
		*/
	void collision(ObjetJeu* oj1, ObjetJeu* oj2)
	{
		if(oj1->toString() == _nomObjet || oj2->toString() == _nomObjet)
		{
			gererCollision((oj1->toString() == _nomObjet)?oj1:oj2,
										 (oj1->toString() == _nomObjet)?oj2:oj1);
		}
		else
		{
			if(_next)
				_next->collision(oj1, oj2);
		}
	}

protected:
	QString _nomObjet;/**< Défini le nom de l'objet jeu �  traiter */
	CollisionOj* _next;/**< Défini la classe suivante qui traitera l'objet si celle ci ne peut pas la traiter */



};

#endif // COLLISION_OJ_H
