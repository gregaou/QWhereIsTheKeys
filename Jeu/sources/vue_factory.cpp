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

	else if(nom == VueJeuMenu::toString())
		return new VueJeuMenu(parent);

	else if(nom == VueJeuNouveau::toString())
		return new VueJeuNouveau(parent);

	else if(nom == VueJeuCharger::toString())
		return new VueJeuCharger(parent);

	else if(nom == VueJeu::toString())
		return new VueJeu(parent);

	else if(nom == VueJeuNiveauTermine::toString())
		return new VueJeuNiveauTermine(parent);

	else if(nom == VueCredit::toString())
		return new VueCredit(parent);

	return new VueAccueil(parent);
}
