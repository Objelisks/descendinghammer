#include "enemy.h"
#include "coordinate.h"
#include "gameState.h"

Enemy::Enemy()
{
	pos = Coordinate(rand()%theState()->world.x,0,rand()%theState()->world.z);
	health = 100;
	move = 0;
	life = 1;
	dead = false;
};

Enemy::Enemy(void (*m)(Coordinate* ,int))
{
	move = m;
	pos = Coordinate(rand()%theState()->world.x,0,rand()%200);
	health = 100;
	life = 1;
	dead = false;
};

void Enemy::update()
{
	(*move)(&pos, life);
	life++;
	if(pos.y > theState()->world.y)
	{
		dead = true;
	}
};