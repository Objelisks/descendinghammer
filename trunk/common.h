#ifndef _common_inc
#define _common_inc

#include "string"

#define PI 3.14159265

std::string toString(int i);
extern volatile int frameRate;
double rad(double deg);
double deg(double rad);

struct DrawableWrapper
{
public:
	DrawableWrapper(int x, int y, int z, int s, bool fill, int color);
	int x;
	int y;
	int z;
	int s;
	bool fill;
	int color;
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