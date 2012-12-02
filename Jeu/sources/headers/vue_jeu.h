/**
 * \file			vue_jeu.h
 * \brief			Classe vue jeu
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      24/11/12
 */

#ifndef VUE_JEU_H
#define VUE_JEU_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

#include "sources/headers/vue.h"
#include "sources/headers/model_jeu.h"
#include "sources/headers/objet_jeu.h"
#include "sources/headers/oj_plateforme.h"
#include "sources/headers/oj_heros.h"
#include "sources/headers/model_niveau.h"
#include "sources/headers/niveau.h"

#include "sources/headers/collision_oj.h"
#include "sources/headers/collision_oj_heros.h"

/** \namespace Ui
 *
 * Espace de nommage pour les
 * interfaces Qt
 */
namespace Ui {
	class VueJeu;
}

/**
 * \class VueJeu
 * \brief Classe de la vue Jeu
 */
class VueJeu : public Vue
{
	Q_OBJECT

public:
	/**
		*  \brief Constructeur
		*	 \fn    explicit VueJeu (QWidget *parent = 0)
		*  \param parent Définit le parent de la fenêtre
		*/
	explicit VueJeu(QWidget *parent = 0);

	/**
		*  \brief VueJeu
		*	 \fn    ~VueJeu ()
		*
		*  Destructeur de la classe VueJeu
		*/
	~VueJeu();

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    static QString toString();
		*/
	static QString toString();

private slots:
	void collision(ObjetJeu *oj1, ObjetJeu *oj2);

private:
	Ui::VueJeu *_ui; /**< Interface graphique liée à la classe */
	ModelJeu *_mJeu; /**< Modèle de données du jeu */
	ModelNiveau *_mNiveau; /**< Modèle de données des niveaux */
	QGraphicsScene _scene; /**< Scene Graphique */
	QGraphicsView _view; /**< Vue Graphique */

	ObjetJeu *h;

	CollisionOj *cOj;

	void keyPressEvent(QKeyEvent *event);

	void keyReleaseEvent(QKeyEvent *event);

	void timerEvent(QTimerEvent *);

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn void connexionAffichage()
		*/
	void connexionAffichage();
};

#endif // VUE_JEU_H
