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
/* Entrée : Taille souhaité					 	*/
/* Sortie : Adresse de la pile créé 			*/
/*												*/
/* Initialise une nouvelle pile de taille 		*/
/* passée en paramétre 							*/
/************************************************/
Pile_t * 	InitPile(int);

/************************************************/
/* Procédure : Libération de la Pile 		 	*/
/* Entrée : Pile à libérer (par adresse)	 	*/
/* Sortie : Aucune					 			*/
/*												*/
/* Libére entiérement l'espace mémoire lié 		*/
/* à la pile à libérer							*/
/************************************************/
void 		LibererPile(Pile_t *);

/************************************************/
/* Fonction : Vérification si la pile est vide 	*/
/* Entrée : Pile à vérifier (par copie)			*/
/* Sortie : Vrai si la sommet est égal à -1 	*/
/* 			Sinon Faux 							*/
/*												*/
/* Renvoie Vrai si la pile est vide sinon Faux	*/
/************************************************/
int 		EstVide(Pile_t);

/************************************************/
/* Procédure : Empiler un élément dans la pile 	*/
/* Entrée : - Pile concernée (par copie)		*/
/* 			- Valeur/Variable à empiler 		*/
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succés de l'empilement 		*/
/*			- 1 : Ne peut pas empiler			*/
/*												*/
/* Empile une variable dans la pile 			*/
/************************************************/
int 		Empiler(Pile_t, std_type_t);

/************************************************/
/* Procédure : Dépiler un élément de la pile 	*/
/* Entrée : - Pile concernée (par adresse)		*/
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succés de l'empilement 		*/
/*			- 2 : Ne peut pas dépiler			*/
/*			Adresse de la valeur/variable 		*/
/*			(NULL si impossibilité de dépiler)  */
/*												*/
/* Dépile une variable de la pile 				*/
/************************************************/
int 		Depiler(Pile_t, std_type_t *);