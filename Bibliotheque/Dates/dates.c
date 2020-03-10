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
    emprunt_t * cour = dates; // pointeur de parcours de la liste des emprunts
    if (cour) 
    {
    	do
    	{
        	printf("Catégorie : %s, Numero de livre : %d, date de retour : %ld\n",
        	        cour->nom, cour->numero, cour->date_retour);
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
/* Entrées : Adresse de liste d'emprunts, Date de recherche     */
/* Sortie : Adresse d'une cellule d'emprunts                    */
/*                                                              */
/* Fonction de recherche du premier emprunt à rendre après      */
/* la date passée en paramètre de la fonction                   */
/****************************************************************/
liste_emprunt_t * RechercheEmprunt(liste_emprunt_t * dates, long date_retour)
{
    liste_emprunt_t * prec; // pointeur de parcours de la liste des emprunts
    prec = dates;
    while(*prec != NULL && date_retour > (*prec)->date_retour)
    {
        prec = &((*prec)->suiv);
    }
    return prec;

}

/****************************************************************/
/* Fonction : Recherche de livre                                */
/* Entrées : Liste de catégories, Nom de la catégorie,          */
/*           Numéro du livre                                    */
/* Sortie : Pointeur sur le livre exact (ou le précédent)       */
/*                                                              */
/* Fonction de recherche de livre. La catégorie et le numéro    */
/* du livre sont passés en paramètres. La fonction retourne un  */
/* pointeur sur le livre trouvé ou le précédent du numéro       */
/* jamais le livre recherché n'existe pas                       */
/****************************************************************/
liste_livres_t * RechercheLivre(liste_categories_t biblio, char nom[4], int numero)
{
    liste_categories_t cour = biblio; // pointeur de parcours de la liste des catégories
    liste_livres_t * prec = NULL; // pointeur de parcours de la liste des livres associée à la catégorie
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
/* Sortie : Adresse de la liste d'emprunts,                     */
/*            Code de retour                                    */
/*          (0 Ok, 1 Livre introuvable, 2 Livre déjà emprunté,  */
/*          3 Plus de place dans la mémoire)                    */
/*                                                              */
/* Fonction d'insertion d'emprunt, en respectant le tri de la   */
/*   liste selon la date de retour                              */
/****************************************************************/
void InsererEmprunt(liste_categories_t liste, liste_emprunt_t * dates, char nom[4], int numero, long date_retour, int * code)
{
    liste_livres_t * adr = RechercheLivre(liste, nom, numero); // pointeur de la cellule correspondant au livre que l'on veut insérer
    if (*adr && (*adr)->numero == numero)
    {
        if ((*adr)->disponible == 1) 
        {
            emprunt_t * maillon = (emprunt_t *) malloc(sizeof(emprunt_t));
            if (maillon)
            {
                liste_emprunt_t * ptr = RechercheEmprunt(dates, date_retour); // pointeur de la cellule qui va être juste après celle que l'on va insérer

                strcpy(maillon->nom, nom);
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

/****************************************************************/
/* Procédure : Suppression d'un emprunt                         */
/* Entrées    : Liste des catégories, Adresse                   */
/*              de la liste des emprunts,                       */
/*              Nom de la catégorie du livre emprunté,          */
/*              numéro du livre emprunté,                       */
/*              date de retour du livre emprunté                */
/* Sortie    : Adresse de la liste des emprunts,                */
/*             Code de retour : 0 si ok, 1 si livre introuvable,*/
/*             2 si livre non emprunté, 3 si date de rendu      */
/*             incorrecte                                       */
/*                                                              */
/* Procédure qui supprime une cellule emprunt                   */
/****************************************************************/

void SupprimerEmprunt (liste_categories_t liste, liste_emprunt_t * dates, char nom[4], int numero, long date_retour, int * code)
{
    emprunt_t * tmp; // pointeur temporaire de la cellule que l'on va libérer

    liste_livres_t * adr = RechercheLivre(liste, nom, numero); // pointeur de la cellule correspondant au livre que l'on va emprunté

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

/****************************************************************/
/* Procédure : Libération de la liste des emprunts              */
/* Entrée    : Liste des emprunts                               */
/* Sortie    : Aucune                                           */
/*                                                              */
/* La procédure rend la mémoire utilisée pour stocker la        */
/* liste des emprunts                                           */
/****************************************************************/

void LibererEmprunts(liste_emprunt_t dates)
{
    liste_emprunt_t cour = dates; // pointeur de parcours de la liste des emprunts
    liste_emprunt_t tmp; // pointeur temporaire de la cellule que l'on va libérer
    while (cour)
    {
        tmp = cour;
        cour = cour->suiv;
        free(tmp);
    }
}