#ifndef _effect_inc
#define _effect_inc

#include "vector"
#include "allegro.h"
#include "coordinate.h"

class Effect
{
public:
	Effect();
	Effect(std::vector<BITMAP*> images, Coordinate c, int stepTime, bool _loop);
	BITMAP* draw();
	Coordinate pos;
	std::vector<BITMAP*> images;
	int frameCount;
	int currentFrame;
	int stepTime;
	int currentTime;
	bool loop;
	bool dead;
};

#endif