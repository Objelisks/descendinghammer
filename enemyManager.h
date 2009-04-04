#ifndef _enemyManager_inc
#define _enemyManager_inc

#include "enemy.h"
#include "list"

class EnemyManager{
public:
	EnemyManager();
	
	std::list<Enemy> enemies;	

	void addEnemy(Enemy e);
	void moveAll();
	void collideEnemyWithBullets(Enemy e);
};

#endif