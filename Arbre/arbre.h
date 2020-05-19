/*******************************************/
/* Fichier "arbre.h"          			   */
/* William Garrier - Valentin Guien 	   */
/*										   */
/* Contient les declarations des fonctions */
/* et la structure de donnees des arbres   */
/*******************************************/

#ifndef ARBRE_H
#define ARBRE_H

#include "type_arbre.h"
#include "pile.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 1023 // Longueur max de la notation algebrique indiquee dans le fichier 
#define CAPACITE_MAX 255 // Capacite max de la pile





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

void	Insertion(std_type_arbre_t, Arbre_t **);

Arbre_t * CreerArbre(char * chaine);

void      ParcoursArbre(Arbre_t *);

void ConvertStr(char **);

#endif