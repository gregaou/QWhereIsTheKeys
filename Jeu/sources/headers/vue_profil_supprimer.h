/**
 * \file	    vue_profil_supprimer.h
 * \brief	    Classe vue supprimer profil
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      12/11/12
 */

#ifndef VUE_PROFIL_SUPPRIMER_H
#define VUE_PROFIL_SUPPRIMER_H

#include "sources/headers/vue_profil.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueProfilSupprimer;
}

/**
 * \class VueProfilSupprimer
 * \brief Classe de la vue supprimer profil
 */
class VueProfilSupprimer : public VueProfil
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueProfilSupprimer (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueProfilSupprimer(QWidget *parent = 0);

	/**
		*  \brief Destructeur
		*	 \fn    ~VueProfilSupprimer ()
		*/
	~VueProfilSupprimer();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    QString toString();
		*/
	QString toString();

private slots:
	/**
		*  \brief Action lorsque l'on clic sur le bouton retour
		*	 \fn    void onClicBoutonRetour();
		*/
	void onClicBoutonRetour();


private:
	Ui::VueProfilSupprimer *_ui; /**< Interface graphique liée à la classe */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
};

#endif // VUE_PROFIL_SUPPRIMER_H
