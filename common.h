#ifndef _common_inc
#define _common_inc

#include "string"
#include "sstream"
#include "allegro.h"

#define PI 3.14159265

template <class T>
std::string toString(T i)
{
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();
	return s;
};
extern volatile int frameRate;
double rad(double deg);
double deg(double rad);

struct DrawableWrapper
{
public:
	DrawableWrapper(int x, int y, int z, double s, BITMAP* img, int color);
	int x;
	int y;
	int z;
	double s;
	int color;
	BITMAP* image;
};

class DrawableComp
{
public:
  DrawableComp(){};
  bool operator() (const DrawableWrapper& lhs, const DrawableWrapper& rhs) const
  {
	  return (lhs.z>rhs.z);
  }
};

#endif