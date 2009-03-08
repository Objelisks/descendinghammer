
#ifndef _coordinate_inc
#define _coordinate_inc

class Coordinate{
public:
	Coordinate();
	Coordinate(int a, int b, int c);
	void setX(int a);
	void setY(int b);
	void setZ(int c);
	int x;
	int y;
	int z;
};

#endif