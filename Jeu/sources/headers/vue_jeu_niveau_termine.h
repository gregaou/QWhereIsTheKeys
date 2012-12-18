/**
 * \file	    vue_jeu_niveau_termine.h
 * \brief	    Classe vue jeu niveau terminé
 * \author    BOSSOLA Grégory
 * \version   6.0
 * \date      18/12/12
 */
#ifndef VUE_JEU_NIVEAU_TERMINE_H
#define VUE_JEU_NIVEAU_TERMINE_H

#include "sources/headers/vue.h"
#include "sources/headers/vue_jeu_menu.h"
#include "sources/headers/model_jeu.h"
#include "sources/headers/model_niveau.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueJeuNiveauTermine;
}
/**
 * \class VueJeuPause
 * \brief Classe de la vue jeu pause
 */
class VueJeuNiveauTermine : public Vue
{
	Q_OBJECT
private:
	Ui::VueJeuNiveauTermine* _ui; /**< Interface graphique liée à la classe */
	ModelJeu *_mJeu; /**< Modèle de données du jeu */
	ModelNiveau *_mNiveau; /**< Modèle de données des niveaux */
	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
private slots:
	/**
		*  \brief Permet de faire un retour au menu du jeu
		*	 \fn    void onClicBoutonRetourMenu()
		*/
	void onClicBoutonRetourMenu();
	/**
		*  \brief Charge le niveau selectionné
		*	 \fn    void onclicBoutonNiveauSuivant()
		*	 \param choixNiveau définit le niveau choisi
		*/
	void onclicBoutonNiveauSuivant();
public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueJeuNiveauTermine(QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueJeuNiveauTermine(QWidget *parent = 0);
	/**
		*  \brief VueJeuNiveauTermine
		*	 \fn    ~VueJeuNiveauTermine ()
		*
		*  Destructeur de la classe VueJeuNiveauTermine
		*/
	~VueJeuNiveauTermine();
	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    static QString toString();
		*/
	static QString toString();
};
#endif // VUE_JEU_NIVEAU_TERMINE_H
