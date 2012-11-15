#include "sources/headers/vue_factory.h"

Vue* VueFactory::getVue(QString nom, QWidget *parent)
{
	if(nom == "VueAccueil")
		return new VueAccueil(parent);

	else if(nom == "VueProfilNouveau")
		return new VueProfilNouveau(parent);

	else if(nom == "VueProfilCharger")
		return new VueProfilCharger(parent);

	else if(nom == "VueProfilSupprimer")
		return new VueProfilSupprimer(parent);

	else if(nom == "VueMenuJeu")
		return new VueMenuJeu(parent);

	else if(nom == "VueNouveauJeu")
		return new VueNouveauJeu(parent);

	return new VueAccueil(parent);
}
