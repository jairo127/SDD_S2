#include "listes.h"

void AfficherBiblio(liste_categories_t biblio)
{
    liste_categories_t cour = biblio;
    liste_livres_t cour_l;
    if (cour)
    {
    	do
    	{
        	printf("Nom de la categorie : %s\n", cour->nom);
        	cour_l = cour->liste_livres_categorie;

        	while (cour_l)
        	{
            		printf("Numero du livre : %d, titre du livre : %s, disponibilite : %s\n", 
            		cour_l->numero, cour_l->titre, (cour_l->disponible)?"OUI":"NON");
            		cour_l = cour_l->suiv;
        	}

        	cour = cour->suiv;
    	} while (cour);
    }
    else
    {
	printf("La bibliothèque est vide !\n");
    }	
}




void InsererApresAdr(liste_livres_t * prec, int numero, char * titre)
{
    livres_t * maillon;
    maillon = (livres_t *) malloc(sizeof(livres_t));

    if (maillon != NULL)
    {
        maillon->numero = numero;
        strcpy(maillon->titre, titre);
        maillon->disponible = 1;

        maillon->suiv = *prec;
        *prec = maillon;
    }
}


void InsererEnTete(liste_categories_t * biblio, char * nom, liste_livres_t liste_livres)
{
    liste_categories_t maillon = (liste_categories_t) malloc(sizeof(categories_t));
    if (maillon != NULL)
    {
        strcpy(maillon->nom,nom);
        maillon->liste_livres_categorie = liste_livres;

        maillon->suiv = *biblio;
        *biblio = maillon;
    }
}

void RemplirListe(FILE * fichier, liste_categories_t * biblio)
{
    char nom[4];
    liste_livres_t liste_livres;
    liste_livres_t * cour_l;
    char ligne[TAILLE_MAX];
    int nombre_livres, numero_livre, i;
    char nom_livre[11];
                                

    while (!feof(fichier))
    {
        liste_livres = NULL;
        cour_l = &liste_livres;
        
        fgets(ligne, TAILLE_MAX, fichier);

        sscanf(ligne, "%s %d", nom, &nombre_livres);

    
        for (i=0; i<nombre_livres; i++)
        {
            fgets(ligne, TAILLE_MAX, fichier);
            sscanf(ligne, "%d %[^\n]s", &numero_livre, nom_livre);
            InsererApresAdr(cour_l, numero_livre, nom_livre);
            
            cour_l = &((*cour_l)->suiv);
            
        }

        InsererEnTete(biblio, nom, liste_livres);

    }
}
