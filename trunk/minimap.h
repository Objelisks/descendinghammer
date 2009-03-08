//bitmap
//sprites
//palette
//positions
//status

#ifndef _minimap_inc
#define _minimap_inc

#include "subScreen.h"

class MiniMap : public SubScreen
{
public:
	MiniMap(BITMAP* parentScreen);
	void draw();
};

#endif