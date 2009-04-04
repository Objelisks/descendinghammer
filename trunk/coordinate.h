#ifndef _coordinate_inc
#define _coordinate_inc

class Coordinate{
public:
	Coordinate();
	Coordinate(double a, double b, double c);
	Coordinate offset(double a, double b, double c);
	double x;
	double y;
	double z;
};

float distance(Coordinate p1, Coordinate p2);

#endif