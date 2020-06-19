/********************************************/
/* Fichier main.c 		                  	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient les codes d'exécutions des	    */
/* différentes manipulations				*/
/********************************************/

#include "table.h"

int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		printf("Compiler avec le nom du fichier texte : ./run <text>\n");
	}
	else
	{
		liste_mots_t * table_hash; //la table de hachage
		FILE * fichier = fopen(argv[1],"r");
		if (fichier)
		{
			Traitement(&table_hash, fichier); //Initialisation de la table et création à partir du fichier texte.
		}
		else
		{
			printf("Erreur d'ouverture du fichier.\n");
		}
		fclose(fichier);

		AfficherTable(table_hash); //Affichage de la table

		LibererTable(table_hash); //Libération de la table
	}

	return 0;
}