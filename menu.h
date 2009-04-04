#ifndef _menu_inc
#define _menu_inc

#include "screen.h"
#include "map"

class Menu : public Screen
{
public:
	Menu(int* chooser);
	std::map<std::string,void(*)()> menu;
	int* currentChoice;
	void draw();
	void execute();
};

#endif