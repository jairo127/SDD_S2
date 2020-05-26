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
	ParcoursArbre(arbre);
	AjouterFils(arbre, 'm', 'o');
	ParcoursArbre(arbre);
	AjouterFils(arbre, 'b', 'w');
	ParcoursArbre(arbre);
	AjouterFils(arbre, 'h', 'j');
	AjouterFils(arbre, 'a', 'l');
	ParcoursArbre(arbre);
	return 0;
}