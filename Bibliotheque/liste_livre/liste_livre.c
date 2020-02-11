#include"liste_livre.h"

liste_livres_t		InitListeLivre(void)
{
	return NULL;
}

liste_livres_t *	RechercheLivre(liste_livres_t* liste, int numero)
{
	liste_livres_t * prec;
	prec = liste;
	while(*prec != NULL && numero > (*prec)->numero)
	{
		prec = &((*prec)->suiv);
	}
	return prec;
}

void				InsererLivre(liste_livres_t* liste, int numero, char* titre)
{
	liste_livres_t * prec;

	livres_t * maillon;
	maillon = (livres_t*) malloc(sizeof(livres_t));

	if (maillon != NULL)
	{
		maillon->numero = numero;
		strcpy(maillon->titre, titre);
		maillon->disponible = 1;

		prec = RechercheLivre(liste, numero);

		maillon->suiv = *prec;
		*prec = maillon;
	}
}

void				AfficherLivre(FILE* fichier, liste_livres_t liste)
{
	if (liste != NULL)
	{
		fprintf(fichier, "%d %s\n", liste->numero, liste->titre);
	}
}

void				AfficherListeLivre(FILE* fichier, liste_livres_t liste)
{
	while(liste != NULL)
	{
		AfficherLivre(fichier, liste);
		liste = liste->suiv;
	}
}

void				LireLivre(FILE* fichier, int* numero, char* titre)
{
	fscanf(fichier, "%d %[^\n]", numero, titre);
}