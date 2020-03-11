/********************************************/
/* Fichier "file.c"                     	*/
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient le comportement des fonctions	*/
/* définis dans le fichier "file.h"     	*/
/********************************************/

#include "file.h"

/************************************************/
/* Fonction : Initialisation de la File 	 	*/
/* Entrée : Taille souhaitée				 	*/
/* Sortie : Adresse de la file créée 			*/
/*												*/
/* Initialise une nouvelle file de taille 		*/
/* passée en paramètre 							*/
/************************************************/
File_t * 	InitFile(const int taille)
{
	File_t * file = (File_t *) malloc(sizeof(File_t)); // Adresse de la file
	if (file)
	{
		file->base = (std_type_t *) malloc(sizeof(std_type_t) * taille);
		if (file->base)
		{
			file->capacite = taille;
			file->debut = -1;
			file->fin = -1;
		}
		else
		{
			free(file);
			file = NULL;
		}
	}

	return file;
}

/************************************************/
/* Procédure : Affichage de la File 		 	*/
/* Entrée : File							 	*/
/* Sortie : Aucun 								*/
/*												*/
/* Affiche la file passée en paramètre  		*/
/* (sert pour le débuggage) 					*/
/************************************************/
void 		AfficherFile(const File_t file)
{
	int i; // variable de parcours de la file
	int nb_elem; // nombre d'éléments dans la file. Vaut -1 si la file est vide
	if (file.debut <= file.fin)
	{
		nb_elem = file.fin - file.debut + 1;
	}
	else
	{
		nb_elem = file.debut - file.fin;
	}
	for (i=0; i < nb_elem; i++)
	{
		printf("%d ", file.base[(file.debut + i) % (file.capacite)]);
	}
	printf("\n");
}

/************************************************/
/* Procédure : Libération de la File 		 	*/
/* Entrée : File à libérer (par adresse)	 	*/
/* Sortie : Aucune					 			*/
/*												*/
/* Libère entièrement l'espace mémoire lié 		*/
/* à la file à libérer							*/
/************************************************/
void 		LibererFile(File_t ** file)
{
	free ((*file)->base);
	free (*file);
	*file = NULL;
}

/************************************************/
/* Fonction : Vérification si la file est vide 	*/
/* Entrée : File à vérifier (par copie)			*/
/* Sortie : Vrai si la file est vide à -1 	 	*/
/* 			Sinon Faux 							*/
/*												*/
/* Renvoie Vrai si la file est vide sinon Faux	*/
/************************************************/
int 		EstVide(const File_t file)
{
	return (file.debut == -1 && file.fin == -1);
}

/************************************************/
/* Procédure : Enfiler un élément dans la file 	*/
/* Entrée : - Adresse de la file concernée 		*/
/* 			- Valeur/Variable à enfiler 		*/
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succés de l'enfilement  		*/
/*			- 1 : Ne peut pas enfiler			*/
/*												*/
/* Enfile une variable dans la file 			*/
/************************************************/
int 		Enfiler(File_t * file, std_type_t var)
{
	int code = 0; // Code de retour
	
	if (file->debut == (file->fin +1)%(file->capacite)) // Si la file est pleine
	{
		code = 1;
	}
	else
	{
		if (EstVide(*file)) // Si la file est vide
		{
			file -> debut = 0;
		}
		file -> fin = (file-> fin +1) % (file->capacite);
		file -> base [file -> fin] = var;
	}

	return code;
}

/************************************************/
/* Procédure : Défiler un élément de la file 	*/
/* Entrée : - Adresse de la file concernée      */
/* Sortie : Code de retour					 	*/
/* 			- 0 : Succés du défilement 	 		*/
/*			- 2 : Ne peut pas défiler			*/
/*			Adresse de la valeur/variable 		*/
/*			(NULL si impossibilité de défiler)  */
/*												*/
/* Défile une variable de la file 				*/
/************************************************/
int 		Defiler(File_t * file, std_type_t * var)
{
	int code = 0; // Code de retour

	if (EstVide(*file)) // Si la file est vide
	{
		code = 2;
	}
	else
	{
		*var = file -> base [file->debut];
		if ( file->debut == file -> fin ) // Si la file n'a plus qu'un élément
		{
			file -> debut = -1; 
			file -> fin = -1;
		}
		else
		{
			file -> debut = (file -> debut + 1) % (file->capacite);
		}
	}

	return code;
}
