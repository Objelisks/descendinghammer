#ifndef _effectManager_inc
#define _effectManager_inc

#include "effect.h"
#include "list"

class EffectManager
{
public:
	EffectManager();
	std::list<Effect> effects;
	void addEffect(Effect e);
};

#endif