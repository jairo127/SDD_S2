#ifndef DATES_H
#define DATES_H

#include "biblio.h"

typedef struct liste_emprunt 
{
    int                       numero;
    long                      date_retour;
    struct liste_emprunt *    suiv;
} emprunt_t, *liste_emprunt_t;

/* Fonctions */

void              AfficherDates    (liste_emprunt_t);
liste_emprunt_t * RechercheEmprunt (liste_emprunt_t *, long);
liste_livres_t  * RechercheLivre   (liste_categories_t, char[4], int);
void              InsererEmprunt   (liste_categories_t, liste_emprunt_t *, char[4], int, long, int *);
void              SupprimerEmprunt (liste_categories_t, liste_emprunt_t *, char[4], int, long, int *);

#endif
