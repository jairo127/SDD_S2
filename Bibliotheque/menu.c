#include "menu.h"

void AfficherMenu()
{
    system('clear');
    printf("1) Consulter la bibliotheque\n
            2) Consulter la liste des emprunts\n
            3) Emprunter un livre\n
            4) Rendre un livre\n
            5) Quitter\n
            \n
            Entrer un entier correspondant au choix : ");
}

int GestionChoix()
{
    int choix;
    scanf("%d", &choix);
    printf("\n\n");
    return choix
}