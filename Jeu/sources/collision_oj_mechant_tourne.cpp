#include "sources/headers/collision_oj_mechant_tourne.h"


void CollisionOjMechantTourne::gererCollision(ObjetJeu *oj1, ObjetJeu *oj2)
{
		OjMechantTourne *s = dynamic_cast<OjMechantTourne*>(oj1);
		if(oj2->toString() == "OjPlateforme")
		{
				OjPlateforme *p = dynamic_cast<OjPlateforme*>(oj2);
				collisionEntre(s,p);
		}

}

void CollisionOjMechantTourne::collisionEntre(OjMechantTourne *h, OjPlateforme *p)
{

		if(h->getPlateforme() != 0 && h->getPlateforme()!=p)
				return;

		h->setPlateforme(p);

		if(!(h->getDeplacement()))
		{
			h->gauche();
		}
		else
		{
			h->droite();
		}

}


