#include "enemy.h"
#include "coordinate.h"
#include "allegro.h"

Enemy::Enemy()
{
	pos = Coordinate(rand()%SCREEN_W,0,0);
	health = 100;
};

Enemy::Enemy(double (*xM)(int), double (*yM)(int))
{
	xMove = xM;
	yMove = yM;
	pos = Coordinate(rand()%SCREEN_W,0,0);
	health = 100;
	life = 0;
};

void Enemy::update()
{
	pos.x = pos.x + (*xMove)(life);
	pos.y = pos.y + (*yMove)(life);
	life++;
};