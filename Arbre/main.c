#include "arbre.h"

int main()
{
	Arbre_t * liste_arbre[4]; // les 4 differents arbres
	char liste_fichier[][8] = {"ARBRE_1", "ARBRE_2", "ARBRE_3", "ARBRE_4" }; // les 4 differents noms de fichiers
	char * liste_chaine[4]; // les 4 chaines de caracteres associees
	
	int i;

	for (i=0;i<4;i++)
	{
		FILE * fichier = fopen(liste_fichier[i], "r");
		liste_chaine[i] = CreerChaine(fichier);
		AdaptChaine(&liste_chaine[i]);
		liste_arbre[i] = CreerArbre(liste_chaine[i]);
		fclose(fichier);
	}
	
	// Manipulations sur l'arbre 1
	printf("Manipulations sur l'arbre 1\n");

	ParcoursArbrePre(liste_arbre[0]);
	ParcoursArbrePost(liste_arbre[0]);

	AjouterFils(liste_arbre[0], 'm', 'o');

	ParcoursArbrePre(liste_arbre[0]);
	ParcoursArbrePost(liste_arbre[0]);

	printf("%d\n", AjouterFils(liste_arbre[0], 'y', 's')); // Affiche 0 car le sommet y n'existe pas

	AjouterFils(liste_arbre[0], 'b', 'w');
	AjouterFils(liste_arbre[0], 'h', 'j');
	AjouterFils(liste_arbre[0], 'a', 'l');
	AjouterFils(liste_arbre[0], 'w', 'q');

	ParcoursArbrePre(liste_arbre[0]);
	ParcoursArbrePost(liste_arbre[0]);

	// Manipulations sur l'arbre 2
	printf("Manipulations sur l'arbre 2\n");

	ParcoursArbrePre(liste_arbre[1]);
	ParcoursArbrePost(liste_arbre[1]);

	AjouterFils(liste_arbre[1], 'm', 'o');

	ParcoursArbrePre(liste_arbre[1]);
	ParcoursArbrePost(liste_arbre[1]);

	// Structure du code identique avec une forêt

	// Manipulations sur l'arbre 3
	printf("Manipulations sur l'arbre 3\n");

	ParcoursArbrePre(liste_arbre[2]);
	ParcoursArbrePost(liste_arbre[2]);

	AjouterFils(liste_arbre[2], 'a', 'b');

	ParcoursArbrePre(liste_arbre[2]);
	ParcoursArbrePost(liste_arbre[2]);

	// Manipulations sur l'arbre 4
	printf("Manipulations sur l'arbre 4\n");

	ParcoursArbrePre(liste_arbre[3]);
	ParcoursArbrePost(liste_arbre[3]);

	AjouterFils(liste_arbre[3], 'd', 'e');
	AjouterFils(liste_arbre[3], 'b', 'x');

	ParcoursArbrePre(liste_arbre[3]);
	ParcoursArbrePost(liste_arbre[3]);

	for (i=0;i<4;i++)
	{
		LibererArbre(&liste_arbre[i]);
		free(liste_chaine[i]);
	}
	return 0;
}