/*******************************************/
/* Fichier "arbre.c"          			   */
/* William Garrier - Valentin Guien 	   */
/*										   */
/* Contient le comportement des fonctions  */
/* definis dans le fichier "arbre.h"       */
/*******************************************/

#include "arbre.h"

/****************************************************************/
/* Fonction : Creation de la chaine de caracteres a partir		*/
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

void AdaptChaine(char ** chaine)
{
    int n = strlen(*chaine);
    int i, j;
  
    for(i=1; i<n; i++)
    {
        if((*chaine)[i] == '*' && (*chaine)[i+1] != '(') // on rencontre un sommet n'admettant qu'un seul fils
        {
            for(j=n+1; j>i+1; j--)
                (*chaine)[j] = (*chaine)[j-2]; // decalage a droite
            (*chaine)[i+1] = '('; //ajout de la parenthese ouvrante
            (*chaine)[i+2] = (*chaine)[i+3]; // petit decalage a gauche
            (*chaine)[i+3] = ')'; //ajout de la parenthese fermante
        }
    }
}

/****************************************************************/
/* Procedure : Insertion d'un sommet dans l'arbre juste         */
/*			   apres l'adresse fournie                          */
/* Entrées : Valeur a inserer, adresse d'insertion       		*/
/* Sortie : Aucune												*/
/*																*/
/* Cette procedure alloue un maillon contenant la valeur donnee */
/* et l'insere juste apres l'adresse donnee				    	*/
/****************************************************************/

void Insertion(std_type_arbre_t valeur, Arbre_t ** ptr)
{
	Arbre_t * maillon = (Arbre_t *) malloc (sizeof(Arbre_t)); //creation du maillon
	maillon->sommet = valeur;
	maillon->lv = NULL; maillon->lh = NULL;

	*ptr = maillon;
}

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

Arbre_t * CreerArbre(char * chaine)
{
	Pile_t * pile = InitPile(CAPACITE_MAX); 

	Arbre_t * arb = NULL;
	Arbre_t ** cour = &arb;

	int n, i;

	n = strlen(chaine);

	for (i=0; i<n; i++)
	{
		switch(chaine[i])
		{
			case '*' : // empiler et descendre vers le lv
				Empiler(pile, cour);
				cour = &((*cour)->lv);
				break;
			case '(' : // on fait rien
				break;
			case ')' : // depiler
				Depiler(pile, &cour);
				break;
			case '+' : // aller sur le lh
				cour = &((*cour)->lh);
				break;
			default  : // un element de l'arbre
				Insertion(chaine[i], cour);
				break;
		}
	}
	LibererPile(&pile);
	return arb;

}

/****************************************************************/
/* Procedure : Parcours de l'arbre avec impression des sommets  */
/*			   dans l'ordre prefixe                            */
/* Entrées : Arbre a parcourir  					       		*/
/* Sortie : Aucune												*/
/*																*/
/* Cette procedure realise le parcours de l'arbre et imprime	*/
/* les valeurs des sommets selon l'ordre prefixe				*/
/****************************************************************/

void ParcoursArbrePre(Arbre_t * arb)
{
	Arbre_t ** cour = &arb;
	Pile_t * pile = InitPile(CAPACITE_MAX);
	int fin = 0; //0 : pas fini ; 1 : fini

	while(!fin)
	{
		while (*cour)
		{
			printf("%c ", (*cour)->sommet);
			Empiler(pile, cour);
			cour = &((*cour)->lv); // descente sur le lv
		}
		if (EstVidePile(*pile))
		{
			fin = 1;
		}
		else
		{
			Depiler(pile, &cour);
			cour = &((*cour)->lh); // aller sur le lh
		}
	}
	printf("\n");
	LibererPile(&pile);
}

/****************************************************************/
/* Procedure : Parcours de l'arbre avec impression des sommets  */
/*			   dans l'ordre postfixe                            */
/* Entrées : Arbre a parcourir  					       		*/
/* Sortie : Aucune												*/
/*																*/
/* Cette procedure realise le parcours de l'arbre et imprime	*/
/* les valeurs des sommets selon l'ordre postfixe				*/
/****************************************************************/

void ParcoursArbrePost(Arbre_t * arb)
{
	Arbre_t ** cour = &arb;
	Pile_t * pile = InitPile(CAPACITE_MAX);
	int fin = 0; //0 : pas fini ; 1 : fini

	while(!fin)
	{
		while (*cour)
		{
			Empiler(pile, cour);
			cour = &((*cour)->lv); // descente sur le lv
		}
		if (EstVidePile(*pile))
		{
			fin = 1;
		}
		else
		{
			Depiler(pile, &cour);
			printf("%c ", (*cour)->sommet);
			cour = &((*cour)->lh); // aller sur le lh
		}
	}
	printf("\n");
	LibererPile(&pile);
}

/****************************************************************/
/* Fonction : Recherche d'un sommet de l'arbre avec la valeur	*/
/*			  indiquee									 		*/
/* Entrée : Adresse de l'arbre, valeur a rechercher	 			*/
/* Sortie : Adresse du premier sommet trouve					*/
/*			s'il existe, NULL sinon 				 			*/
/* 																*/
/* Cette fonction recherche dans l'arbre un sommet contenant	*/
/* la valeur indiquee. La recherche se fait selon un parcours  	*/
/* en largeur, et s'arrete au premier sommet trouve. S'il n'y   */
/* a pas de tel sommet, alors la fonction retourne NULL			*/
/****************************************************************/

Arbre_t ** RechercheValeur(Arbre_t * arb, std_type_arbre_t valeur)
{
	Arbre_t ** cour = &arb;
	File_t * file = InitFile(CAPACITE_MAX);

	while (*cour && (*cour)->sommet != valeur)
	{
		Enfiler(file, cour);
		cour = &((*cour)->lh);
		while(!(*cour) && !EstVideFile(*file))
		{
			Defiler(file, &cour);
			cour = &((*cour)->lv); // partir sur le lv du point defile
		}
	}
	if (!(*cour)) // le sommet n'existe pas
	{
		cour = NULL;
	}

	LibererFile(&file);
	return cour;
}

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

Arbre_t ** Dernier(Arbre_t ** tete)
{
	Arbre_t ** prec = tete;

	while (*prec)
	{
		prec = &((*prec)->lh);
	}

	return prec;
}

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

int AjouterFils(Arbre_t * arb, std_type_arbre_t valeur_pere, std_type_arbre_t valeur_fils)
{
	int ok = 0;
	Arbre_t ** cour = RechercheValeur(arb, valeur_pere);
	if (cour) // Si un sommet a ete trouve
	{
		Arbre_t ** dern = Dernier(&((*cour)->lv));
		Insertion(valeur_fils, dern);
		ok = 1;
	}

	return ok;
}

void LibererArbre(Arbre_t ** arb)
{
	Arbre_t ** prec = arb;
	Arbre_t * temp;
	File_t * file = InitFile(CAPACITE_MAX);


	while(*prec)
	{
		Enfiler(file, &((*prec)->lv));
		temp = *prec;
		prec = &((*prec)->lh);
		free(temp);
		while(!(*prec) && !EstVideFile(*file))
		{
			Defiler(file, &prec);
		}

	}

	LibererFile(&file);
}