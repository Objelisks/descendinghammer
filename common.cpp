#include "common.h"

volatile int frameRate = 0;

double rad(double deg)
{
	return deg*PI/180.0;
};

double deg(double rad)
{
	return rad*180.0/PI;
};

DrawableWrapper::DrawableWrapper(int _x, int _y, int _z, double _s, BITMAP* img, int c)
{
	x=_x;
	y=_y;
	z=_z;
	s=_s;
	color=c;
	image=img;
};