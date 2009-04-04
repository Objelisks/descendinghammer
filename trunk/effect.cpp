#include "effect.h"
#include "vector"
#include "allegro.h"

Effect::Effect()
{

};

Effect::Effect(std::vector<BITMAP*> imgs, Coordinate c, int step, bool _loop)
{
	images = imgs;
	pos = c;
	frameCount = imgs.size();
	currentFrame = 1;
	stepTime = step;
	currentTime = 0;
	loop = _loop;
	dead = false;
};

BITMAP* Effect::draw()
{
	BITMAP* returnMe = images[currentFrame];
	if(!dead)
	{
		currentTime++;
		if(currentTime >= stepTime)
		{
			currentFrame++;
			if(currentFrame >= frameCount)
			{
				if(loop)
				{
					currentFrame = 0;
				}
				else
				{
					dead = true;
				}
			}
			currentTime = 0;
		}
	}
	return returnMe;
};