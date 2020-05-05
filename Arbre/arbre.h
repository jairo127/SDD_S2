/*******************************************/
/* Fichier "arbre.h"          			   */
/* William Garrier - Valentin Guien 	   */
/*										   */
/* Contient les declarations des fonctions */
/* et la structure de donnees des arbres   */
/*******************************************/

#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 1023 // Longueur max de la notation algebrique indiquee dans le fichier 

/************************************************/
/* Type standard utilise pour adapter l'arbre 	*/
/* a tout type de variable a stocker			*/
/* Remplacer int par le type voulu				*/
/************************************************/
typedef int std_type_t;

typedef struct arbre
{
	std_type_t sommet;
	struct arbre * fils;
	struct arbre * frere;
} arbre_t;


/****************************************************************/
/* Fonction : Creation de la chaine de caractere a partir		*/
/*			  de la notation algebrique 			 			*/
/* Entrée : Adresse du fichier 									*/
/* Sortie : Pointeur de tete de la chaine    					*/
/* 																*/
/* Cette fonction lit la notation algebrique contenue dans le	*/
/* fichier et retourne la chaine de caracteres associe			*/
/****************************************************************/

char *  CreerChaine(FILE *);



#endif