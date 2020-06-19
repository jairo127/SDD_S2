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

liste_mots_t * InitialiserTable(int * code)
{
	int i;

	liste_mots_t * table = (liste_mots_t *) malloc(sizeof(liste_mots_t)*HASH_MAX);
	if (table)
	{
		for (i=0;i<HASH_MAX;i++)
		{
			table[i] = NULL;
		}
	}
	else
	{
		*code = 2;
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
		mot[0] = tolower(mot[0]);
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

	maillon * bloc = RechercheMot((*table_hash)[indice],mot);


	if (bloc)
	{
		bloc->occurrence += 1;
	}
	else
	{
		InsererEnTete(&(*table_hash)[indice], mot, code);
		printf("%s\n", (*table_hash)[indice]->mot);
	}
}

void Traitement(liste_mots_t ** table_hash, FILE * fichier)
{
	char mot[LONGUEUR_MAX];
	int fin = 0;
	int code = 0;

	*table_hash = InitialiserTable(&code);

	while (!fin && !code)
	{
		LireMot(fichier, mot, &fin);

		if (fin == 0)
		{

			TraiterMot(table_hash, mot, &code);

			if (code)
			{
				printf("Probleme de lecture d'un mot. Arret\n");
			}
		}
	}
	if (code==2)
	{
		printf("Erreur, la table n'a pas pu être créée.");
	}
}

void AfficherListeChainee(liste_mots_t liste)
{
	maillon * cour = liste;
	while(cour)
	{
		printf("Mot : %s ; Occurrence : %d\n", cour->mot, cour->occurrence);
		cour = cour->suiv;
	}
}

void AfficherTable(liste_mots_t * table_hash)
{
	int i;

	for (i=0;i<HASH_MAX;i++)
	{
		if (table_hash[i])
		{
			printf("Case n°%d\n", i);
			AfficherListeChainee(table_hash[i]);
		}
	}
}

void LibererListeChainee(liste_mots_t liste)
{
	maillon * prec = liste;
	maillon * temp;

	while(prec)
	{
		temp = prec;
		prec = prec->suiv;
		free(temp);
	}
}

void LibererTable(liste_mots_t * table_hash)
{
	int i;

	for (i=0;i<HASH_MAX;i++)
	{
		LibererListeChainee(table_hash[i]);
	}

	free(table_hash);
}