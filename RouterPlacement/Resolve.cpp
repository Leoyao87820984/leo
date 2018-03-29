#include "Resolve.h"

void Resolve::findRectangles(Grid grid)
{
	Coordinates backbone = grid.getBackbone();
	int rangeRouter = grid.getRangeRouter();


}

void Resolve::splitRectangles()
{
}

void Resolve::statsRouters()
{
}

void Resolve::sortRouters()
{

}

void Resolve::linkRouters()
{
	for (std::vector<Coordinates>::iterator it = listRouters.begin(); it != listRouters.end(); ++it) {

		Coordinates nearestRouter = getNearestRouter(*it);

	}
}

void Resolve::linkRouters(Cell a, Cell b)
{

	double slope = calculateSlope(a.getPosition(), b.getPosition());
	Coordinates lastLinked;
	std::vector<Cell> targetNeighbours = b.getNeighboursList();
	std::vector<Coordinates> targetNeighboursCoordinates;

	for (std::vector<Cell>::iterator it = targetNeighbours.begin(); it != targetNeighbours.end(); ++it) {

		Cell temp = *it;
		targetNeighboursCoordinates.push_back(temp.getPosition());
	}

	int i = 1;

	while (!(std::find(targetNeighboursCoordinates.begin(), targetNeighboursCoordinates.end(), lastLinked) != targetNeighboursCoordinates.end())) {

		if (lastLinked.getCoordinateY() > a.getPosition().getCoordinateY() + slope*i) {}


		i++;
	}
}

void Resolve::addRouter(Coordinates c)
{
	listRouters.push_back(c);

}

Coordinates Resolve::getNearestRouter(Coordinates c)
{
	double distanceMin = -1;
	Coordinates nearestRouter;

	for (std::vector<Coordinates>::iterator it = listRouters.begin(); it != listRouters.end(); ++it) {

		double distance = calculateDistance(c, *it);

		if ((distance < distanceMin) || (distanceMin == -1)) {

			distanceMin = distance;
			nearestRouter = *it;
		}
	}
	return nearestRouter;
}

double Resolve::calculateDistance(Coordinates a, Coordinates b)
{
	double distance = sqrt((pow((a.getCoordinateX() - b.getCoordinateX()), 2) + pow((a.getCoordinateY() - b.getCoordinateY()), 2)));

	return distance;
}

double Resolve::calculateSlope(Coordinates a, Coordinates b)
{
	double slope = ((b.getCoordinateY() - a.getCoordinateY()) / (b.getCoordinateX() - a.getCoordinateX()));

	return slope;
}