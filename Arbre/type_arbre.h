/********************************************/
/* Fichier type_arbre.h"                  	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient la structure de données de      */
/* l'arbre et la définition des types       */
/* utilisés dans les piles et les files     */
/********************************************/

#ifndef TYPE_ARBRE
#define TYPE_ARBRE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char std_type_arbre_t; //type utilisé pour l'arbre

typedef struct arbre
{
	std_type_arbre_t sommet;
	struct arbre * lv; // lien vertical
	struct arbre * lh; // lien horizontal
} Arbre_t;

typedef Arbre_t ** std_type_pile_t; //type utilisé pour les piles

typedef Arbre_t ** std_type_file_t; //type utilisé pour les files

#endif