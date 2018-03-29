#include "Tools.h"


// COORDINATES

std::ostream & operator<<(std::ostream & os, const Coordinates & obj)
{
	os << "(" << obj.x << " ; " << obj.y << ")";

	return os;
}

bool operator==(Coordinates const &obj1, Coordinates const &obj2) {

	if ((obj1.x == obj2.x) && (obj1.y == obj2.y)) {
		return true;
	}
	else return false;
}




// CELL

Cell::Cell(char c, int coordinateX, int coordinateY)
{
	setType(c);
	setPosition(coordinateX, coordinateY);
}


void Cell::setType(char c)
{
	if (c == '.') {
		type = 0;
	}
	else if (c == '#') {
		type = 1;
	}
	else if (c == '-') {
		type = 2;
	}
	else if (c == 'r') {
		type = 4;
	}
	else if (c == 'c') {
		type = 6;
	}
}

void Cell::setBackbone()
{
	type = 3;
}

void Cell::setPosition(int i, int j)
{
	position.setCoordinates(i, j);
}

void Cell::addNeighbour(Cell c)
{
	neighboursList.push_back(c);
}


std::ostream & operator<<(std::ostream & os, const Cell & obj)
{
	os << obj.type;

	return os;
}


std::ostream & operator<<(std::ostream & os, const std::vector<Cell> &obj)
{

	for (std::vector<Cell>::const_iterator it = obj.begin(); it != obj.end(); ++it) {

		os << *it << " ";
	}
	os << std::endl;

	return os;
}