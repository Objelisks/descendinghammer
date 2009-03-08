//bitmap
//sprites
//palette
//positions
//status

#ifndef _minimap_inc
#define _minimap_inc

#include "subScreen.h"
#include "allegro.h"

class MiniMap : public SubScreen
{
public:
	MiniMap(BITMAP* parentScreen);
	void draw();
private:
	int colors[7];
};

#endif