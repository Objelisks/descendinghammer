#ifndef _ship_inc
#define _ship_inc

#include "coordinate.h"

class Ship
{
public:
	Ship();
	Coordinate pos;
	int X();
	int Y();
	int Z();
};

#endif