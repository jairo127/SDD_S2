/*******************************************/
/* Fichier "arbre.c"          			   */
/* William Garrier - Valentin Guien 	   */
/*										   */
/* Contient le comportement des fonctions  */
/* definis dans le fichier "arbre.h"       */
/*******************************************/

#include "arbre.h"

/****************************************************************/
/* Fonction : Creation de la chaine de caractere a partir		*/
/*			  de la notation algebrique 			 			*/
/* Entrée : Adresse du fichier 									*/
/* Sortie : Pointeur de tete de la chaine    					*/
/* 																*/
/* Cette fonction lit la notation algebrique contenue dans le	*/
/* fichier et retourne la chaine de caracteres associe			*/
/****************************************************************/

char * CreerChaine(FILE * fichier)
{
	char * ligne = (char *) malloc(sizeof(char) * TAILLE_MAX); // Pour enregistrer la ligne du fichier

	fscanf(fichier, "%s", ligne);

	return ligne;
}