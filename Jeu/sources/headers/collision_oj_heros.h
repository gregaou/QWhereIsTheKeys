#ifndef COLLISION_OJ_HEROS_H
#define COLLISION_OJ_HEROS_H

#include "sources/headers/collision_oj.h"

class CollisionOjHeros : public CollisionOj
{
public:
	CollisionOjHeros() : CollisionOj("OjHeros") {}

	void gererCollision(ObjetJeu* oj1, ObjetJeu* oj2);
	//QString toString() { return QString("CollisionOjHeros"); }

private:
	void collisionEntre(OjHeros *h, OjPlateforme *p);

};

#endif // COLLISION_OJ_HEROS_H
