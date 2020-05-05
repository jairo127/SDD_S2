#include "arbre.h"

int main()
{
	FILE * fichier = fopen("ARBRE_1", "r");
	char * chaine = CreerChaine(fichier);
	fclose(fichier);

	printf("%s\n", chaine);

	return 0;
}