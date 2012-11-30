#ifndef COLLISION_OJ_H
#define COLLISION_OJ_H

#include <QString>
#include "sources/headers/objet_jeu.h"
#include "sources/headers/oj_heros.h"
#include "sources/headers/oj_plateforme.h"

class CollisionOj :
{
	Q_OBJECT
public:
	CollisionOj(QString name) : _nomObjet(name), _next(0) {}

	CollisionOj* setNext(CollisionOj* next)
	{
		_next = next;
		return (_next);
	}

	virtual void gererCollision(ObjetJeu* oj1, ObjetJeu* oj2) = 0;
	static QString toString();

public slots:
	void collision(ObjetJeu* oj1, ObjetJeu* oj2)
	{
		//todo
		if(oj1->toString() == _nomObjet || oj2->toString() == _nomObjet)
		{
			gererCollision((oj1->toString() == _nomObjet)?oj2:oj1,
										 (oj1->toString() == _nomObjet)?oj1:oj2);
		}
		else
		{
			if(!_next)
				_next->collision(oj1, oj2);
		}
	}

protected:
	QString _nomObjet;
	CollisionOj* _next;



};

#endif // COLLISION_OJ_H
