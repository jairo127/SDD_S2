/*******************************************/
/* Fichier "arbre.h"          			   */
/* William Garrier - Valentin Guien 	   */
/*										   */
/* Contient les declarations des fonctions */
/* liées aux arbres                        */
/*******************************************/

#ifndef ARBRE_H
#define ARBRE_H

#include "type_arbre.h"
#include "pile.h"
#include "file.h"

#define TAILLE_MAX 1023 // Longueur max de la notation algebrique indiquee dans le fichier 
#define CAPACITE_MAX 255 // Capacite max de la pile/file





/****************************************************************/
/* Fonction : Creation de la chaine de caracteres a partir		*/
/*			  de la notation algebrique 			 			*/
/* Entrée : Adresse du fichier 									*/
/* Sortie : Pointeur de tete de la chaine    					*/
/* 																*/
/* Cette fonction lit la notation algebrique contenue dans le	*/
/* fichier et retourne la chaine de caracteres associe			*/
/****************************************************************/

char *     CreerChaine(FILE *);

/****************************************************************/
/* Procedure : Adaptation de la chaine de caracteres pour       */
/*			   pouvoir utiliser la fonction CreerArbre sans bug */
/* Entrée : Adresse de la chaine 								*/
/* Sortie : Aucune												*/
/*																*/
/* Cette procedure fait en sorte que dans la notation algebrique*/
/* si un sommet v n'admet qu'un seul fils w alors l'ecriture    */
/* passera de v*w a v*(w) 										*/
/****************************************************************/

void	   AdaptChaine(char **);

/****************************************************************/
/* Procedure : Insertion d'un sommet dans l'arbre juste         */
/*			   apres l'adresse fournie                          */
/* Entrées : Valeur a inserer, adresse d'insertion       		*/
/* Sortie : Aucune												*/
/*																*/
/* Cette procedure alloue un maillon contenant la valeur donnee */
/* et l'insere juste apres l'adresse donnee						*/
/****************************************************************/

void	   Insertion(std_type_arbre_t, Arbre_t **);

/****************************************************************/
/* Fonction : Creation de l'arbre a partir de la notation		*/
/*			  algebrique (adaptee) contenue dans la chaine 		*/
/* Entrée : Chaine de caractere 								*/
/* Sortie : Pointeur de l'arbre             					*/
/* 																*/
/* Cette fonction lit la notation algebrique contenue dans la	*/
/* chaine adaptee par AdaptChaine et retourne le pointeur de    */
/* l'arbre associee												*/
/****************************************************************/

Arbre_t *  CreerArbre(char * chaine);

/****************************************************************/
/* Procedure : Parcours de l'arbre avec impression des sommets  */
/*			   dans l'ordre postfixe                            */
/* Entrées : Arbre a parcourir  					       		*/
/* Sortie : Aucune												*/
/*																*/
/* Cette procedure realise le parcours de l'arbre et imprime	*/
/* les valeurs des sommets selon l'ordre postfixe				*/
/****************************************************************/

void       ParcoursArbre(Arbre_t *);

/****************************************************************/
/* Fonction : Recherche d'un sommet de l'arbre avec la valeur	*/
/*			  indiquee									 		*/
/* Entrée : Adresse de l'arbre, valeur a rechercher	 			*/
/* Sortie : Adresse du premier sommet trouve					*/
/*			s'il existe, NULL sinon 				 			*/
/* 																*/
/* Cette fonction recherche dans l'arbre un sommet contenant	*/
/* la valeur indiquee. La recherche se fait selon un parcours  	*/
/* en profondeur, et s'arrete au premier sommet trouve. S'il n'y*/
/* a pas de tel sommet, alors la fonction retourne NULL			*/
/****************************************************************/

Arbre_t ** RechercheValeur(Arbre_t *, std_type_arbre_t);

/****************************************************************/
/* Fonction : Recherche du dernier fils d'un sommet indique		*/
/*			  											 		*/
/* Entrée : Adresse du sommet 						 			*/
/* Sortie : Adresse du lh du dernier fils du sommets 			*/
/*			/adresse du lv du sommet s'il n'admet pas de fils	*/
/*													 			*/ 
/* Cette fonction retourne l'adresse de la zone pointeur du 	*/
/* dernier fils, pour pouvoir avec une autre fonction en inserer*/
/* un nouveau. Si le sommet n'admet pas de fils, alors la 		*/
/* fonction retourne l'adresse du lv du sommets 				*/
/****************************************************************/

Arbre_t ** Dernier(Arbre_t **);

/****************************************************************/
/* Fonction : Insertion d'un fils de valeur donnee a un sommet	*/
/* 			  de valeur egalement donnee						*/
/*			  											 		*/
/* Entrée : Adresse de l'arbre, valeurs des sommets fils et pere*/
/* Sortie : Code de retour (1 : insertion reussi, 0 : echec)	*/
/*													 			*/ 
/* Cette fonction recherche d'abord un sommet ayant la valeur   */
/* recherchee, puis, si un tel sommet existe, et concernant     */
/* le premier sommet trouve suivant le parcours en largeur,     */
/* insere un fils a la  zone pointeur de son dernier fils (ou   */
/* de son lv si pas de fils) 									*/
/****************************************************************/

int  	   AjouterFils(Arbre_t *, std_type_arbre_t, std_type_arbre_t);



void	   LibererArbre(Arbre_t **);

#endif