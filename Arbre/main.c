#include "arbre.h"

int main()
{
	Arbre_t * arbre;
	FILE * fichier = fopen("ARBRE_1", "r");
	char * chaine = CreerChaine(fichier);
	fclose(fichier);
	ConvertStr(&chaine);
	printf("%s\n", chaine);
	arbre = CreerArbre(chaine);
	//ParcoursArbre(arbre);
	return 0;
}