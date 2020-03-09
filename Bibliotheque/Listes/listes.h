#ifndef LISTES_H
#define LISTES_H

#include "../Biblio/biblio.h"


/* Gestion d'une liste chainee a tete reelle */


/* Fonctions de gestion */

/****************************************************************/
/* Procédure : Affichage de la bibliothèque			            */
/* Entrée    : Liste d'emprunts					                */
/* Sortie    : Aucune						                    */
/*					                                 			*/
/* La procédure affiche chaque maillon de la liste d'emprunts   */
/****************************************************************/
void             AfficherBiblio     (liste_categories_t);

/****************************************************************/
/* Procédure : Insertion d'un livre après une adresse           */
/* Entrées   : - Adresse d'une cellule livre                    */
/*             - Numéro du livre à insérer                      */
/*             - Titre du livre à insérer                       */
/*                                                              */
/* Sortie    : - Adresse de la cellule livre                    */
/*             - Code de retour : 0 si ok                       */
/*                                1 si problème d'allocation    */
/*                                                              */
/* Procédure qui insère après une adresse prec donnée une       */
/* cellule livre_t dont les champs sont spécifiés dans les      */
/* paramètres                                                   */
/****************************************************************/
void             InsererApresAdr    (liste_livres_t *, int, char *, int *);

/****************************************************************/
/* Procédure : Insertion en tête de la liste des catégories     */
/* Entrées   : - Adresse de la liste des catégories             */
/*             - Nom de la catégorie à insérer                  */
/*             - Liste de livres la catégorie à insérer         */
/*                                                              */
/* Sortie    : - Adresse de la liste des catégories             */
/*             - Code de retour : 0 si ok                       */
/*                                1 si problème d'allocation    */
/*                                                              */
/* La procédure insère en tête de la liste des catégories       */
/* une nouvelle cellule categories_t, dont les champs sont      */
/* spécifiés dans les paramètres                                */
/****************************************************************/
void             InsererEnTete      (liste_categories_t *, char * , liste_livres_t, int *);

/******************************************************************/
/* Procédure : Remplissage de la bibliothèque à partir du fichier */
/* Entrée    : - Fichier contenant les différents livres          */
/*                                                                */
/* Sorties   : - Liste des catégories, ie la bibliothèque associée*/
/*             - Code de retour : 0 si ok                         */
/*                                1 si problème d'insertion       */
/*                                due à une allocation ratée      */
/*                                                                */
/* La procédure met en place la liste des catégories à partir du  */
/* fichier fourni, contenant les divers livres et leurs attributs */
/******************************************************************/
void             RemplirListe       (FILE *, liste_categories_t *, int *);

/****************************************************************/
/* Procédure : Libération d'une liste de livres                 */
/* Entrée    : Liste de livres                                  */
/* Sortie    : Aucune                                           */
/*                                                              */
/* Procédure qui libère une liste chaînée des livres (pointée   */
/* par le champ d'une cellule categories_t)                     */
/*                                                              */
/****************************************************************/
void             LibererListeLivre  (liste_livres_t);

/****************************************************************/
/* Procédure : Libération de la bibliothèque                    */
/* Entrée    : Liste des catégories, ie la bibliothèque         */
/* Sortie    : Aucune                                           */
/*                                                              */
/* La procédure rend toute la mémoire qui a été allouée pour    */
/* la bibliothèque libérant chaque cellule categories_t, et pour*/
/* chacune de ces cellules la liste de livres associée          */
/****************************************************************/
void             LibererBibliotheque(liste_categories_t);

#endif