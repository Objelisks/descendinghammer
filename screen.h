#ifndef _screen_inc
#define _screen_inc

#include "allegro.h"
#include "string"

class Screen {
public:
	std::string name;
	virtual void draw(){};
	virtual void execute(){};
	BITMAP* m_screen;
};

#endif