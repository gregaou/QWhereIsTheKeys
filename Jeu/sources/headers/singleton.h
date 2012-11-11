/**
 * \file			singleton.h
 * \brief			Classe mod�le pour la cr�ation de singletons
 * \author    Soci�t� de D�veloppement de Projets Informatique
 * \version   1.0
 * \date      11/11/12
 */

#ifndef SINGLETON_H
#define SINGLETON_H

#include <QDebug>

/**
 * \class Singleton
 * \brief Classe mod�le pour la cr�ation de singletons
 */
template <typename T>
class Singleton
{
protected:
	/**
		*  \brief Constructeur
		*	 \fn    Singleton ()
		*/
	Singleton () {}
	/**
		*  \brief Destructeur
		*	 \fn    Singleton ()
		*/
	~Singleton () {}

public:
	/**
		*  \brief Permet l'obtention de l'instance de la classe T
		*	 \fn    static T *getInstance ()
		*/
	static T *getInstance ()
	{
		if (NULL == _singleton)
			_singleton = new T;

		return (static_cast<T*> (_singleton));
	}

	/**
		*  \brief D�truit le singleton
		*	 \fn    static void kill ()
		*/
	static void kill ()
	{
		if (NULL != _singleton)
		{
			delete _singleton;
			_singleton = NULL;
		}
	}

private:
	static T *_singleton;
};

template <typename T>
T *Singleton<T>::_singleton = NULL;

#endif // SINGLETON_H
