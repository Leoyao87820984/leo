#pragma once

#include <string>
#include <vector>
#include <iostream>


// COORDINATES

class Coordinates {

	friend std::ostream &operator<<(std::ostream &os, const Coordinates &obj);
	friend bool operator==(Coordinates const &obj1, Coordinates const &obj2);

public:
	Coordinates() {}
	Coordinates(int x, int y) : x(x), y(y) {}
	virtual ~Coordinates() {}
	inline void setCoordinates(int a, int b) { x = a; y = b; }
	inline int getCoordinateX() { return(x); }
	inline int getCoordinateY() { return(y); }

private:
	int x;
	int y;
};

std::ostream &operator<<(std::ostream &os, const Coordinates &obj);


// CELL

class Cell {

	friend std::ostream &operator<<(std::ostream &os, const Cell &obj);
	friend std::ostream &operator<<(std::ostream &os, std::vector<Cell> &obj);

public:
	Cell() {}
	Cell(char, int coordinateX, int coordinateY);
	virtual ~Cell() {}
	void setType(char c);
	void setBackbone();
	void setPosition(int i, int j);
	void addNeighbour(Cell);
	inline int getType() {return (this->type); }
	inline Coordinates getPosition() { return (position); }
	inline const std::vector<Cell> &getNeighboursList() { return(neighboursList); }


private:
	int type; // .->0 ; #->1 ; -->2 ; b->3 ; r->4 ; l->5 ; zoneCouverte -> 6
	std::vector<Cell> neighboursList;

	Coordinates position;
};

std::ostream &operator<<(std::ostream &os, const Cell &obj);
std::ostream &operator<<(std::ostream &os, const std::vector<Cell> &obj);


// RECTANGLE

class Rectangle {

public:
	Rectangle(Coordinates a, Coordinates b, Coordinates c, Coordinates d) : upperLeftCorner(a), upperRightCorner(b), lowerLeftCorner(c), lowerRightCorner(d) {}

private:
	Coordinates upperLeftCorner;
	Coordinates upperRightCorner;
	Coordinates lowerLeftCorner;
	Coordinates lowerRightCorner;
};

