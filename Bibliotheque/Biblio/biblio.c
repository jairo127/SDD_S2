/****************************************************************/
/* Fichier : biblio.c                                           */
/*                                                              */
/* Auteurs : Valentin Guien - William Garrier                   */
/*                                                              */
/* Fichier contenant les implémentations des fonctions          */
/* déclarées dans biblio.h                                      */
/****************************************************************/

#include "biblio.h"

/****************************************************************/
/* Fonction : Ouverture de fichier                              */
/* Entrées : Nom du fichier, mode d'ouverture                   */
/* Sortie : Adresse du fichier ouvert (NULL si échec)           */
/*          Code de retour -> 1 si échec de l'ouverture         */
/*                                                              */
/* Fonction chargée d'ouvrir un fichier dont le nom et le mode  */
/* d'ouverture sont donnés en paramètre et retourne l'adresse   */
/* mémoire du fichier ouvert.                                   */
/****************************************************************/
FILE * OuvrirFichier (char * nom_fichier, int * code, char * mode)
{
    FILE * fichier = fopen(nom_fichier,mode);
    if (!fichier)
    {
        *code = 1;
    }
    return fichier;
}

/****************************************************************/
/* Procédure : Affichage du fichier                             */
/* Entrées : Adresse du fichier                                 */
/* Sortie : Aucune                                              */
/*                                                              */
/* Cette procédure lit chaque ligne du fichier et les affichent */
/* sur la sortie standard.                                      */
/****************************************************************/
void LireDonnees(FILE * fichier)
{
    char ligne[TAILLE_MAX];

    while (!feof(fichier))
    {
        fgets(ligne, TAILLE_MAX, fichier);
        printf("%s", ligne);
    }
}
