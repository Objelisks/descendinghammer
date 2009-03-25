#ifndef _frontWindow_inc
#define _frontWindow_inc

#include "subScreen.h"
#include "common.h"
#include "queue"
#include "functional"

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
	int fovX;//per side
	int fovY;//darkness
	int fovZ;//per side
	std::priority_queue<DrawableWrapper,std::vector<DrawableWrapper>,DrawableComp> drawOrder;
};

#endif