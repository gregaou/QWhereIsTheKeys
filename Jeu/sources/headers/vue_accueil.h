/**
 * \file	    vue_accueil.h
 * \brief	    Classe vue accueil
 * \author    RIT Grégoire
 * \version   1.0
 * \date      11/11/12
 */

#ifndef VUE_ACCUEIL_H
#define VUE_ACCUEIL_H

#include "sources/headers/vue.h"
#include "sources/headers/vue_profil_nouveau.h"
#include "sources/headers/vue_profil_charger.h"
#include "sources/headers/vue_profil_supprimer.h"
#include "sources/headers/vue_credit.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueAccueil;
}

/**
 * \class VueAccueil
 * \brief Classe de la vue accueil
 */
class VueAccueil : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueAccueil (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueAccueil(QWidget *parent = 0);

	/**
		*  \brief VueAccueil
		*	 \fn    ~VueAccueil ()
		*
		*  Destructeur de la classe VueAccueil
		*/
	~VueAccueil();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    QString toString();
		*/
	static QString toString();

private slots:
	/**
		*  \brief Action lorsque l'on clic sur le bouton nouveau profil
		*	 \fn    void onClicBoutonNouveauProfil();
		*/
	void onClicBoutonNouveauProfil();
	/**
		*  \brief Action lorsque l'on clic sur le bouton charger profil
		*	 \fn    void onClicBoutonChargerProfil();
		*/
	void onClicBoutonChargerProfil();
	/**
		*  \brief Action lorsque l'on clic sur le bouton supprimer profil
		*	 \fn    void onClicBoutonSupprimerProfil();
		*/
	void onClicBoutonSupprimerProfil();

	/**
		*  \brief Action lorsque l'on clic sur le bouton crédits
		*	 \fn    void onClicBoutonCredit();
		*/
	void onClicBoutonCredit();

private:
	Ui::VueAccueil *_ui; /**< Interface graphique liée à la classe */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
};

#endif // VUE_ACCUEIL_H
