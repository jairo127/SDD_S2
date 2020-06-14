/********************************************/
/* Fichier "table.c"                     	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient le comportement des fonctions	*/
/* définis dans le fichier "table.h"     	*/
/********************************************/

#include "table.h"

unsigned int hash_string (const char *str)
{ 
  unsigned int hash = 5381;             /*  fonction de hachage de D.J. Bernstein*/
  const char *s;
  for (s = str; *s; s++)
 	 hash = ((hash << 5) + hash) + tolower(*s);
  return (hash & 0x7FFFFFFF) %HASH_MAX;
}

liste_mots_t * InitialiserTable(void)
{
	int i;

	liste_mots_t * table = (liste_mots_t *) malloc(sizeof(liste_mots_t)*HASH_MAX);

	for (i=0;i<HASH_MAX;i++)
	{
		table[i] = NULL;
	}

	return table;
}

void LireMot(FILE * fichier, char * mot, int * fin)
{
	int i = 0;
	char lettre;
	
	fscanf(fichier, "%c", &lettre);
	if (!feof(fichier))
	{
		do
		{
			mot[i] = lettre; i++;
			fscanf(fichier, "%c", &lettre);
		} while (lettre != ' ' && lettre != '.');
	
		if (lettre == '.')
		{
			fscanf(fichier, "%c", &lettre);
		}
	
		mot[i] = '\0';
	}
	else
	{
		*fin = 1;
	}
}