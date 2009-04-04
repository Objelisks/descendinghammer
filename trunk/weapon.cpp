#include "weapon.h"
#include "gameState.h"
#include "behaviors.h"

Laser::Laser()
{
	cooldown = 0;
	cooldownMax = 3;
	name = "Laser";
};

void Laser::fire(Coordinate pos)
{
	if(cooldown <= 0)
	{
		theState()->bulletManager.addBullet(Bullet(
			pos.offset(0,-10,10),
			10,
			-5,
			&Behaviors::Straight));
		

		cooldown = cooldownMax;
	}
};

MachineGun::MachineGun()
{
	cooldown = 0;
	cooldownMax = 15;
	name = "MachineGun";
};

void MachineGun::fire(Coordinate pos)
{
	if(cooldown <= 0)
	{
		theState()->bulletManager.addBullet(Bullet(
			pos.offset(0,-10,10),
			25,
			-1.8,
			&Behaviors::Straight));
		

		cooldown = cooldownMax;
	}
};

FlakCannon::FlakCannon()
{
	cooldown = 0;
	cooldownMax = 100;
	name = "FlakCannon";
}

void FlakCannon::fire(Coordinate pos)
{
	if(cooldown <= 0)
	{
		theState()->bulletManager.addBullet(Bullet(
			pos.offset(-10,-10,-10),
			50,
			-1,
			&Behaviors::Straight));
		theState()->bulletManager.addBullet(Bullet(
			pos.offset(-10,-10,10),
			50,
			-1,
			&Behaviors::Straight));
		theState()->bulletManager.addBullet(Bullet(
			pos.offset(10,-10,10),
			50,
			-1,
			&Behaviors::Straight));
		theState()->bulletManager.addBullet(Bullet(
			pos.offset(10,-10,-10),
			50,
			-1,
			&Behaviors::Straight));
		

		cooldown = cooldownMax;
	}
};