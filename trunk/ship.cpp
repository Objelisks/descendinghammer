#include "ship.h"
#include "coordinate.h"

Ship::Ship()
{
	pos = Coordinate();
};

int Ship::X()
{
	return pos.x;
};

int Ship::Y()
{
	return pos.y;
};

int Ship::Z()
{
	return pos.z;
};