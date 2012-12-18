/**
 * \file	    vue_credit.h
 * \brief	    Classe vue credit
 * \author    RIT Grégoire
 * \version   1.0
 * \date      18/12/12
 */


#ifndef VUE_CREDIT_H
#define VUE_CREDIT_H

#include "sources/headers/vue.h"
#include "sources/headers/vue_accueil.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueCredit;
}

/**
 * \class VueCredit
 * \brief Classe de la vue credit
 */
class VueCredit : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueCredit (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueCredit(QWidget *parent = 0);

	/**
		*  \brief VueCredit
		*	 \fn    ~VueCredit ()
		*
		*  Destructeur de la classe VueCredit
		*/
	~VueCredit();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    static QString toString();
		*/
	static QString toString();

private slots:
	/**
		*  \brief Action lorsque l'on clic sur le bouton retour menu
		*	 \fn    void onClicBoutonRetourMenu();
		*/

	void onClicBoutonRetourMenu();

private:
	Ui::VueCredit *_ui; /**< Interface graphique liée à la classe */
	ModelJeu *_mJeu; /**< Modêle de données du jeu */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associée
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
};

#endif // VUE_JEU_MENU_H

