#include "dates.h"

void AfficherDates (liste_emprunt_t dates)
{
    emprunt_t * cour = dates;

    while (cour)
    {
        printf("Numero de livre : %d , date de retour : %ld\n",
                cour->numero, cour->date_retour);
        cour = cour->suiv;
    }
}

liste_emprunt_t * RechercheEmprunt(liste_emprunt_t * dates, long date_retour)
{
    liste_emprunt_t * prec;
    prec = dates;
    while(*prec != NULL && date_retour > (*prec)->date_retour)
    {
        prec = &((*prec)->suiv);
    }
    return prec;

}

liste_livres_t * RechercheLivre(liste_categories_t biblio, char nom[4], int numero)
{
    liste_categories_t cour = biblio;
    liste_livres_t * prec = NULL;
    while (cour != NULL && strcmp(cour-> nom, nom) != 0)
    {
        cour = cour->suiv;
    }
    if (cour)
    {
        prec = &(cour->liste_livres_categorie);
        while(*prec != NULL && numero > (*prec)->numero)
        {
            prec = &((*prec)->suiv);
        }
    }
    return prec;
}

void InsererEmprunt (liste_categories_t liste, liste_emprunt_t * dates, char nom[4], int numero, long date_retour, int * code)
{
    liste_livres_t * adr = RechercheLivre(liste, nom, numero);
    if (*adr && (*adr)->numero == numero && (*adr)->disponible == 1) 
    {
        (*adr) -> disponible = 0;

        liste_emprunt_t * ptr = RechercheEmprunt(dates, date_retour);

        emprunt_t * maillon = (emprunt_t *) malloc(sizeof(emprunt_t));
        if (maillon)
        {
            maillon->numero = numero;
            maillon->date_retour = date_retour;
            maillon->suiv = *ptr;
            *ptr = maillon;
        }
        else
        {
            free(maillon);
            *code = 0;
        }

    }
    else
    {
        *code = 0;
    }
}

void SupprimerEmprunt (liste_categories_t liste, liste_emprunt_t * dates, char nom[4], int numero, long date_retour)
{
    liste_emprunt_t * cour = dates;
    emprunt_t * tmp;
    while( *cour != NULL && ((*cour)->numero != numero || (*cour)->date_retour != date_retour))
    {
        cour = &((*cour)-> suiv);
    }
    
    if (*cour)
    {
        tmp = *cour;
        *cour = (*cour) -> suiv;
        free(tmp);

        liste_livres_t * adr = RechercheLivre(liste, nom, numero);
        (*adr) -> disponible = 1;
    }
}
