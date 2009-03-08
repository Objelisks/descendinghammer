#ifndef _screen_inc
#define _screen_inc

#include "allegro.h"

class Screen {
public:
	virtual void draw(){};
protected:
	BITMAP* m_screen;
};

#endif