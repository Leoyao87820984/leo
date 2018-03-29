#pragma once

#include "Tools.h"
#include "Grid.h"

class Resolve {	
public:

	void findRectangles(Grid grid) ; // Trouve les plus grands rectangles remplis de cellules ?couvrir
	void splitRectangles(); // Décompose les rectangles pour couvrir un maximum de cellules avec un minimum de routeurs
	void statsRouters(); // Stocke pour chaque routeur, son score, sa distance au backbone et le nombre de routeurs dans son entourage
	void sortRouters(); // Classe les routeurs ?l'aide d'une équation qui pondère les variables citées ci-dessus
	void linkRouters(); // Relie le maximum de routeurs en respectant le classement et le budget
	void linkRouters(Cell a, Cell b);
	void addRouter(Coordinates);
	Coordinates getNearestRouter(Coordinates);
	double calculateDistance(Coordinates, Coordinates);
	double calculateSlope(Coordinates a, Coordinates b);


private:
	std::vector<Rectangle> listRectangles;
	std::vector<Coordinates> listRouters;
};