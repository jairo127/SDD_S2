/****************************************************************/
/* Fichier : dates.h 							 				*/
/* 							 									*/
/* Auteurs : Valentin Guien - William Garrier 					*/
/* 																*/
/* Fichier contenant la structure de données de liste chaîné  	*/
/* d'emprunts ainsi que les fonctions relatives à la 			*/
/* gestion des emprunts 										*/
/****************************************************************/

#ifndef DATES_H
#define DATES_H

#include "biblio.h"

/****************************************************************/
/* Structure de données : Liste chaînée d'emprunts 				*/
/* - nom : Nom de la catégorie sur 3 caractères 				*/
/* - numero : Nom du livre emprunté 							*/
/* - date_retour : Date de retour au plus tard du livre 	 	*/
/* 				   Format : AAAAMMJJ 							*/
/* - suiv : Pointeur vers le prochain maillon 					*/
/*			(NULL s'il n'existe pas)  							*/
/* 																*/
/* emprunt_t : Maillon 											*/
/* liste_emprunt_t : Pointeur sur maillon 						*/
/* 					 (utilisé comme tête réelle) 				*/
/****************************************************************/
typedef struct liste_emprunt 
{
    char                      nom[4];
    int                       numero;
    long                      date_retour;
    struct liste_emprunt *    suiv;
} emprunt_t, *liste_emprunt_t;

/****************************************************************/
/* Procédure : Afficher les emprunts                            */
/* Entrées : Liste d'emprunts                                   */
/* Sortie : Aucune                                              */
/*                                                              */
/* Fonction chargée d'afficher la liste des emprunts            */
/****************************************************************/
void              AfficherDates    (liste_emprunt_t);

/****************************************************************/
/* Fonction : Recherche d'emprunts                              */
/* Entrées : Liste d'emprunts (A), Date de recherche            */
/* Sortie : Liste d'emprunts (B) (A inclus dans B)              */
/*                                                              */
/* Fonction de recherche des emprunts à rendre après la date    */
/* passée en paramétre de la fonction                           */
/****************************************************************/
liste_emprunt_t * RechercheEmprunt (liste_emprunt_t *, long);

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
liste_livres_t  * RechercheLivre   (liste_categories_t, char[4], int);
void              InsererEmprunt   (liste_categories_t, liste_emprunt_t *, char[4], int, long, int *);
void              SupprimerEmprunt (liste_categories_t, liste_emprunt_t *, char[4], int, long, int *);

#endif
