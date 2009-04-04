#ifndef _weaponMeter_inc
#define _weaponMeter_inc

#include "string"
#include "allegro.h"
#include "vector"
#include "subScreen.h"

class WeaponVisual
{
public:
	WeaponVisual(std::string n, int* cool, int coolMax, RLE_SPRITE* img);
	std::string name;
	int* cooldown;
	int cooldownMax;
	RLE_SPRITE* image;
};

class WeaponMeter : public SubScreen
{
public:
	WeaponMeter(BITMAP* parentScreen, int x, int y);
	std::vector<WeaponVisual> weapons;
	void draw();
};

#endif