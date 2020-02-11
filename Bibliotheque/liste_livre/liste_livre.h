#ifndef L_LIVRE
#define L_LIVRE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 30
#define TITRE_MAX 31

typedef struct liste_livres
{
    int                   numero;
    char                  titre[TITRE_MAX];
    int                   disponible; //1 si le livre est disponible, 0 s'il est emprunte
    struct liste_livres * suiv;
} livres_t, *liste_livres_t;

liste_livres_t		InitListeLivre(void);
liste_livres_t *	RechercheLivre(liste_livres_t*, int);
void				InsererLivre(liste_livres_t*, int, char*);
void				AfficherLivre(FILE*, liste_livres_t);
void				AfficherListeLivre(FILE*, liste_livres_t);
void				LireLivre(FILE*, int*, char*);

#endif