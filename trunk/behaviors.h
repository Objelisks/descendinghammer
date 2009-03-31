#ifndef _behaviors_inc
#define _behaviors_inc

#include "coordinate.h"

namespace Behaviors
{

void Wave(Coordinate *c, int t, double speed);
void Zag(Coordinate *c, int t, double speed);
void Stay(Coordinate *c, int t, double speed);
void Straight(Coordinate *c, int t, double speed);
void Homing(Coordinate *c, int t, double speed);

}

#endif