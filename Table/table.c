/********************************************/
/* Fichier "table.c"                     	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient le comportement des fonctions	*/
/* définis dans le fichier "table.h"     	*/
/********************************************/

#include "table.h"


/**********************************************************/
/* Fonction de hachage d'une chaine de caractères         */
/* Entrée : chaîne de caractères                          */
/* Sortie : hash de la chaine de caractères               */
/**********************************************************/
unsigned int hash_string (const char *str)
{ 
  unsigned int hash = 5381;             /*  fonction de hachage de D.J. Bernstein*/
  const char *s;
  for (s = str; *s; s++)
 	 hash = ((hash << 5) + hash) + tolower(*s);
  return (hash & 0x7FFFFFFF) %HASH_MAX;
}


/**********************************************************/
/* Fonction d'initialisation de la table majeure          */
/* Entrée : Code valant 0                                 */
/* Sortie : liste contigüe de listes chaînées de mots     */
/*			Code (0 si ok, 2 si erreur)					  */
/* La fonction fait en sorte que la table de hachage	  */
/* soit de longueur HASH_MAX et ne contienne que données  */
/* cases contenant NULL.								  */
/**********************************************************/
liste_mots_t * InitialiserTable(int * code)
{
	int i; //Parcours de la table

	liste_mots_t * table = (liste_mots_t *) malloc(sizeof(liste_mots_t)*HASH_MAX);
	if (table) 
	{
		for (i=0;i<HASH_MAX;i++)
		{
			table[i] = NULL;
		}
	}
	else // Problème de mémoire, la table n'a pu être créée
	{
		*code = 2;
	}

	return table;
}


/**********************************************************/
/* Procédure de lecture de mot dans un fichier            */
/* Entrée : fichier dans lequel lire                      */
/* Entrée/Sortie : chaîne de caractère qui est le mot     */
/* Sortie : fin, pour savoir si le fichier est fini       */
/*														  */
/* La procédure lit un mot dans le fichier et le stocke   */
/* dans une variable donnée en paramètre.				  */
/**********************************************************/
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
		} while (lettre != ' ' && lettre != '.'); // Tant qu'il n'y a pas de point ou d'espace, on lit
	
		if (lettre == '.') // Après un point il y a un espace
		{
			fscanf(fichier, "%c", &lettre); // Avancer d'un caractère de plus
		}
	
		mot[i] = '\0';
		mot[0] = tolower(mot[0]); // Insensibilité à la casse
	}
	else //Cas à traiter pour éviter une duplication du dernier mot
	{
		*fin = 1;
	}

}

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
void InsererEnTete(liste_mots_t * liste, char * mot, int * code)
{
	maillon * bloc = (maillon *) malloc(sizeof(maillon));
	if (bloc)
	{
		strcpy(bloc->mot, mot);
		bloc->occurrence = 1; // Première apparition du mot

		bloc->suiv = *liste;
		*liste = bloc;
	}
	else // Le bloc n'a pas pu être créé, problème de mémoire
	{
		*code = 1;
	}
}

/**********************************************************/
/* Fonction de recherche de mot dans une liste chaînée    */
/* Entrée : liste chaînée dans laquelle rechercher le mot */         	                 
/* Sortie : adresse vers le maillon trouvé (ou NULL)      */
/*														  */
/* La fonction renvoie le maillon ayant pour champ "mot"  */
/* le mot en question. Elle renvoie NULL si un tel maillon*/
/* n'existe pas											  */
/**********************************************************/
maillon * RechercheMot(liste_mots_t liste, char * mot)
{
	maillon * cour = liste;

	while (cour && strcmp(cour->mot,mot))
	{

		cour = cour->suiv;

	}

	return cour;
}

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
void TraiterMot(liste_mots_t ** table_hash, char * mot, int * code)
{
	unsigned int indice = hash_string(mot);

	maillon * bloc = RechercheMot((*table_hash)[indice],mot);


	if (bloc) // Le mot était déjà présent une fois
	{
		bloc->occurrence += 1;
	}
	else // Première apparition du mot
	{
		InsererEnTete(&(*table_hash)[indice], mot, code);
	}
}

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
void Traitement(liste_mots_t ** table_hash, FILE * fichier)
{
	char mot[LONGUEUR_MAX];
	int fin = 0;
	int code = 0;

	*table_hash = InitialiserTable(&code); // Initialisation de la table

	while (!fin && !code)
	{
		LireMot(fichier, mot, &fin);

		if (fin == 0) // Nécessaire pour éviter la duplication du dernier mot
		{

			TraiterMot(table_hash, mot, &code);

			if (code) // Une insertion n'a pas pu être faite
			{
				printf("Erreur, pas assez de mémoire pour allouer. Arret\n");
			}
		}
	}
	if (code==2) // L'initialisation de la table a échoué
	{
		printf("Erreur, la table n'a pas pu être créée.");
	}
}

/**********************************************************/
/* Procédure d'affichage d'une liste chaînée	          */
/* Entrée : Liste chaînée à afficher 					  */         	                 
/*														  */
/* La procédure lit tous les mots contenus dans la liste  */
/* ainsi que leur nombre d'apparition dans le texte lu.   */
/**********************************************************/
void AfficherListeChainee(liste_mots_t liste)
{
	maillon * cour = liste;
	while(cour)
	{
		printf("Mot : %s ; Occurrence : %d\n", cour->mot, cour->occurrence);
		cour = cour->suiv;
	}
}

/**********************************************************/
/* Procédure d'affichage de la table de hachage	          */
/* Entrée : Table à afficher 		 					  */         	                 
/*														  */
/* La procédure affiche tous les mots contenus dans la 	  */
/* tabe ainsi que leur nombre d'apparition dans le texte  */
/* lu. Pour chaque mot elle indique également dans quelle */
/* case de la table il appartient.						  */
/**********************************************************/
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

/**********************************************************/
/* Procédure de libération de la liste chaînée	          */
/* Entrée/Sortie : Liste à libérer 		 				  */         	                 
/*														  */
/* La procédure libère la liste chaînée entière pour      */
/* rendre la mémoire allouée.							  */
/**********************************************************/
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

/**********************************************************/
/* Procédure de libération de la table 			          */
/* Entrée/Sortie : Table à libérer 		 				  */         	                 
/*														  */
/* La procédure libère la table entière pour rendre la 	  */
/* mémoire allouée. Pour se faire elle libère toutes les  */
/* sous listes chaînées, puis la table majeure			  */
/**********************************************************/
void LibererTable(liste_mots_t * table_hash)
{
	int i;

	for (i=0;i<HASH_MAX;i++)
	{
		LibererListeChainee(table_hash[i]);
	}

	free(table_hash);
}