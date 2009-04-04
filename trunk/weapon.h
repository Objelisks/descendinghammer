#ifndef _weapon_inc
#define _weapon_inc

#include "coordinate.h"
#include "string"

class Weapon
{
public:
	virtual void fire(Coordinate pos){};
	int cooldown;
	int cooldownMax;
	std::string name;
};


class Laser : public Weapon {
public:
	Laser();
	void fire(Coordinate pos);
};

class MachineGun : public Weapon {
public:
	MachineGun();
	void fire(Coordinate pos);
};

class FlakCannon : public Weapon {
public:
	FlakCannon();
	void fire(Coordinate pos);
};

#endif