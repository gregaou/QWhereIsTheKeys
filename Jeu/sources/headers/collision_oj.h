#ifndef COLLISION_OJ_H
#define COLLISION_OJ_H

#include <QString>
#include "sources/headers/objet_jeu.h"

class CollisionOj
{
public:
	CollisionOj(QString name)
	{
			_nomObjet=name;
			_next = 0;
	}

	CollisionOj* setNext(CollisionOj* next)
	{
					_next = next;
					return (_next);
	}

	void collision(ObjetJeu* oj1, ObjetJeu* oj2)
	{
		//todo
		if(oj1->toString() == _name || oj2->toString() == _name)
		{
			gererCollision((oj1->toString() == _name)?oj2:oj1);
		}
		else
		{
			if(!_next)
				_next->collision(oj1, oj2);
		}
	}

	virtual void gererCollision(ObjetJeu* oj) = 0;

private:


protected:
	QString _nomObjet;
	CollisionOj* _next;



};

#endif // COLLISION_OJ_H
