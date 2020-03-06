#include "pile.h"

int main()
{
    Pile_t * pile = InitPile(10);
    std_type_t n = 99;

    printf("Vide : %s\n", (EstVide(*pile))?"Oui":"Non");
    printf("%d\n", pile->capacite);
    printf("%d\n", pile->sommet);

    Empiler(pile, 7);
    printf("POUP !\n");

    printf("%d\n", pile->capacite);
    printf("%d\n", pile->sommet);
    AfficherPile(*pile);

    Empiler(pile, 3);
    printf("POUP !\n");

    printf("%d\n", pile->capacite);
    printf("%d\n", pile->sommet);
    AfficherPile(*pile);

    Empiler(pile, 14);
    printf("POUP !\n");

    printf("%d\n", pile->capacite);
    printf("%d\n", pile->sommet);
    AfficherPile(*pile);



    printf("debug : %d \n", Depiler(pile, &n));
    printf("TOP ! : %d \n", n);

    printf("%d\n", pile->capacite);
    printf("%d\n", pile->sommet);
    AfficherPile(*pile);

    Empiler(pile, 25);
    printf("POUP !\n");

    printf("%d\n", pile->capacite);
    printf("%d\n", pile->sommet);
    AfficherPile(*pile);

    LibererPile(&pile);

    return 0;
}
