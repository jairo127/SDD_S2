/********************************************/
/* Fichier "file.c"                     	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient les déclaration des fonctions	*/
/* et la structure de données de la file    */
/********************************************/

#ifndef FILE
#define FILE

#include <stdio.h>
#include <stdlib.h>

/************************************************/
/* Type standard utilisé pour adapter la file 	*/
/* à tout type de variable à stocker			*/
/* Remplacer int par le type voulu				*/
/************************************************/
typedef int std_type_t;

/************************************************/
/* Structure de données : File_t 			 	*/
/* - capacite : Capacité max de la file			*/
/* - debut : Indice de début de la file 		*/
/* - fin : Indice de fin de la file 			*/
/* - base : Zone d'enfilement de la structure 	*/
/************************************************/
typedef struct file
{
	int 			capacite;
	int 			debut;
	int 			fin;
	std_type_t    * base;
} File_t;

/************************************************/
/* Fonction : Initialisation de la File 	 	*/
/* Entrée : Taille souhaitée				 	*/
/* Sortie : Adresse de la file créée 			*/
/*												*/
/* Initialise une nouvelle file de taille 		*/
/* passée en paramétre 							*/
/************************************************/
File_t * 	InitFile(int);

/************************************************/
/* Procédure : Libération de la File 		 	*/
/* Entrée : File à libérer (par adresse)	 	*/
/* Sortie : Aucune					 			*/
/*												*/
/* Libére entièrement l'espace mémoire lié 		*/
/* à la file à libérer							*/
/************************************************/
void 		LibererFile(File_t **);

/************************************************/
/* Fonction : Vérification si la file est vide 	*/
/* Entrée : File à vérifier (par copie)			*/
/* Sortie : Vrai si la file est vide à -1 	 	*/
/* 			Sinon Faux 							*/
/*												*/
/* Renvoie Vrai si la file est vide sinon Faux	*/
/************************************************/
int 		EstVide(File_t);

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
int 		Enfiler(File_t, std_type_t);

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
int 		Defiler(File_t, std_type_t *);

#endif