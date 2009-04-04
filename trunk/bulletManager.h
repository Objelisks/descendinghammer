#ifndef _bulletManager_inc
#define _bulletManager_inc

#include "bullet.h"
#include "list"

class BulletManager{
public:
	BulletManager();

	std::list<Bullet> bullets;	

	void addBullet(Bullet b);
	void moveAll();
};

#endif