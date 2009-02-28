#include "coordinate.h"

struct Enemy
{
public:
	Coordinate pos;
	int health;
	void update();
};