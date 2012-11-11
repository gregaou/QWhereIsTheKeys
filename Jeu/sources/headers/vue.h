/**
 * \file			vue.h
 * \brief			Classe abstraite pour les vues
 * \author    Société de Développement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */

#ifndef VUE_H
#define VUE_H

#include <QWidget>

/**
 * \class Vue
 * \brief Classe abstraite pour la gestion des vues
 */
class Vue : public QWidget{

public:

	Vue(QWidget *parent) :
		QWidget(parent){}

	~Vue(){}

	/**
		*  \brief Renvoi le nom de la vue
		*	 \fn    virtual QString toString() = 0;
		*/
	virtual QString toString() = 0;

signals:
	/**
		*  \brief Signal pour changer la vue
		*	 \fn    void setVue (QString)
		*  \param QString Nom de la nouvelle vue
		*/
	void setVue(QString);

protected:

};

#endif // VUE_H
