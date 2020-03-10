/****************************************************************/
/* Fichier : biblio.h 							 				*/
/* 							 									*/
/* Auteurs : Valentin Guien - William Garrier 					*/
/* 																*/
/* Fichier contenant les structures de données des listes 		*/
/* chaînées de livres et de catégories ainsi que les 			*/
/* déclarations des fonctions d'ouverture et de lecture 		*/
/* du fichier texte de stockage des données de la 				*/
/* bibliothéque.												*/
/****************************************************************/

#ifndef BIBLIO_H
#define BIBLIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100

/****************************************************************/
/* Structure de données : Liste chaînée de livres 				*/
/* - numero : Numéro du livre 									*/
/* - titre : Titre du livre sur 10 caractères 					*/
/* - disponible : 1 si le livre est disponible pour l'emprunt 	*/
/*   			  0 sinon 										*/
/* - suiv : Pointeur vers le prochain maillon 					*/
/* 			(NULL s'il n'existe pas) 							*/
/* 																*/
/* livres_t : Maillon 											*/
/* liste_livres_t : Pointeur sur maillon 						*/
/* 					(utilisé comme tête réelle) 				*/
/****************************************************************/
typedef struct liste_livres
{
    int                   numero ;
    char                  titre[11] ;
    int                   disponible ;
    struct liste_livres * suiv ;
} livres_t, *liste_livres_t ;

/****************************************************************/
/* Structure de données : Liste chaînée de catégories 			*/
/* - nom : Nom de la catégorie sur 3 caractères 				*/
/* - liste_livres_categories : Liste de livres de la catégorie 	*/
/* - suiv : Pointeur vers le prochain maillon 					*/
/*			(NULL s'il n'existe pas)  							*/
/* 																*/
/* categories_t : Maillon 										*/
/* liste_categories_t : Pointeur sur maillon 					*/
/* 						(utilisé comme tête réelle) 			*/
/****************************************************************/
typedef struct liste_categories 
{
    char                          nom[4];
    liste_livres_t                liste_livres_categorie;
    struct liste_categories *     suiv ;
} categories_t, *liste_categories_t ;

/****************************************************************/
/* Fonction : Ouverture de fichier 					 			*/
/* Entrées : Nom du fichier, mode d'ouverture 					*/
/* Sortie : Adresse du fichier ouvert (NULL si échec) 			*/
/* 			Code de retour -> 0 si échec de l'ouverture 		*/
/* 																*/
/* Fonction chargée d'ouvrir un fichier dont le nom et le mode 	*/
/* d'ouverture sont donnés en paramétre et retourne l'adresse 	*/
/* mémoire du fichier ouvert. 									*/
/****************************************************************/
FILE *        OuvrirFichier(char *, int *, char *);

/****************************************************************/
/* Procédure : Affichage du fichier 				 			*/
/* Entrées : Adresse du fichier 								*/
/* Sortie : Aucune 										 		*/
/* 																*/
/* Cette procédure lit chaque ligne du fichier et les affichent	*/
/* sur la sortie standard. 	 									*/
/****************************************************************/
void          LireDonnees(FILE *);

#endif
