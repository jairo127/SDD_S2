#include "biblio.h"


FILE * OuvrirFichier (char * nom_fichier, int * code, char * mode)
{
    FILE * fichier = fopen(nom_fichier,mode);
    if (!fichier)
    {
        *code = 0;
    }
    return fichier;
}


void LireDonnees(FILE * fichier)
{
    char ligne[TAILLE_MAX];

    while (!feof(fichier))
    {
        fgets(ligne, TAILLE_MAX, fichier);
        printf("%s", ligne);
    }
}
