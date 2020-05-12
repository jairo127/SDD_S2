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

void Insertion(std_type_t valeur, arbre_t ** ptr)
{
	arbre_t * maillon = (arbre_t *) malloc (sizeof(arbre_t));
	maillon->lv = NULL; maillon->lh = NULL;

	*ptr = maillon;
}


arbre_t * CreerArbre(char * chaine)
{
	Pile_t * pile = InitPile(CAPACITE_MAX);

	arbre_t * arb = NULL;
	arbre_t ** cour = &arb;

	int n = strlen(chaine);
	int i;

	for (i=0; i<n; i++)
	{
		switch(chaine[i])
		{
			case '*' : 
				break;
			case '(' :
				break;
			case ')' :
				break;
			case '+' :
				break;
			default  :
				Insertion(chaine[i], cour);
				break;
		}
	}

	return arb;
}