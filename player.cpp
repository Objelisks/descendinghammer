#include "player.h"
#include "coordinate.h"
#include "gameState.h"
#include "common.h"
#include "weapon.h"
#include "behaviors.h"
#include "vector"
#include "boost/ptr_container/ptr_vector.hpp"

Player::Player()
{
	pos = Coordinate(100,750,0);
	speed = 0.5;
	intSpeed = 1;
	direction = 90;
	inversethrustvectoringfuelcoiltoggled = 0;
	currentWeapon = 0;
	weapons = boost::ptr_vector<Weapon>();
	weapons.insert(weapons.end(), new MachineGun());
	weapons.insert(weapons.end(), new Laser());
	weapons.insert(weapons.end(), new FlakCannon());
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
	for(boost::ptr_vector<Weapon>::iterator iter=weapons.begin(); iter != weapons.end(); iter++)
	{
		if(iter->cooldown > 0)
		{
			iter->cooldown--;
		}
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
	weapons[currentWeapon].fire(pos);
};

void Player::switchWeapon()
{
	if((unsigned int)currentWeapon+1 < weapons.size())
	{
		currentWeapon++;
	}
	else
	{
		currentWeapon = 0;
	}
};