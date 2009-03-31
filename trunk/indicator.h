#ifndef _indicator_inc
#define _indicator_inc

#include "allegro.h"
#include "subScreen.h"


enum IndicatorType {IND_METER,IND_LIGHT,IND_DIGIT3,IND_DIGIT4,IND_DIGIT5};

class Indicator : public SubScreen
{
public:
	Indicator(BITMAP* parentScreen, IndicatorType _type, int* value, int x, int y);
	int* value;
	IndicatorType type;
	RLE_SPRITE* image;
	void draw();
};

#endif