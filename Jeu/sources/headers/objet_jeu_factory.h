/**
 * \file	    objet_jeu_factory.h
 * \brief			Classe fabrique pour les objets jeu
 * \author    BUISSON Fabien, RIT Grégoire
 * \version   6.0
 * \date      17/12/12
 */

#include "sources/headers/singleton.h"
#include "sources/headers/objet_jeu.h"
#include "sources/headers/objet_jeu_mobile.h"
#include "sources/headers/oj_clef.h"
#include "sources/headers/oj_fix_anime.h"
#include "sources/headers/oj_heros.h"
#include "sources/headers/oj_mechant_simple.h"
#include "sources/headers/oj_mechant_tourne.h"
#include "sources/headers/oj_plateforme.h"

#ifndef OBJET_JEU_FACTORY_H
#define OBJET_JEU_FACTORY_H

#define SEP_FIC_NIV "##"

class ObjetJeuFactory : public Singleton<ObjetJeuFactory>
{
	friend class Singleton<ObjetJeuFactory>;

private:
	/**
		*  \brief Constructeur
		*	 \fn    ObjetJeuFactory ()
		*/
	ObjetJeuFactory ()	 {}
	/**
		*  \brief Destructeur
		*	 \fn    ~ObjetJeuFactory ()
		*/
	~ObjetJeuFactory () { }

public:
	/**
		*  \brief Renvoi l'instance d'un objet jeu en fonction d'un QString
		*	 \fn    static ObjetJeu* getObjetJeu(QString nom);
		*	 \param nom Décris le nom du type de l'objet jeu à renvoyer
		*/
	static ObjetJeu* getObjetJeu(QString line);

private:

};

#endif // OBJET_JEU_FACTORY_H
