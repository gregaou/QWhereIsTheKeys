/**
 * \file	    vue_profil_charger.h
 * \brief	    Classe abstraite pour les vues profil
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      12/11/12
 */

#ifndef VUE_PROFIL_H
#define VUE_PROFIL_H

#include "sources/headers/vue.h"


/**
 * \class VueProfil
 * \brief Classe abstraite pour les vues profil
 */
class VueProfil : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueProfil (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueProfil(QWidget *parent = 0) :
		Vue(parent) {}
	/**
		*  \brief Destructeur
		*	 \fn    ~VueProfil ()
		*/
	~VueProfil() {}

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    QString toString();
		*/
	virtual QString toString() =0;

protected slots:
	/**
		*  \brief Action lorsque l'on clic sur le bouton annuler
		*	 \fn    void onClicBoutonAnnuler();
		*/
	virtual void onClicBoutonAnnuler() {}

	/**
		*  \brief Action lorsque l'on clic sur le bouton retour
		*	 \fn    virtual void onClicBoutonRetour();
		*/
	virtual void onClicBoutonRetour() {}


protected:

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	virtual void connexionAffichage() = 0;
};

#endif // VUE_PROFIL_H
