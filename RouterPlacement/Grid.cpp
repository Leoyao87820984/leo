#include "Grid.h"

Grid::Grid(std::string gridName)
{

	std::ifstream file(gridName);

	if (file) {

		int backboneX;
		int backboneY;

		file >> nbRows;
		file >> nbColumns;
		file >> rangeRouter;
		file >> linkPrice;
		file >> routerPrice;
		file >> maxBudget;
		file >> backboneX;
		file >> backboneY;

		backbone.setCoordinates(backboneX, backboneY);

		building = new Cell*[nbRows];
		for (int i = 0; i<nbRows; ++i) {
			//building[i] = new Cell[nbColumns];
			building[i] = new Cell[nbColumns];
		}

		std::string line;

		for (int i = 0; i < nbRows; ++i) {

			getline(file, line);

			for (int j = 0; j < nbColumns; ++j) {
				char tempCell;
				file >> tempCell;
				building[i][j].setType(tempCell);
				building[i][j].setPosition(i, j);

			}

		}

		building[backboneX][backboneY].setBackbone();

	}

	else {

		std::cout << "Erreur : fichier introuvable !" << std::endl;

	}
}

std::ostream & operator<<(std::ostream & os, const Grid & obj)
{
	os << "Lignes : " << obj.nbRows << std::endl;
	os << "Colonnes : " << obj.nbColumns << std::endl;
	os << "Portee du routeur : " << obj.rangeRouter << std::endl;
	os << "Prix du cable : " << obj.linkPrice << std::endl;
	os << "Prix d'un routeur : " << obj.routerPrice << std::endl;
	os << "Budget maximal : " << obj.maxBudget << std::endl;
	os << "Position du backbone : " << obj.backbone << std::endl;

	os << std::endl;

	std::string show_grid;
	os << "Souhaitez-vous afficher la carte ? (y/n)" << std::endl;

	while ((show_grid != "y") && (show_grid != "n")) {
		std::cin >> show_grid;
	}

	if (show_grid == "y") {
		os << std::endl;

		for (int i = 0; i < obj.nbRows; i++) {
			for (int j = 0; j < obj.nbColumns; j++) {
				os << obj.building[i][j] << " ";
			}
			os << std::endl;
		}
	}

	return os;
}

void Grid::Routercover(Coordinates a) 
{
	int x = a.getCoordinateX();
	int y = a.getCoordinateY();
	int up = -(rangeRouter + x + 1);
	int down = (rangeRouter + x + 1);
	int left = -(rangeRouter + y + 1);
	int right = (rangeRouter + y + 1);
	int l = 2 * rangeRouter + 1;
	for (int i = rangeRouter + y; i >y; i--) {
		if (building[x][i].getType() == 1) {
			right = i;
		}
	}
	for (int i = y - rangeRouter; i < y; i++) {
		if (building[x][i].getType() == 1) {
			left = i;
		}
	}
	for (int i = x - rangeRouter; i < x; i++) {
		if (building[i][y].getType() == 1) {
			up = i;
		}
	}
	for (int i = x + rangeRouter; i > x; i--)
	{
		if (building[i][y].getType() == 1) {
			down = i;
		}
	}
	int k = 0;
	for (int i = x; i > x - rangeRouter - 1; i--) {
		for (int j = y; j > y - rangeRouter + k - 1; j--) {
			if (i > up&&j > left) {
				if (building[i][j].getType() == 1) {
					k = j + rangeRouter - y + 1;
				}
				else if (building[i][j].getType() == 0) {
					building[i][j].setType('c');

				}
			}

		}
	}
	k = 0;
	for (int i = x; i > x - rangeRouter - 1; i--) {
		for (int j = y; j < y + rangeRouter - k + 1; j++) {
			if (i > up&&j < right) {
				if (building[i][j].getType() == 1) {
					k = y + rangeRouter - j + 1;
				}
				else if (building[i][j].getType() == 0) {
					building[i][j].setType('c');

				}
			}

		}
	}
	k = 0;
	for (int i = x; i < x + rangeRouter + 1; i++) {
		for (int j = y; j > y - rangeRouter + k - 1; j--) {
			if (i < down&&j > left) {
				if (building[i][j].getType() == 1) {
					k = j + rangeRouter - y + 1;
				}
				else if (building[i][j].getType() == 0) {
					building[i][j].setType('c');

				}
			}

		}
	}
	k = 0;
	for (int i = x; i <x + rangeRouter + 1; i++) {
		for (int j = y; j < y + rangeRouter - k + 1; j++) {
			if (i < down&&j < right) {
				if (building[i][j].getType() == 1) {
					k = y + rangeRouter - j + 1;
				}
				else if (building[i][j].getType() == 0) {
					building[i][j].setType('c');

				}
			}

		}
	}
	building[x][y].setType('r');
	/*for (int i = 0; i < l; i++) {
	for (int j = 0; j < l; j++) {
	if ((x - rangeRouter + i) < down && (x - rangeRouter + i) > up && (y - rangeRouter + j) < right && (y - rangeRouter + j) > left) {
	building[x - rangeRouter + i][y - rangeRouter + j].setType('c');
	}
	}
	}*/
}


std::vector<Cell> Grid::findNeighbours(Cell c) // Remplit neighboursList avec les voisins de la cellule
{
	int xCoord = c.getPosition().getCoordinateX();
	int yCoord = c.getPosition().getCoordinateY();

	c.addNeighbour(building[yCoord][xCoord - 1]);


	c.addNeighbour(building[yCoord - 1][xCoord - 1]);


	c.addNeighbour(building[yCoord - 1][xCoord]);


	c.addNeighbour(building[yCoord - 1][xCoord + 1]);


	c.addNeighbour(building[yCoord][xCoord + 1]);


	c.addNeighbour(building[yCoord + 1][xCoord + 1]);


	c.addNeighbour(building[yCoord + 1][xCoord]);


	c.addNeighbour(building[yCoord + 1][xCoord - 1]);
	//std::cout << building[yCoord + 1][xCoord - 1].getPosition() << std::endl;
	//std::cout << building[yCoord + 1][xCoord - 1] << std::endl;

	/*for (std::vector<Cell>::const_iterator it = c.getNeighboursList().begin(); it != c.getNeighboursList().end(); ++it) {

	std::cout << *it << " ";
	}
	std::cout << std::endl;*/
	return c.getNeighboursList();
}