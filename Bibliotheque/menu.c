#include "menu.h"

void AfficherMenu()
{
    printf("Gestionnaire de bibliotheque\n1) Consulter la bibliotheque\n2) Consulter la liste des emprunts\n3) Emprunter les livres\n4) Rendre les livres\n5) Quitter\n\nEntrer un entier correspondant au choix : ");
}

int GestionChoix()
{
    int choix;
    scanf("%d", &choix);
    printf("\n\n");
    return choix;
}

void Emprunter(liste_categories_t biblio, liste_emprunt_t dates, int * code)
{
    char ligne[TAILLE_MAX];
    char nom[4];
    int numero;
    long date_retour;
    FILE * emprunts = fopen("Emprunts", "r");

    if (!emprunts)
    {
        printf("Erreur, le fichier Emprunts est introuvable\n");
    }
    else
    {
        while (!feof(emprunts) && code)
        {
            fgets(ligne, TAILLE_MAX, emprunts);
            sscanf(ligne, "%s %d %ld", nom, &numero, &date_retour);
            InsererEmprunt(biblio, &dates, nom, numero, date_retour, code);
        }
        if (!code)
        {
            printf("Erreur de lecture du fichier Emprunt\n");
        }
    }
}

void Rendre(liste_categories_t biblio, liste_emprunt_t dates)
{
    char ligne[TAILLE_MAX];
    char nom[4];
    int numero;
    long date_retour;
    FILE * rendus = fopen("Rendus", "r");

    if (!rendus)
    {
        printf("Erreur, le fichier Rendus est introuvable\n");
    }
    else
    {
        while (!feof(rendus))
        {
            fgets(ligne, TAILLE_MAX, rendus);
            sscanf(ligne, "%s %d %ld", nom, &numero, &date_retour);
            SupprimerEmprunt(biblio, &dates, nom, numero, date_retour);
        }
    }
}