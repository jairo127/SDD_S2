#ifndef LISTES_H
#define LISTES_H

#include "../Biblio/biblio.h"


/* Gestion d'une liste chainee a tete reelle */


/* Fonctions de gestion */

void             AfficherBiblio   (liste_categories_t);
void             InsererApresAdr  (liste_livres_t *, int, char *);
void             InsererEnTete    (liste_categories_t *, char * , liste_livres_t);
void             RemplirListe     (FILE *, liste_categories_t *);

#endif
