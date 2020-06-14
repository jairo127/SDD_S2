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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

unsigned int hash_string (const char *str);


#endif