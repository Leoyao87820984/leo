#pragma once

#include "Tools.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Grid {

	friend std::ostream &operator<<(std::ostream &os, const Grid &obj);

public:
	Grid(std::string);
	virtual ~Grid() {}
	inline int getNbRows() { return(nbRows); }
	inline int getNbColumns() { return(nbColumns); }
	inline int getRangeRouter() { return(rangeRouter); }
	inline double getLinkPrice() { return(linkPrice); }
	inline double getRouterPrice() { return(routerPrice); }
	inline double getMaxBudget() { return(maxBudget); }
	inline Coordinates getBackbone() { return(backbone); }
	inline std::vector<Coordinates> getListConnected() { return(listConnected); }
	inline std::vector<Coordinates> getListRouters() { return(listRouters); }
	inline Cell getBuildingValue(int i, int j) { return(building[i][j]); }
	void setRouter(int i,int j) {
		building[i][j].setType('r');

	}
	void Routercover(Coordinates a);
	std::vector<Cell> findNeighbours(Cell cell);


private:
	int nbRows; // nombre de lignes de la grille
	int nbColumns; // nombre de colonnes de la grille
	int rangeRouter; // rayon de la portee
	double linkPrice; // prix pour connecter une cellule au backbone
	double routerPrice; // prix d'un routeur
	double maxBudget; // budget maximal
	Coordinates backbone; // coordonnées du backbone
	std::vector<Coordinates> listRouters; // liste de coordonnées des routeurs
	std::vector<Coordinates> listConnected; // liste des cellules connectées
											// Intégrer solution liste câbles : cf Submission.cpp

	Cell **building;

};

std::ostream &operator<<(std::ostream &os, const Grid &obj);