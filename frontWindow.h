#ifndef _3dWindow_inc
#define _3dWindow_inc

#include "subScreen.h"

class FrontWindow : public SubScreen
{
public:
	FrontWindow(BITMAP* parentScreen);
	void draw();
};

#endif