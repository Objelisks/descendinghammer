#ifndef _frontWindow_inc
#define _frontWindow_inc

#include "subScreen.h"

class FrontWindow : public SubScreen
{
public:
	FrontWindow(BITMAP* parentScreen);
	FrontWindow(BITMAP* parentScreen,int w, int h);
	void draw();
private:
	int colors[9];
	int width;
	int height;
	int fovX;
	int fovZ;
	int fogDist;
};

#endif