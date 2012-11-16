/**
 * \file	    vue_profil_charger.h
 * \brief	    Classe abstraite pour les vues profil
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      12/11/12
 */

#ifndef VUE_PROFIL_H
#define VUE_PROFIL_H

#include <QSortFilterProxyModel>

#include "sources/headers/vue.h"
#include "sources/headers/model_profil.h"


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
		Vue(parent),
		_profils(ModelProfil::getInstance()){}
	/**
		*  \brief Destructeur
		*	 \fn    ~VueProfil ()
		*/
	~VueProfil() {}

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    static QString toString();
		*/
	static QString toString();

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

	ModelProfil *_profils; /**< Modèle des données du profil */

	/**
		*  \brief Charge les données des profils dans la liste
		*  \fn virtual void chargerDonnees()
		*/
	virtual void chargerDonnees() {}
};

#endif // VUE_PROFIL_H
