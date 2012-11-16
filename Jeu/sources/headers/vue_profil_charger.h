/**
 * \file	    vue_profil_charger.h
 * \brief	    Classe vue charger nouveau profil
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      12/11/12
 */

#ifndef VUE_PROFIL_CHARGER_H
#define VUE_PROFIL_CHARGER_H

#include "sources/headers/vue_profil.h"
#include "sources/headers/vue_accueil.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueProfilCharger;
}

/**
 * \class VueProfilCharger
 * \brief Classe de la vue charger profil
 */
class VueProfilCharger : public VueProfil
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueProfilCharger (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueProfilCharger(QWidget *parent = 0);

	/**
		*  \brief Destructeur
		*	 \fn    ~VueProfilCharger ()
		*
		*  Destructeur de la classe VueProfilCharger
		*/
	~VueProfilCharger();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    static QString toString();
		*/
	static QString toString();

private slots:
	/**
		*  \brief Action lorsque l'on clic sur le bouton annuler
		*	 \fn    void onClicBoutonAnnuler();
		*/
	void onClicBoutonAnnuler();

	/**
		*  \brief Action lorsque l'on clic sur le bouton charger
		*	 \fn    void onClicBoutonValider();
		*/
	void onClicBoutonValider();


private:
	Ui::VueProfilCharger *_ui; /**< Interface graphique liée à la classe */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();

	/**
		*  \brief Charge les données des profils dans la liste
		*  \fn void chargerDonnees()
		*/
	void chargerDonnees();
};

#endif // VUE_PROFIL_CHARGER_H
