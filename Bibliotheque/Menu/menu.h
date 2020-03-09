#ifndef MENU_H
#define MENU_H

#include "../Biblio/biblio.h"
#include "../Listes/listes.h"
#include "../Dates/dates.h"


/****************************************************************/
/* Procédure : Affichage du menu                                */
/* Entrée    : Aucune                                           */
/* Sortie    : Aucune                                           */
/*                                                              */
/* Affiche le menu principal                                    */
/****************************************************************/
void    AfficherMenu();

/****************************************************************/
/* Fonction  : Gestion du choix                                 */
/* Entrée    : Aucune                                           */
/* Sortie    : Entier                                           */
/*                                                              */
/* Demande à l'utilisateur un entier correspondant à son choix  */
/* (cf AfficherMenu), et enregistre cette valeur                */
/****************************************************************/
int     GestionChoix();

/****************************************************************/
/* Fonction : Réalisation des emprunts à partir du fichier      */
/*            des emprunts                                      */
/* Entrée    : Liste des catégories, adresse de la liste des    */
/*             emprunts, nom du fichier associé                 */
/* Sortie    : Adresse de la liste des emprunts                 */
/*                                                              */
/* La procédure met à jour la liste des emprunts                */
/* en insérant des emprunts à partir du fichier associé         */
/****************************************************************/
void    Emprunter(liste_categories_t, liste_emprunt_t *, char [20]);

/****************************************************************/
/* Procédure : Réalisation des rendus à partir du fichier       */
/*             des rendus                                       */
/* Entrée    : Liste des catégories, adresse de la liste des    */
/*               emprunts, nom du fichier associé               */
/* Sortie    : Adresse de la liste des emprunts                 */
/*                                                              */
/* La procédure met à jour la liste des emprunts en             */
/* supprimant des emprunts à l'aide du fichier associé          */
/****************************************************************/
void    Rendre(liste_categories_t, liste_emprunt_t *, char [20]);

/****************************************************************/
/* Fonction  : Récupération de l'année dans une date            */
/* Entrée    : Date (sous format aaaammjj)                      */
/* Sortie    : Année                                            */
/*                                                              */
/* Récupère l'année de la date passée en paramètre              */
/****************************************************************/
long    RecupAnnee(long);

/****************************************************************/
/* Fonction  : Récupération du mois    dans une date            */
/* Entrée    : Date (sous format aaaammjj)                      */
/* Sortie    : Mois                                             */
/*                                                              */
/* Récupère le mois de la date passée en paramètre              */
/****************************************************************/
long    RecupMois(long);

/****************************************************************/
/* Fonction  : Récupération du jour    dans une date            */
/* Entrée    : Date (sous format aaaammjj)                      */
/* Sortie    : Jour                                             */
/*                                                              */
/* Récupère le jour de la date passée en paramètre              */
/****************************************************************/
long    RecupJour(long);

/****************************************************************/
/* Procédure : Impression des emprunts dont la date de retour   */
/*             est inférieure à une date passée en paramètre    */
/* Entrée    : Liste des emprunts, date                         */
/* Sortie    : Aucune                                           */
/*                                                              */
/* La procédure affiche la catégorie, le numéro et la date      */
/* de retour des livres qui doivent être rendus avant la date   */
/* passée en paramètre                                          */
/****************************************************************/
void    Imprimer(liste_emprunt_t, long);

/****************************************************************/
/* Procédure : Sauvegarder dans un fichier l'état courant       */
/*             des emprunts                                     */
/* Entrée    : Liste des emprunts, fichier                      */
/* Sortie    : Aucune                                           */
/*                                                              */
/* Dans le fichier passée en paramètre figureront les           */
/* différentes catégories, numéros et date de retour des livres */
/* actuellement empruntés                                       */
/****************************************************************/
void    SauvegarderEmprunts(liste_emprunt_t, FILE *);

#endif
