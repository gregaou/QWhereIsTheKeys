/**
 * \file	  vue_factory.h
 * \brief	  Classe fabrique pour les vues
 * \author    Sociétéde Développement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */

#ifndef VUE_FACTORY_H
#define VUE_FACTORY_H

#include "sources/headers/singleton.h"
#include "sources/headers/vue.h"
#include "sources/headers/vue_accueil.h"
#include "sources/headers/vue_profil_nouveau.h"
#include "sources/headers/vue_profil_charger.h"
#include "sources/headers/vue_profil_supprimer.h"

/**
 * \class VueFactory
 * \brief Classe fabrique pour la gestion des vues
 */
class VueFactory : public Singleton<VueFactory>
{
	friend class Singleton<VueFactory>;

private:
	/**
		*  \brief Constructeur
		*	 \fn    VueFactory ()
		*/
	VueFactory ()	 {}
	/**
		*  \brief Destructeur
		*	 \fn    ~VueFactory ()
		*/
	~VueFactory () { }

public:
	/**
		*  \brief Renvoi l'instance d'une vue en fonction d'un QString
		*	 \fn    static Vue* getVue(QString nom, QWidget *parent = 0);
		*	 \param nom Décris le nom du type de la Vue à renvoyer
		*  \param parent Décris le parent de la vue que l'on va créer
		*/
	static Vue* getVue(QString nom, QWidget *parent);

private:

};

#endif // VUE_FACTORY_H
