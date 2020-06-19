/********************************************/
/* Fichier table.h 		                  	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient la structure de données de la   */
/* table et les déclarations des fonctions  */
/* liées à la table. 	  				    */
/********************************************/

#ifndef TABLE_H
#define TABLE_H

#define HASH_MAX 29
#define LONGUEUR_MAX 255

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct liste_mots
{
	char 			    mot[LONGUEUR_MAX];
	int 				occurrence;
	struct liste_mots * suiv;
} maillon, *liste_mots_t;   // maillon *  =  liste_mots_t

unsigned int hash_string (const char *str);


liste_mots_t * InitialiserTable(void);

void LireMot(FILE *, char *, int *);

void InsererEnTete(liste_mots_t *, char *, int *);

maillon * RechercheMot(liste_mots_t, char *);

#endif