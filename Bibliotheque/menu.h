#ifndef MENU_H
#define MENU_H

#include "biblio.h"
#include "listes.h"
#include "dates.h"

void    AfficherMenu();
int     GestionChoix();
void    Emprunter(liste_categories_t, liste_emprunt_t *, int *);
void    Rendre(liste_categories_t, liste_emprunt_t *, int *);
long    RecupAnnee(long);
long    RecupMois(long);
long    RecupJour(long);
void    Imprimer(liste_emprunt_t, long);

#endif
