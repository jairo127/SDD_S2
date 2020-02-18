#ifndef BIBLIO_H
#define BIBLIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAILLE_MAX 30

/* Utilisation de tetes reelles dans les listes chainees */


typedef struct liste_livres
{
    int                   numero ;
    char                  titre[11] ;
    int                   disponible ; //1 si le livre est disponible, 0 s'il est emprunte
    struct liste_livres * suiv ;
} livres_t, *liste_livres_t ;


typedef struct liste_categories 
{
    char                          nom[4];
    liste_livres_t                liste_livres_categorie;
    struct liste_categories *     suiv ;
} categories_t, *liste_categories_t ;


/* Fonctions de traitement de fichiers */


FILE *        OuvrirFichier    (char *, int *, char *);
void          LireDonnees      (FILE *);


#endif