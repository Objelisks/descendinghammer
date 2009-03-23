#include "player.h"
#include "coordinate.h"
#include "gameState.h"
#include "common.h"

Player::Player()
{
	pos = Coordinate(20,20,20);
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
		Coordinate firePos = pos;
		firePos.x += -5+rand()%8;
		firePos.z += -5+rand()%8;
		firePos.y -= 10;

		//Bullet newBullet = Bullet(firePos,1,5,-rand()%10+95,2);
		Bullet newBullet = Bullet(firePos,1,5,-rand()%10+95,2);
		theState()->spawnBullet(newBullet);

		cooldown += 8 + rand()%4;
	}
};