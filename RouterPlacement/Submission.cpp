#include "Submission.h"

void Submission::outputFile(Grid grid)
{

	std::ofstream subFile("./results.out");

	if (subFile) {

		// TRAITEMENT
		std::vector<Coordinates> listConnected = grid.getListConnected();
		std::vector<Coordinates> listRouters = grid.getListRouters();
		int N = listConnected.size();
		int M = listRouters.size();

		// ECRITURE
		subFile << N << std::endl; // nombre de cellules connect�es au backbone

								   // liste des cellules connect�es au backbone, par ordre de connexion
								   // QUESTION : Plusieurs c�bles peuvent-ils partir d'un m�me routeur ?
								   // -> Si oui : utiliser un vecteur contenant des listes cha�n�es
								   // -> Si non : utiliser une liste cha�n�e

		subFile << M << std::endl; // nombre de routeurs d�ploy�s

								   // liste des routeurs d�ploy�s
		for (std::vector<Coordinates>::iterator it = listRouters.begin(); it != listRouters.end(); ++it) {

			Coordinates temp = *it;
			subFile << temp.getCoordinateX() << " " << temp.getCoordinateY() << std::endl;
			//~temp();
		}
	}

	else std::cout << "Impossible d'ecrire dans le fichier de sortie !" << std::endl;
}
