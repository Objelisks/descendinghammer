#include "common.h"
#include "string"
#include "sstream"

std::string toString(int i)
{
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();
	return s;
};

volatile int frameRate = 0;

double rad(double deg)
{
	return deg*PI/180.0;
};

double deg(double rad)
{
	return rad*180.0/PI;
};

DrawableWrapper::DrawableWrapper(int _x, int _y, int _z, int _s, bool _fill, int _color)
{
	x=_x;
	y=_y;
	z=_z;
	s=_s;
	fill=_fill;
	color=_color;
};