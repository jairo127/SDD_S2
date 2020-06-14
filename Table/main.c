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
	liste_mots_t * table_hash;
	table_hash = InitialiserTable();

	char mot[LONGUEUR_MAX];
	int fin = 0;
	char pio;

	FILE * fichier = fopen("texte","r");
	while (!feof(fichier))
	{
		LireMot(fichier, mot, &fin);
		if (!fin)
		{
			printf("Le mot lu est : %s\n", mot);
		}
	}
	fclose(fichier);

	/*char * strr = "Salut";
	char * str2 = "Coucou";

	printf("Voici le truc : %d\n", hash_string(strr));
	printf("Voici la chose : %d\n", hash_string(str2));
	*/

	return 0;
}