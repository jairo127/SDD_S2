#ifndef LISTES_H
#define LISTES_H

#include "../Biblio/biblio.h"


/* Gestion d'une liste chainee a tete reelle */


/* Fonctions de gestion */

/****************************************************************/
/* Procédure : Affichage de la bibliothèque			*/
/* Entrée    : Liste d'emprunts					*/
/* Sortie    : Aucune						*/
/*								*/
/* La procédure affiche chaque maillon de la liste d'emprunts   */
/****************************************************************/
void             AfficherBiblio     (liste_categories_t);

/****************************************************************/
/* Procédure : Affichage de la bibliothèque			*/
/* Entrée    : Liste d'emprunts					*/
/* Sortie    : Aucune						*/
/*								*/
/* La procédure affiche chaque maillon de la liste d'emprunts   */
/****************************************************************/

void             InsererApresAdr    (liste_livres_t *, int, char *, int *);
void             InsererEnTete      (liste_categories_t *, char * , liste_livres_t, int *);
void             RemplirListe       (FILE *, liste_categories_t *, int *);
void             LibererListeLivre  (liste_livres_t);
void             LibererBibliotheque(liste_categories_t);

#endif
