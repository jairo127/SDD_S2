#include "menu.h"

void AfficherMenu()
{
    printf("Gestionnaire de bibliotheque\n1) Consulter la bibliotheque\n2) Consulter la liste des emprunts\n3) Emprunter les livres\n4) Rendre les livres\n5) Imprimer les livres à rendre avant une certaine date\n6) Quitter\n\nEntrer un entier correspondant au choix : ");
}

int GestionChoix()
{
    int choix;
    scanf("%d", &choix);
    printf("\n\n");
    return choix;
}

void Emprunter(liste_categories_t biblio, liste_emprunt_t * dates, int * code)
{
    char ligne[TAILLE_MAX];
    char nom[4];
    int numero;
    long date_retour;
    FILE * emprunts = fopen("Emprunts", "r");

    if (!emprunts)
    {
        printf("Erreur, le fichier Emprunts est introuvable\n");
    }
    else
    {
	fgets(ligne, TAILLE_MAX, emprunts);   //Duplication de code nécessaire pour faire fonctionner feof 
        while (!feof(emprunts) && !(*code))
        {
            sscanf(ligne, "%s %d %ld", nom, &numero, &date_retour);
       	    InsererEmprunt(biblio, dates, nom, numero, date_retour, code);
 	  
	    fgets(ligne, TAILLE_MAX, emprunts);	   
        }
        
	switch(*code)
    	{
	    case 0:
		printf("Fait\n");
	        break;	
	    case 1:
                printf("Erreur : Le livre n°%d n'existe pas ou n'est pas dans la catégorie %s\nArret du programme\n", numero, nom);
	        break;
	    case 2: 
		printf("Erreur : Le livre n°%d est déjà emprunté ou tentative d'emprunts multiples\nArret du programme\n", numero); 
   	        break;
	    case 3:
   	        printf("Erreur : Espace mémoire insuffisant\nArret du programme\n"); 
	        break;
	}
       
	fclose(emprunts);
    }
}

void Rendre(liste_categories_t biblio, liste_emprunt_t * dates, int * code)
{
    char ligne[TAILLE_MAX];
    char nom[4];
    int numero;
    long date_retour;
    FILE * rendus = fopen("Rendus", "r");

    if (!rendus)
    {
        printf("Erreur, le fichier Rendus est introuvable\n");
    }
    else
    {
	fgets(ligne, TAILLE_MAX, rendus); //Duplication de code nécessaire pour faire fonctionner feof

        while (!feof(rendus) && !(*code))
        {
            sscanf(ligne, "%s %d %ld", nom, &numero, &date_retour);
            SupprimerEmprunt(biblio, dates, nom, numero, date_retour, code);
            
	    fgets(ligne, TAILLE_MAX, rendus);
	}
	
	switch(*code)
	{
	    case 0:
		printf("Fait\n");
		break;
            case 1:
  	        printf("Erreur : Le livre n°%d n'existe pas ou n'est pas dans la catégorie %s\nArret du programme\n", numero, nom);
                break;
	    case 2:
	 	printf("Erreur : Le livre n°%d n'a pas été emprunté ou tentative de rendus multiples\nArret du programme\n", numero);
		break;
	    case 3:
		printf("Erreur : La date de retour du livre n°%d est incorrecte\nArret du programme\n", numero);
		break;
	}
	
	fclose(rendus);
    }
}

long RecupAnnee(long date)
{
    return date / 10000;
}

long RecupMois(long date)
{
    return date / 100 - RecupAnnee(date) * 100;
}

long RecupJour(long date)
{
    return date - (date / 100) * 100;
}


void Imprimer(liste_emprunt_t dates, long date)
{
    liste_emprunt_t cour = dates;
    printf("Liste des livres à rendre avant le %ld %ld %ld :\n", RecupJour(date), RecupMois(date), RecupAnnee(date));
    while (cour && cour->date_retour <= date)
    {
        printf("Livre n°%d : à rendre avant le %ld %ld %ld\n",cour->numero, RecupJour(cour->date_retour), RecupMois(cour->date_retour), RecupAnnee(cour->date_retour));
        cour = cour->suiv;
    }
}
