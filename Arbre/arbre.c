/*******************************************/
/* Fichier "arbre.c"          			   */
/* William Garrier - Valentin Guien 	   */
/*										   */
/* Contient le comportement des fonctions  */
/* definis dans le fichier "arbre.h"       */
/*******************************************/

#include "arbre.h"

/****************************************************************/
/* Fonction : Creation de la chaine de caractere a partir		*/
/*			  de la notation algebrique 			 			*/
/* Entrée : Adresse du fichier 									*/
/* Sortie : Pointeur de tete de la chaine    					*/
/* 																*/
/* Cette fonction lit la notation algebrique contenue dans le	*/
/* fichier et retourne la chaine de caracteres associe			*/
/****************************************************************/

char * CreerChaine(FILE * fichier)
{
	char * ligne = (char *) malloc(sizeof(char) * TAILLE_MAX); // Pour enregistrer la ligne du fichier

	fscanf(fichier, "%s", ligne);

	return ligne;
}

void ConvertStr(char ** chaine)
{
    int n = strlen(*chaine);
    int i, j;
  
    for(i=1; i<n; i++)
    {
        if((*chaine)[i] == '*' && (*chaine)[i+1] != '(')
        {
            for(j=n+1; j>i+1; j--)
                (*chaine)[j] = (*chaine)[j-2];
            (*chaine)[i+1] = '(';
            (*chaine)[i+2] = (*chaine)[i+3];
            (*chaine)[i+3] = ')';
        }
    }
    //printf("%s\n", *chaine);
}

void Insertion(std_type_arbre_t valeur, Arbre_t ** ptr)
{
	arbre_t * maillon = (arbre_t *) malloc (sizeof(arbre_t));
	maillon->lv = NULL; maillon->lh = NULL;

	*ptr = maillon;
}


Arbre_t * CreerArbre(char * chaine)
{
	Pile_t * pile = InitPile(CAPACITE_MAX);

	Arbre_t * arb = NULL;
	Arbre_t ** cour = &arb;

	int n = strlen(chaine);
	int i;

	for (i=0; i<n; i++)
	{
		switch(chaine[i])
		{
			case '*' : // descente vers le lv
				cour = &((*cour)->lv);
				break;
			case '(' : // empiler
				Empiler(pile, )
				break;
			case ')' : // depiler
				break;
			case '+' : // aller sur le lh
				break;
			default  : // un element de l'arbre
				Insertion(chaine[i], cour);
				break;
		}
	}

	return arb;
}

void ParcoursArbre(arbre_t * arb)
{
	Arbre_t * cour = arb;
	Pile_t * pile = InitPile(CAPACITE_MAX);
	int fin = 0; //0 : pas fini ; 1 : fini
	char * caractere;

	while(!fin)
	{
		while (cour)
		{
			Empiler(pile, cour);
			cour = cour->lv;
		}
		if (EstVidePile(pile))
		{
			fin = 1;
		}
		else
		{
			Depiler(pile, );
			printf('%c ',*caractere);
			cour = cour->lh;
		}
	}
	printf("\n");
}