/********************************************/
/* Fichier "pile.h"                     	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient les déclarations des fonctions	*/
/* et la structure de données de la pile    */
/********************************************/

#ifndef PILE
#define PILE

#include <stdio.h>
#include <stdlib.h>

#include "type_arbre.h"

/************************************************/
/* Structure de données : Pile_t 			 	*/
/* - capacite : Capacité max de la pile			*/
/* - sommet : Sommet de la pile 				*/
/* - base : Zone d'empilement de la structure 	*/
/************************************************/
typedef struct pile
{
	int 		        	capacite;
	int 		        	sommet;
	std_type_pile_t 	  *	base;
} Pile_t;

/************************************************/
/* Fonction : Initialisation de la Pile 	 	*/
/* Entrée : Taille souhaitée				 	*/
/* Sortie : Adresse de la pile créée 			*/
/*												*/
/* Initialise une nouvelle pile de taille 		*/
/* passée en paramètre 							*/
/************************************************/
Pile_t * 	InitPile(const int);

/************************************************/
/* Procédure : Libération de la Pile 		 	*/
/* Entrée : Pile à libérer (par adresse)	 	*/
/* Sortie : Aucune					 			*/
/*												*/
/* Libére entièrement l'espace mémoire lié 		*/
/* à la pile à libérer							*/
/************************************************/
void 		LibererPile(Pile_t **);

/************************************************/
/* Fonction : Vérification si la pile est vide 	*/
/* Entrée : Pile à vérifier (par copie)			*/
/* Sortie : Vrai si la sommet est égal à -1 	*/
/* 			Sinon Faux 							*/
/*												*/
/* Renvoie Vrai si la pile est vide sinon Faux	*/
/************************************************/
int 		EstVidePile(Pile_t);

/************************************************/
/* Procédure : Empiler un élément dans la pile 	*/
/* Entrée : - Pile concernée (par copie)		*/
/* 			- Valeur/Variable à empiler 		*/
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succès de l'empilement 		*/
/*			- 1 : Ne peut pas empiler			*/
/*												*/
/* Empile une variable dans la pile 			*/
/************************************************/
int 		Empiler(Pile_t *, std_type_pile_t);

/************************************************/
/* Procédure : Dépiler un élément de la pile 	*/
/* Entrée : - Pile concernée (par adresse)		*/
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succès du dépilement 			*/
/*			- 2 : Ne peut pas dépiler			*/
/*			Adresse de la valeur/variable 		*/
/*			(NULL si impossibilité de dépiler)  */
/*												*/
/* Dépile une variable de la pile 				*/
/************************************************/
int 		Depiler(Pile_t *, std_type_pile_t *);

/************************************************/
/* Procédure DEBUG : Afficher la pile 			*/
/* Entrée : - Pile à afficher (par copie)		*/
/* Sortie : Aucune 								*/
/*												*/
/* Affiche les éléments présents dans la pile 	*/
/* de bas en haut (utilisé seulement pour du 	*/
/* débug)										*/
/************************************************/
void		AfficherPile(const Pile_t);

#endif