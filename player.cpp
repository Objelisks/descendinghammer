#include "player.h"
#include "coordinate.h"
#include "gameState.h"
#include "common.h"
#include "behaviors.h"

Player::Player()
{
	pos = Coordinate(500,1000,0);
	cooldown = 0;
};

void Player::moveForward(int amt)
{
	if(pos.y > 0){
		pos.y = pos.y - 1;
	}
};

void Player::moveBackward(int amt)
{
	if(pos.y < theState()->world.y){
		pos.y = pos.y + 1;
	}
};

void Player::moveUp(int amt)
{
	if(pos.z > 0){
		pos.z = pos.z - 1;
	}
};

void Player::moveDown(int amt)
{
	if(pos.z < theState()->world.z){
		pos.z = pos.z + 1;
	}
};

void Player::moveLeft(int amt)
{
	if(pos.x > 0){
		pos.x = pos.x - 1;
	}
};

void Player::moveRight(int amt)
{
	if(pos.x < theState()->world.x){
		pos.x = pos.x + 1;
	}
};

void Player::fire()
{
	if(cooldown == 0)
	{
		Coordinate firePos1 = pos;
		//firePos1.x += 1;
		firePos1.y -= 10;
		firePos1.z += 1;

		//Coordinate firePos2 = pos;
		//firePos2.x -= 1;
		//firePos2.y -= 30;

		//Bullet newBullet = Bullet(firePos,1,5,-rand()%10+95,2);
		Bullet newBullet1 = Bullet(firePos1,100,5,2,&Behaviors::Bullet);
		theState()->spawnBullet(newBullet1);

		//Bullet newBullet2 = Bullet(firePos2,100,5,2,&Behaviors::Bullet);
		//theState()->spawnBullet(newBullet2);

		cooldown += 8 + rand()%4;
	}
};