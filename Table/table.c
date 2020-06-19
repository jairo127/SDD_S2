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

void InsererEnTete(liste_mots_t * liste, char * mot, int * code)
{
	maillon * bloc = (maillon *) malloc(sizeof(maillon));
	if (bloc)
	{
		strcpy(bloc->mot, mot);
		bloc->occurrence = 1;

		bloc->suiv = *liste;
		*liste = bloc;
	}
	else
	{
		*code = 1;
	}
}

maillon * RechercheMot(liste_mots_t liste, char * mot)
{
	maillon * cour = liste;

	
	while (cour && strcmp(cour->mot,mot))
	{
		cour = cour->suiv;

	}

	return cour;
}

void TraiterMot(liste_mots_t ** table_hash, char * mot, int * code)
{
	unsigned int indice = hash_string(mot);
	liste_mots_t liste = *table_hash[indice];

	maillon * bloc = RechercheMot(liste,mot);


	if (bloc)
	{
		bloc->occurrence += 1;
	}
	else
	{
		InsererEnTete(&liste, mot, code);
	}

}

void Traitement(liste_mots_t ** table_hash, FILE * fichier)
{
	char mot[LONGUEUR_MAX];
	int fin = 0;
	int code = 0;

	*table_hash = InitialiserTable();

	while (!fin && !code)
	{
		LireMot(fichier, mot, &fin);

		TraiterMot(table_hash, mot, &code);

		if (code)
		{
			printf("Probleme de lecture d'un mot. Arret\n");
		}
	}
}