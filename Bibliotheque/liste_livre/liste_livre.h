#ifndef L_LIVRE
#define L_LIVRE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct liste_livre
{
	int numero;
	char titre[30];
	struct liste_livre * suiv;
} maillon_livre_t, * liste_livre_t;

// Initialise une liste de livre
liste_livre_t init_liste_livre(void);

// Insére un livre dans la liste
liste_livre_t inserer_livre(liste_livre_t, int, char*);

// Lis un livre dans un fichier
void lire_livre(FILE*, int*, char*);

// Affiche le livre en tête de la liste
void afficher_livre(liste_livre_t);

// Affiche tous les livres de la liste
void afficher_liste_livre(liste_livre_t liste);

#endif