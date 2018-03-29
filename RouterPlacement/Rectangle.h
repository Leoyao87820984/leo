
#pragma once

#include "Coordinates.h"

class Rectangle {

public:
	Rectangle(Coordinates a, Coordinates b, Coordinates c, Coordinates d) : upperLeftCorner(a), upperRightCorner(b), lowerLeftCorner(c), lowerRightCorner(d) {}

private:
	Coordinates upperLeftCorner;
	Coordinates upperRightCorner;
	Coordinates lowerLeftCorner;
	Coordinates lowerRightCorner;
};