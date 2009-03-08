#ifndef _subScreen_inc
#define _subScreen_inc

#include "allegro.h"

class SubScreen
{
public:
	virtual void draw(){};
protected:
	BITMAP* m_subScreen;
};

#endif