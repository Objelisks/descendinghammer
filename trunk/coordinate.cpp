#include "coordinate.h"
#include "common.h"
#include "string"

Coordinate::Coordinate() {x=0;y=0;z=0;};
Coordinate::Coordinate(int a, int b, int c) {x=a;y=b;z=c;};
void Coordinate::setX(int a){x=a;};
void Coordinate::setY(int b){y=b;};
void Coordinate::setZ(int c){z=c;};