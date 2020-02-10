#ifndef L_CATEG
#define L_CATEG
#include"../liste_livre/liste_livre.h"

typedef struct liste_categorie
{
	char titre[4];
	int nombre_livre;
	liste_livre_t liste_livre;
	struct liste_categorie * suiv;
} maillon_categorie_t, liste_categorie_t;

liste_categorie_t init_liste_categorie(void);

void inserer_categorie(liste_categorie_t, *char, int, liste_livre);

void lire_categorie(*char, *int, *liste_livre_t);

#endif