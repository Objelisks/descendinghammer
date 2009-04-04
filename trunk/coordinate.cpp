#include "coordinate.h"
#include "common.h"
#include "string"
#include "cmath"

Coordinate::Coordinate() {x=0;y=0;z=0;};
Coordinate::Coordinate(double a, double b, double c) {x=a;y=b;z=c;};
Coordinate Coordinate::offset(double a, double b, double c)
{
	return Coordinate(x+a,y+b,z+c);
};

float distance(Coordinate p1, Coordinate p2)
{
	return sqrtf((float)(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)+pow(p1.z-p2.z,2)));
};