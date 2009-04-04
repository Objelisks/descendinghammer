#include "effectManager.h"
#include "effect.h"
#include "list"

EffectManager::EffectManager()
{
	effects = std::list<Effect>();
};

void EffectManager::addEffect(Effect e)
{
	effects.insert(effects.end(), e);
};