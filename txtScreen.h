#ifndef _txtScreen_inc
#define _txtScreen_inc

#include "allegro.h"
#include "vector"
#include "subScreen.h"

class TextScreen : public SubScreen
{
public:
	TextScreen();
	TextScreen(BITMAP* parentScreen,int x, int y);
	std::vector<std::string> text;
	int lines;
	bool available;
	unsigned int maxLines;
	int color;
	void draw();
	void addText(std::string str);
};

#endif