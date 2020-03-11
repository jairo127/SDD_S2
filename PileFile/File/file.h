/********************************************/
/* Fichier "file.c"                     	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient lesè déclaration des fonctions	*/
/* et la structure de données de la file    */
/********************************************/

#ifndef FILE_H
#define FILE_H

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
/* passée en paramètre 							*/
/************************************************/
File_t * 	InitFile(const int);

/************************************************/
/* Procédure : Affichage de la File 		 	*/
/* Entrée : File							 	*/
/* Sortie : Aucun 								*/
/*												*/
/* Affiche la file passée en paramètre  		*/
/* (sert pour le débuggage) 					*/
/************************************************/
void 		AfficherFile(const File_t);

/************************************************/
/* Procédure : Libération de la File 		 è	*/
/* Entrée : File à libérer (par adresse)	 	*/
/* Sortie : Aucune					 			*/
/*												*/
/* Libère entièrement l'espace mémoire lié 		*/
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
int 		EstVide(const File_t);

/************************************************/
/* Procédure : Enfiler un élément dans la file 	*/
/* Entrée : - Adresse de la file concernée 		*/
/* 			- Valeur/Variable à enfiler 		*/
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succés de l'enfilement  		*/
/*			- 1 : Ne peut pas enfiler			*/
/*												*/
/* Enfile une variable dans la file 			*/
/************************************************/
int 		Enfiler(File_t *, std_type_t);

/************************************************/
/* Procédure : Défiler un élément de la file 	*/
/* Entrée : - Adresse de la file concernée      */
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succés du défilement 	 		*/
/*			- 2 : Ne peut pas défiler			*/
/*			Adresse de la valeur/variable 		*/
/*			(NULL si impossibilité de défiler)  */
/*												*/
/* Défile une variable de la file 				*/
/************************************************/
int 		Defiler(File_t *, std_type_t *);

#endif