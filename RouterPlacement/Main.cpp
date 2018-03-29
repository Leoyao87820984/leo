#include "Tools.h"
#include "Grid.h"
#include"Resolve.h"
int main() {

	Grid test("test_grid.in");

	std::cout << "########### PARAMETRES ###########" << std::endl;
	//test.setRouter(6, 6);
	Resolve a(test);
	
	std::cout << test << std::endl;

	Cell cell = test.getBuildingValue(5, 5);

	std::cout << "Voisins de " << cell.getPosition() << " : " << std::endl;

	std::cout << test.findNeighbours(cell) << std::endl;


	int concombre;
	std::cin >> concombre;
	return 0;

}