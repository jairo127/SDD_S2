/********************************************/
/* Fichier "pile.c"                     	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient le comportement des fonctions	*/
/* définis dans le fichier "pile.h"     	*/
/********************************************/

#include "pile.h"

/************************************************/
/* Fonction : Initialisation de la Pile 	 	*/
/* Entrée : Taille souhaitée				 	*/
/* Sortie : Adresse de la pile créée 			*/
/*												*/
/* Initialise une nouvelle pile de taille 		*/
/* passée en paramétre 							*/
/************************************************/
Pile_t * 	InitPile(const int taille)
{
	Pile_t * pile = (Pile_t *) malloc(sizeof(Pile_t)); // Pile
	
	if (pile)
	{
		pile->base = (std_type_t *) malloc(sizeof(std_type_t) * taille);
		
		if (pile->base)
		{
			pile->capacite = taille;
			pile->sommet = -1;
		}
		else
		{
			free(pile);
			pile = NULL;
		}
	}

	return pile;
}

/************************************************/
/* Procédure : Libération de la Pile 		 	*/
/* Entrée : Pile à libérer (par adresse)	 	*/
/* Sortie : Aucune					 			*/
/*												*/
/* Libère entièrement l'espace mémoire lié 		*/
/* à la pile à libérer							*/
/************************************************/
void 		LibererPile(Pile_t ** pile)
{
	free((*pile)->base);
	free(*pile);
	*pile = NULL;
}

/************************************************/
/* Fonction : Vérification si la pile est vide 	*/
/* Entrée : Pile à vérifier (par copie)			*/
/* Sortie : Vrai si la sommet est égal à -1 	*/
/* 			Sinon Faux 							*/
/*												*/
/* Renvoie Vrai si la pile est vide sinon Faux	*/
/************************************************/
int 		EstVide(const Pile_t pile)
{
	return (pile.sommet == -1);
}

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
int 		Empiler(Pile_t * pile, std_type_t var)
{
	int code = 1; // Code de retour

	if (pile->sommet < pile->capacite - 1)
	{
		pile->sommet = pile->sommet + 1;
		pile->base [pile->sommet] = var;
		code = 0;
	}
	return code;
}

/************************************************/
/* Procédure : Dépiler un élément de la pile 	*/
/* Entrée : - Pile concernée (par adresse)		*/
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succès de l'empilement 		*/
/*			- 2 : Ne peut pas dépiler			*/
/*			Adresse de la valeur/variable 		*/
/*			(NULL si impossibilité de dépiler)  */
/*												*/
/* Dépile une variable de la pile 				*/
/************************************************/
int 		Depiler(Pile_t * pile, std_type_t * adr_var)
{
	int code = 2; // Code de retour

	if (!EstVide(*pile))
	{
		*adr_var = pile->base [pile->sommet];
		pile->sommet = pile->sommet - 1;
		code = 0;
	}

	return code;
}

/************************************************/
/* Procédure DEBUG : Afficher la pile 			*/
/* Entrée : - Pile à afficher (par copie)		*/
/* Sortie : Aucune 								*/
/*												*/
/* Affiche les éléments présents dans la pile 	*/
/* de bas en haut (utilisé seulement pour du 	*/
/* débug et quand la pile utilise des int)		*/
/************************************************/
void		AfficherPile(const Pile_t pile)
{
	int i; // Compteur de boucle

	for(i=0 ; i<=pile.sommet ; i++)
	{
		printf("%d ", pile.base [i]);
	}
	printf("\n");
}