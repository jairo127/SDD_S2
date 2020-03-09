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

#include "../Biblio/biblio.h"

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
/* Entrées : Adresse de liste d'emprunts, Date de recherche     */
/* Sortie : Adresse d'une cellule d'emprunts                    */
/*                                                              */
/* Fonction de recherche du premier emprunt à rendre après      */
/* la date passée en paramètre de la fonction                   */
/****************************************************************/
liste_emprunt_t * RechercheEmprunt (liste_emprunt_t *, long);

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
liste_livres_t  * RechercheLivre   (liste_categories_t, char[4], int);

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
void              InsererEmprunt   (liste_categories_t, liste_emprunt_t *, char[4], int, long, int *);

/****************************************************************/
/* Procédure : Suppression d'un emprunt                         */
/* Entrées    : Liste des catégories, Adresse                   */
/*              de la liste des emprunts,						*/
/*              Nom de la catégorie du livre emprunté,			*/
/*              numéro du livre emprunté,						*/
/*              date de retour du livre emprunté                */
/* Sortie    : Adresse de la liste des emprunts,				*/
/*             Code de retour : 0 si ok, 1 si livre introuvable,*/
/*             2 si livre non emprunté, 3 si problème mémoire   */
/*                                                              */
/* Procédure qui supprime une cellule emprunt                   */
/****************************************************************/
void              SupprimerEmprunt (liste_categories_t, liste_emprunt_t *, char[4], int, long, int *);

/****************************************************************/
/* Procédure : Libération de la liste des emprunts              */
/* Entrée    : Liste des emprunts                               */
/* Sortie    : Aucune                                           */
/*                                                              */
/* La procédure rend la mémoire utilisée pour stocker la        */
/* liste des emprunts                                           */
/****************************************************************/
void              LibererEmprunts  (liste_emprunt_t);

#endif
