#include "coordinate.h"

struct Bullet
{
public:
	Bullet() {pos = Coordinate(0,0);};
	Coordinate pos;
	int dmg;
};