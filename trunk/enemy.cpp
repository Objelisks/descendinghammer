#include "enemy.h"
#include "coordinate.h"
#include "gameState.h"
#include "common.h"

Enemy::Enemy()
{
	pos = Coordinate(rand()%theState()->world.x,0,rand()%theState()->world.z);
	health = 100;
	move = 0;
	life = 1;
	speed = 1;
	image = theState()->resources.images["ship"+toString(rand()%3+1)];
	size = image->w/10;
	dead = false;
};

Enemy::Enemy(void (*m)(Coordinate* ,int, double))
{
	move = m;
	pos = Coordinate(rand()%theState()->world.x,0,rand()%theState()->world.z);
	health = 100;
	life = 1;
	speed = 1;
	image = theState()->resources.images["ship"+toString(rand()%3+1)];
	size = image->w/10;
	dead = false;
};

void Enemy::update()
{
	(*move)(&pos, life, speed);

	int dmg = theState()->collideEnemyWithBullets(*this);

	health = health - dmg;

	life++;
	if(pos.y > theState()->world.y || health <= 0)
	{
		if(pos.y > theState()->world.y && theState()->humansToKill < 4294967294)
		{
			theState()->humansToKill+=100000;
		}
		else
		{
			theState()->addText("Enemy destroyed!");
			theState()->score++;
			theState()->addEffect(Effect(theState()->resources.effects["Explode"],pos,5,false));
		}
		dead = true;
	}
};