/********************************************/
/* Fichier "file.c"                     	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient le comportement des fonctions	*/
/* définis dans le fichier "file.h"     	*/
/********************************************/

#include "file.h"

/************************************************/
/* Fonction : Initialisation de la File 	 	*/
/* Entrée : Taille souhaitée				 	*/
/* Sortie : Adresse de la file créée 			*/
/*												*/
/* Initialise une nouvelle file de taille 		*/
/* passée en paramétre 							*/
/************************************************/
File_t * 	InitFile(int taille)
{
	return NULL;
}

/************************************************/
/* Procédure : Libération de la File 		 	*/
/* Entrée : File à libérer (par adresse)	 	*/
/* Sortie : Aucune					 			*/
/*												*/
/* Libére entièrement l'espace mémoire lié 		*/
/* à la file à libérer							*/
/************************************************/
void 		LibererFile(File_t ** file)
{

}

/************************************************/
/* Fonction : Vérification si la file est vide 	*/
/* Entrée : File à vérifier (par copie)			*/
/* Sortie : Vrai si la file est vide à -1 	 	*/
/* 			Sinon Faux 							*/
/*												*/
/* Renvoie Vrai si la file est vide sinon Faux	*/
/************************************************/
int 		EstVide(File_t file)
{
	return -1;
}

/************************************************/
/* Procédure : Enfiler un élément dans la file 	*/
/* Entrée : - File concernée (par copie)		*/
/* 			- Valeur/Variable à enfiler 		*/
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succès de l'enfilement  		*/
/*			- 1 : Ne peut pas enfiler			*/
/*												*/
/* Enfile une variable dans la file 			*/
/************************************************/
int 		Enfiler(File_t file, std_type_t var)
{
	return -1;
}

/************************************************/
/* Procédure : Défiler un élément de la file 	*/
/* Entrée : - File concernée (par copie)		*/
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succès du défilement 	 		*/
/*			- 2 : Ne peut pas défiler			*/
/*			Adresse de la valeur/variable 		*/
/*			(NULL si impossibilité de défiler)  */
/*												*/
/* Défile une variable de la file 				*/
/************************************************/
int 		Defiler(File_t file, std_type_t * var)
{
	return -1;
}
