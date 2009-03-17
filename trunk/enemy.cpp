#include "enemy.h"
#include "coordinate.h"
#include "allegro.h"

Enemy::Enemy()
{
	pos = Coordinate(rand()%SCREEN_W,0,0);
	health = 100;
};

Enemy::Enemy(void (*m)(Coordinate* ,int))
{
	move = m;
	pos = Coordinate(rand()%SCREEN_W,0,0);
	health = 100;
	life = 1;
	dead = false;
};

void Enemy::update()
{
	(*move)(&pos, life);
	life++;
};