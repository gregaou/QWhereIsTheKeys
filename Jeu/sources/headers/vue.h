/**
 * \file	    vue.h
 * \brief	    Classe abstraite pour les vues
 * \author    RIT Grégoire
 * \version   1.0
 * \date      11/11/12
 */

#ifndef VUE_H
#define VUE_H

#include <QWidget>
#include <QMessageBox>

/**
 * \class Vue
 * \brief Classe abstraite pour la gestion des vues
 */
class Vue : public QWidget{
	Q_OBJECT
public:
	/**
		*  \brief Constructeur
		*	 \fn    Vue (QWidget *parent)
		*  \param parent Définit le parent de la vue
		*/
	Vue(QWidget *parent) :
		QWidget(parent),
		_qwitk(parent)
	{}

	/**
		*  \brief Destructeur
		*	 \fn    ~Vue ()
		*/
	~Vue(){}

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    static QString toString();
		*/
	static QString toString();

signals:
	/**
		*  \brief Signal pour changer la vue
		*	 \fn    void setVue (QString)
		*/
	void setVue(QString);

protected:
	QWidget *_qwitk; /**< Fenêtre principale */

	/**
		*  \brief Connecte les signaux des éléments de l'interface à
		*  leur fonction associé
		*  \fn virtual void connexionAffichage() = 0
		*/
	virtual void connexionAffichage() = 0;

	virtual void keyPressEvent(QKeyEvent *event) { Q_UNUSED(event) }
	virtual void keyReleaseEvent(QKeyEvent *event) { Q_UNUSED(event) }


};

#endif // VUE_H
