#include "menu.h"

void AfficherMenu()
{
    printf("Gestionnaire de bibliotheque\n1) Consulter la bibliotheque\n2) Consulter la liste des emprunts\n3) Emprunter les livres\n4) Rendre les livres\n5) Imprimer les livres à rendre avant une certaine date\n6) Enregistrer les emprunts actuels dans un fichier\n7) Quitter\n\nEntrer un entier correspondant au choix : ");
}

int GestionChoix()
{
    int choix;
    scanf("%d", &choix);
    printf("\n\n");
    return choix;
}

void Emprunter(liste_categories_t biblio, liste_emprunt_t * dates, char nom_fichier[30])
{
    char ligne[TAILLE_MAX];
    char nom[4];
    int numero;
    long date_retour;
    FILE * emprunts = fopen(nom_fichier, "r");
    int code = 0;

    if (!emprunts)
    {
        printf("Erreur, le fichier %s est introuvable\n", nom_fichier);
    }
    else
    {
	fgets(ligne, TAILLE_MAX, emprunts);   //Duplication de code nécessaire pour faire fonctionner feof 
        while (!feof(emprunts) && code != 3)
        {
            code = 0;
            sscanf(ligne, "%s %d %ld", nom, &numero, &date_retour);
       	    InsererEmprunt(biblio, dates, nom, numero, date_retour, &code);
            switch(code)
    	    {
	        case 0:
	            break;	
	        case 1:
                printf("Erreur : Le livre n°%d n'existe pas ou n'est pas dans la catégorie %s\n", numero, nom);
	            break;
	        case 2: 
		        printf("Erreur : Le livre n°%d est déjà emprunté ou tentative d'emprunts multiples\n", numero); 
   	            break;
	        case 3:
   	            printf("Erreur : Espace mémoire insuffisant\n"); 
	            break;
	        }
	    fgets(ligne, TAILLE_MAX, emprunts);	   
        }
	fclose(emprunts);
    }
    printf("Terminé\n");
}

void Rendre(liste_categories_t biblio, liste_emprunt_t * dates, char nom_fichier[30])
{
    char ligne[TAILLE_MAX];
    char nom[4];
    int numero;
    long date_retour;
    FILE * rendus = fopen(nom_fichier, "r");
    int code;

    if (!rendus)
    {
        printf("Erreur, le fichier %s est introuvable\n", nom_fichier);
    }
    else
    {
	fgets(ligne, TAILLE_MAX, rendus); //Duplication de code nécessaire pour faire fonctionner feof

        while (!feof(rendus) && code != 3)
        {
            code = 0;
            sscanf(ligne, "%s %d %ld", nom, &numero, &date_retour);
            SupprimerEmprunt(biblio, dates, nom, numero, date_retour, &code);
            switch(code)
    	    {
	        case 0:
	            break;	
	        case 1:
                printf("Erreur : Le livre n°%d n'existe pas ou n'est pas dans la catégorie %s\n", numero, nom);
	            break;
	        case 2: 
		        printf("Erreur : Le livre n°%d n'est pas emprunté ou tentative de rendus multiples\n", numero); 
   	            break;
	        case 3:
   	            printf("Erreur : Espace mémoire insuffisant\n"); 
	            break;
	        }
	        fgets(ligne, TAILLE_MAX, rendus);
        }
	fclose(rendus);
    }
    printf("Terminé\n");
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


void Imprimer(liste_emprunt_t liste_dates, long date)
{
    liste_emprunt_t cour = liste_dates;
    printf("Liste des livres à rendre avant le %ld %ld %ld :\n", RecupJour(date), RecupMois(date), RecupAnnee(date));
    while (cour && cour->date_retour <= date)
    {
        printf("Catégorie %s, Livre n°%d : à rendre avant le %ld %ld %ld\n", cour->nom, cour->numero, RecupJour(cour->date_retour), RecupMois(cour->date_retour), RecupAnnee(cour->date_retour));
        cour = cour->suiv;
    }
}

void SauvegarderEmprunts(liste_emprunt_t dates, FILE * fichier)
{
    liste_emprunt_t cour = dates;

    while(cour)
    {
        fprintf(fichier, "%s %d %ld\n", cour->nom, cour->numero, cour->date_retour);
        cour = cour->suiv;
    }
    printf("Fait\n");
}