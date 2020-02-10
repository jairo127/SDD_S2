#include"liste_livre.h"

// Insére un livre dans la liste
liste_livre_t inserer_livre(liste_livre_t liste, int numero, char * titre)
{
	liste_livre_t * prec = &liste;
	maillon_livre_t * maillon;
	maillon = (maillon_livre_t*) malloc(sizeof(maillon_livre_t));
	if (maillon != NULL)
	{
		maillon->numero = numero;
		strcpy(maillon->titre, titre);
		while(*prec != NULL && strcmp(titre, (*prec)->titre)>0)
			prec = &((*prec)->suiv);
		maillon->suiv = *prec;
		*prec = maillon;
	}
	return liste;
}

// Lis un livre dans un fichier
void lire_livre(FILE * file, int * numero, char * titre)
{
	fscanf(file, "%d %[^\n]", numero, titre);
}

// Affiche le livre en tête de la liste
void afficher_livre(liste_livre_t liste)
{
	printf("Numero : %d\nTitre : %s\n------------\n", liste->numero, liste->titre);
}

// Initialise une liste de livre
liste_livre_t init_liste_livre(void)
{
	return NULL;
}

// Affiche tous les livres de la liste
void afficher_liste_livre(liste_livre_t liste)
{
	liste_livre_t cour = liste;
	while(cour != NULL)
	{
		afficher_livre(cour);
		cour = cour->suiv;
	}
}