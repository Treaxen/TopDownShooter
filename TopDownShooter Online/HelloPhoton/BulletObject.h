#ifndef  _BULLETOBJECT_H
#define _BULLETOBJECT_H

#include "GameObject.h"

class Bullet : public GameObject
{
public:

	//static ObjectPool<Bullet> BulletPool;
	int IsAlive;

	int Owner;

	float Life;

	Bullet();

	void update(double elapsedTime) override;
};

#endif // ! _BULLETOBJECT_H


