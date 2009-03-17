#ifndef _behaviors_inc
#define _behaviors_inc

#include "coordinate.h"

namespace Behaviors
{

void Wave(Coordinate *c, int t);
void Zag(Coordinate *c, int t);
void Stay(Coordinate *c, int t);
void Straight(Coordinate *c, int t);
void Homing(Coordinate *c, int t);

}

#endif