/****************************************************************/
/* Fichier : dates.c                                            */
/*                                                              */
/* Auteurs : Valentin Guien - William Garrier                   */
/*                                                              */
/* Fichier contenant les implémentation des fonctions de        */
/* gestion des emprunts déclarées dans dates.h                  */
/****************************************************************/

#include "dates.h"

/****************************************************************/
/* Procédure : Afficher les emprunts                            */
/* Entrées : Liste d'emprunts                                   */
/* Sortie : Aucune                                              */
/*                                                              */
/* Fonction chargée d'afficher la liste des emprunts            */
/****************************************************************/
void AfficherDates (liste_emprunt_t dates)
{
    emprunt_t * cour = dates;
    if (cour) 
    {
    	do
    	{
        	printf("Numero de livre : %d , date de retour : %ld\n",
        	        cour->numero, cour->date_retour);
        	cour = cour->suiv;
    	} while (cour);
    }
    else
    {
	    printf("Aucun livre n'a été emprunté\n");
    }
}

/****************************************************************/
/* Fonction : Recherche d'emprunts                              */
/* Entrées : Liste d'emprunts (A), Date de recherche            */
/* Sortie : Liste d'emprunts (B) (A inclus dans B)              */
/*                                                              */
/* Fonction de recherche des emprunts à rendre après la date    */
/* passée en paramétre de la fonction                           */
/****************************************************************/
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

/****************************************************************/
/* Fonction : Recherche de livre                                */
/* Entrées : Liste de catégorie, Nom de la catégorie,           */
/*           Numéro du livre                                    */
/* Sortie : Pointeur sur le livre exact ou le précédent         */
/*                                                              */
/* Fonction de recherche de livre. La catégorie et le numéro    */
/* du livre est passé en paramétre. La fonction retourne un     */
/* pointeur sur le livre trouvé ou le précédent du numéro       */
/****************************************************************/
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

/****************************************************************/
/* Fonction : Insertion d'emprunt                               */
/* Entrées : Liste de catégorie                                 */
/*           Adresse de la liste d'emprunts                     */
/*           Nom de la catégorie                                */
/*           Numéro du livre                                    */
/*           Date de retour du livre                            */
/* Sortie : Code de retour                                      */
/*          (0 Ok, 1 Livre introuvable, 2 Livre déjà emprunté,  */
/*          3 Plus de place dans la mémoire)                    */
/*                                                              */
/* Fonction d'insertion d'emprunt                               */
/****************************************************************/
void InsererEmprunt(liste_categories_t liste, liste_emprunt_t * dates, char nom[4], int numero, long date_retour, int * code)
{
    liste_livres_t * adr = RechercheLivre(liste, nom, numero);
    
    if (*adr && (*adr)->numero == numero)
    {
        if ((*adr)->disponible == 1) 
        {
            emprunt_t * maillon = (emprunt_t *) malloc(sizeof(emprunt_t));
            if (maillon)
            {
                liste_emprunt_t * ptr = RechercheEmprunt(dates, date_retour);

		maillon->numero = numero;
                maillon->date_retour = date_retour;
                maillon->suiv = *ptr;
                *ptr = maillon;

		(*adr)->disponible = 0;
            }
            else
            {
                free(maillon);
                *code = 3;
            }

        }
        else
        {
            *code = 2;
        }
    }
    else
    {
	*code = 1;
    }
}


// 0 : ok
// 1 : livre introuvable
// 2 : livre pas emprunté
// 3 : date retour incorrect
void SupprimerEmprunt (liste_categories_t liste, liste_emprunt_t * dates, char nom[4], int numero, long date_retour, int * code)
{
    emprunt_t * tmp;

    liste_livres_t * adr = RechercheLivre(liste, nom, numero);

    if (*adr && (*adr) -> numero == numero)
    {
	if ((*adr) -> disponible == 0)
	{
	
	    liste_emprunt_t * ptr = RechercheEmprunt(dates, date_retour);
   
    	    if (*ptr && (*ptr)->date_retour == date_retour)
    	    {
        	tmp = *ptr;
        	*ptr = (*ptr) -> suiv;
        	free(tmp);

        	(*adr) -> disponible = 1;
    	    }
	    else
	    {
		*code = 3;
	    }
	}
	else
	{
	    *code = 2;
	}
    }
    else
    {
        *code = 1;	
    }
}
// si (*adr)->disponible = 0, afficher message d'erreur, ou bien si on veut rendre un livre qui n'existe pas
