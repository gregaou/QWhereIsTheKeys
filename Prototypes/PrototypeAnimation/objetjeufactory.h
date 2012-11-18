#ifndef OBJETJEUFACTORY_H
#define OBJETJEUFACTORY_H

#include "singleton.h"

class ObjetJeuFactory : public Singleton<ObjetJeuFactory>
{
	friend class Singleton<ObjetJeuFactory>;
public:
	ObjetJeuFactory();
};

#endif // OBJETJEUFACTORY_H
