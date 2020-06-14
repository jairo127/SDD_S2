/********************************************/
/* Fichier main.c 		                  	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient les codes d'exécutions des	    */
/* différentes manipulations				*/
/********************************************/

#include "table.h"

int main()
{
	char * strr = "Salut";
	char * str2 = "Coucou";

	printf("Voici le truc : %d\n", hash_string(strr));
	printf("Voici la chose : %d\n", hash_string(str2));

	return 0;
}