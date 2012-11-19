#ifndef OBJETJEUFACTORY_H
#define OBJETJEUFACTORY_H

#include "singleton.h"
#include "objet_jeu.h"

class ObjetJeuFactory : public Singleton<ObjetJeuFactory>
{
	friend class Singleton<ObjetJeuFactory>;
private:
	ObjetJeuFactory();
	~ObjetJeuFactory();

public:
	static ObjetJeu* getObjetJeu(QString nom);
};

#endif // OBJETJEUFACTORY_H
