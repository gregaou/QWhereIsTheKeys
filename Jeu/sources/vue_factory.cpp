#include "sources/headers/vue_factory.h"

Vue* VueFactory::getVue(QString nom)
{
	return new VueAccueil();
}
