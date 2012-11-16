#include "sources/headers/vue_factory.h"

Vue* VueFactory::getVue(QString nom, QWidget *parent)
{
	if(nom == VueAccueil::toString())
		return new VueAccueil(parent);

	else if(nom == VueProfilNouveau::toString())
		return new VueProfilNouveau(parent);

	else if(nom == VueProfilCharger::toString())
		return new VueProfilCharger(parent);

	else if(nom == VueProfilSupprimer::toString())
		return new VueProfilSupprimer(parent);

	else if(nom == VueMenuJeu::toString())
		return new VueMenuJeu(parent);

	else if(nom == VueNouveauJeu::toString())
		return new VueNouveauJeu(parent);

	return new VueAccueil(parent);
}
