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
} maillon, *liste_mots_t;


/**********************************************************/
/* Fonction de hachage d'une chaine de caractères         */
/* Entrée : chaîne de caractères                          */
/* Sortie : hash de la chaine de caractères               */
/**********************************************************/
unsigned int 	hash_string (const char *str);

/**********************************************************/
/* Procédure d'initialisation de la table majeure         */
/* Entrée : Code valant 0                                 */
/* Sortie : liste contigüe de listes chaînées de mots     */
/*			Code (0 si ok, 2 si erreur)					  */
/* La procédure fait en sorte que la table de hachage	  */
/* soit de longueur HASH_MAX et ne contienne que données  */
/* cases contenant NULL. 								  */
/**********************************************************/
liste_mots_t * 	InitialiserTable(int *);

/**********************************************************/
/* Procédure de lecture de mot dans un fichier            */
/* Entrée : fichier dans lequel lire                      */
/* Entrée/Sortie : chaîne de caractère qui est le mot     */
/* Sortie : fin, pour savoir si le fichier est fini       */
/*														  */
/* La procédure lit un mot dans le fichier et le stocke   */
/* dans une variable donnée en paramètre.				  */
/**********************************************************/
void		    LireMot(FILE *, char *, int *);

/**********************************************************/
/* Procédure d'insertion en tête d'un mot dans une liste  */
/* chaînée.                                               */
/* Entrée : mot à insérer                                 */
/* Entrée/Sortie : liste chaînée dans laquel insérer      */
/* Sortie : Code de retour (1 si erreur)                  */
/* 														  */
/* La procédure alloue de la mémoire pour créer un bloc   */
/* contenant le mot et l'insère en tête de liste   	      */
/**********************************************************/
void 			InsererEnTete(liste_mots_t *, char *, int *);

/**********************************************************/
/* Fonction de recherche de mot dans une liste chaînée    */
/* Entrée : liste chaînée dans laquelle rechercher le mot */         	                 
/* Sortie : adresse vers le maillon trouvé (ou NULL)      */
/*														  */
/* La fonction renvoie le maillon ayant pour champ "mot"  */
/* le mot en question. Elle renvoie NULL si un tel maillon*/
/* n'existe pas											  */
/**********************************************************/
maillon * 		RechercheMot(liste_mots_t, char *);

/**********************************************************/
/* Procédure de traitement d'un mot 				      */
/* Entrée : Mot à traiter 								  */         	                 
/* Entrées/Sorties : Table de hachage				      */
/*					 Code de retour (1 si erreur)		  */
/*														  */
/* La procédure traite le mot fournie, c'est-à-dire soit  */
/* elle insère le mot dans une liste chaînée de la table  */
/* de hachage (l'indice étant donnée par la fonction de   */
/* hachage), soit elle augmente le nombre d'occurrence de */
/* ce mot de 1.											  */
/**********************************************************/
void 			TraiterMot(liste_mots_t **, char *, int *);

/**********************************************************/
/* Procédure de traitement de la table de hachage	      */
/* Entrée : Fichier texte à lire 						  */         	                 
/* Entrée/Sortie : Table de hachage					      */
/*														  */
/* La procédure initialise d'abord la table de hachage,	  */
/* puis elle lit le texte fournie pour insérer tous les   */
/* mots dans la table de hachage. Si une erreur survient, */
/* elle avertit l'utilisateur.							  */
/**********************************************************/
void 			Traitement(liste_mots_t **, FILE *);

/**********************************************************/
/* Procédure d'affichage d'une liste chaînée	          */
/* Entrée : Liste chaînée à afficher 					  */         	                 
/*														  */
/* La procédure affiche tous les mots contenus dans la    */
/* liste ainsi que leur nombre d'apparition dans le texte */
/* lu.  												  */
/**********************************************************/
void 			AfficherListeChainee(liste_mots_t);

/**********************************************************/
/* Procédure d'affichage de la table de hachage	          */
/* Entrée : Table à afficher 		 					  */         	                 
/*														  */
/* La procédure affiche tous les mots contenus dans la 	  */
/* tabe ainsi que leur nombre d'apparition dans le texte  */
/* lu. Pour chaque mot elle indique également dans quelle */
/* case de la table il appartient.						  */
/**********************************************************/
void 			AfficherTable(liste_mots_t *);

/**********************************************************/
/* Procédure de libération de la liste chaînée	          */
/* Entrée/Sortie : Liste à libérer 		 				  */         	                 
/*														  */
/* La procédure libère la liste chaînée entière pour      */
/* rendre la mémoire allouée.							  */
/**********************************************************/
void 			LibererListeChainee(liste_mots_t);

/**********************************************************/
/* Procédure de libération de la table 			          */
/* Entrée/Sortie : Table à libérer 		 				  */         	                 
/*														  */
/* La procédure libère la table entière pour rendre la 	  */
/* mémoire allouée. Pour se faire elle libère toutes les  */
/* sous listes chaînées, puis la table majeure			  */
/**********************************************************/
void 			LibererTable(liste_mots_t * table_hash);



#endif