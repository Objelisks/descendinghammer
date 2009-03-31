#include "player.h"
#include "coordinate.h"
#include "gameState.h"
#include "common.h"
#include "behaviors.h"

Player::Player()
{
	pos = Coordinate(100,750,0);
	cooldown = 0;
	speed = 0.5;
	intSpeed = 1;
	inversethrustvectoringfuelcoiltoggled = 0;
};

void Player::toggleThrustVectors()
{
	if(inversethrustvectoringfuelcoiltoggled == 0)
	{
		inversethrustvectoringfuelcoiltoggled = 1;
	}
	else
	{
		inversethrustvectoringfuelcoiltoggled = 0;
	}
};

void Player::update()
{
	if(cooldown > 0)
	{
		cooldown--;
	}
	if(intSpeed < 30)
	{
		intSpeed++;
	}
	if(intSpeed > 30)
	{
		intSpeed--;
	}
};

void Player::moveForward()
{
	if(pos.y > 0){
		pos.y = pos.y - speed;
	}
	if(intSpeed < 60)
	intSpeed+=2;
};

void Player::moveBackward()
{
	if(pos.y < theState()->world.y){
		pos.y = pos.y + speed;
	}
	if(intSpeed > 15)
	intSpeed-=2;
};

void Player::moveUp()
{
	if(pos.z > 0){
		pos.z = pos.z - speed;
	}
};

void Player::moveDown()
{
	if(pos.z < theState()->world.z){
		pos.z = pos.z + speed;
	}
};

void Player::moveLeft()
{
	if(pos.x > 0){
		pos.x = pos.x - speed;
	}
};

void Player::moveRight()
{
	if(pos.x < theState()->world.x){
		pos.x = pos.x + speed;
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
		Bullet newBullet1 = Bullet(firePos1,100,5,-2,&Behaviors::Straight);
		theState()->spawnBullet(newBullet1);

		//Bullet newBullet2 = Bullet(firePos2,100,5,2,&Behaviors::Bullet);
		//theState()->spawnBullet(newBullet2);

		cooldown += 5 + rand()%4;
	}
};