#include "behaviors.h"
#include "gameState.h"
#include "cmath"
#include "common.h"

double Behaviors::Wave(int t)
{
	return cos(rad((double)t));
};

double Behaviors::Zag(int t)
{
	return t%50<25 ? 1 : -1;
};

double Behaviors::Stay(int t)
{
	return 0;
};

double Behaviors::Straight(int t)
{
	return 1;
};