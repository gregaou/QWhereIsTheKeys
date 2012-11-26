#ifndef VUE_JEU_CHARGER_H
#define VUE_JEU_CHARGER_H

#include "sources/headers/vue.h"
#include "sources/headers/vue_profil.h"
#include "sources/headers/vue_jeu_menu.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueJeuCharger;
}

/**
 * \class VueJeuCharger
 * \brief Classe de la Vue Jeu Charger
 */
class VueJeuCharger : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueJeuCharger (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueJeuCharger(QWidget *parent = 0);

	/**
		*  \brief VueJeuCharger
		*	 \fn    ~VueJeuCharger ()
		*
		*  Destructeur de la classe VueJeuCharger
		*/
	~VueJeuCharger();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    static QString toString();
		*/
	static QString toString();

private slots:
	/**
		*  \brief Permet de faire un retour
		*	 \fn    void onClicBoutonRetour()
		*/
	void onClicBoutonRetour();
	/**
		*  \brief Charge le niveau selectionné
		*	 \fn    void onclicBoutonNiveau(int choixNiveau)
		*	 \param choixNiveau définit le niveau choisi
		*/
	void onclicBoutonNiveau(int choixNiveau);

private:
	Ui::VueJeuCharger *_ui; /**< Interface graphique liée à la classe */
	ModelJeu *_mJeu;					/**< Modèle de données du jeu */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
	/**
		*  \brief Actualise la liste des niveaux débloqués
		*  \fn void actualiseListeNiveaux
		*/
	void actualiseListeNiveaux();
};


#endif // VUE_JEU_CHARGER_H
