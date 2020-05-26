#include "arbre.h"

int main()
{
	Arbre_t * arbre;
	FILE * fichier = fopen("ARBRE_1", "r");
	char * chaine = CreerChaine(fichier);
	fclose(fichier);
	AdaptChaine(&chaine);
	arbre = CreerArbre(chaine);
	//AjouterFils(arbre, 'm', 'o');
	ParcoursArbrePre(arbre);
	ParcoursArbrePost(arbre);
	/*AjouterFils(arbre, 'b', 'w');
	ParcoursArbre(arbre);
	AjouterFils(arbre, 'h', 'j');
	AjouterFils(arbre, 'a', 'l');
	ParcoursArbre(arbre);*/
	LibererArbre(&arbre);
	free(chaine);
	return 0;
}