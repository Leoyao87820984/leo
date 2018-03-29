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
		subFile << N << std::endl; // nombre de cellules connectées au backbone

								   // liste des cellules connectées au backbone, par ordre de connexion
								   // QUESTION : Plusieurs câbles peuvent-ils partir d'un même routeur ?
								   // -> Si oui : utiliser un vecteur contenant des listes chaînées
								   // -> Si non : utiliser une liste chaînée

		subFile << M << std::endl; // nombre de routeurs déployés

								   // liste des routeurs déployés
		for (std::vector<Coordinates>::iterator it = listRouters.begin(); it != listRouters.end(); ++it) {

			Coordinates temp = *it;
			subFile << temp.getCoordinateX() << " " << temp.getCoordinateY() << std::endl;
			//~temp();
		}
	}

	else std::cout << "Impossible d'ecrire dans le fichier de sortie !" << std::endl;
}
