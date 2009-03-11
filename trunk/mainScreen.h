//bitmap
//3ding

#ifndef _mainScreen_inc
#define _mainScreen_inc
#include "screen.h"
#include "vector"
#include "subScreen.h"
#include "boost/ptr_container/ptr_list.hpp"

class MainScreen : public Screen
{
public:
	MainScreen();
	void draw();
	boost::ptr_list<SubScreen> subScreens;
private:
	void drawSubScreens();
	RLE_SPRITE* hud;
};

#endif