#ifndef MENU_H
#define MENU_H

#include "../Biblio/biblio.h"
#include "../Listes/listes.h"
#include "../Dates/dates.h"

void    AfficherMenu();
int     GestionChoix();
void    Emprunter(liste_categories_t, liste_emprunt_t *, char [20], int *);
void    Rendre(liste_categories_t, liste_emprunt_t *, char [20], int *);
long    RecupAnnee(long);
long    RecupMois(long);
long    RecupJour(long);
void    Imprimer(liste_emprunt_t, long);
void    SauvegarderEmprunts(liste_emprunt_t, FILE *);

#endif
