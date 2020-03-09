#include "listes.h"

/****************************************************************/
/* Procédure : Affichage de la bibliothèque			*/
/* Entrée    : Liste d'emprunts					*/
/* Sortie    : Aucune						*/
/*								*/
/* La procédure affiche chaque maillon de la liste d'emprunts   */
/****************************************************************/

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
            		printf("Numero du livre : %d, titre du livre : %s, disponible : %s\n", 
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




void InsererApresAdr(liste_livres_t * prec, int numero, char * titre, int * code)
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
    else
    {
        free(maillon);
        *code = 1;
    }
}


void InsererEnTete(liste_categories_t * biblio, char * nom, liste_livres_t liste_livres, int * code)
{
    liste_categories_t maillon = (liste_categories_t) malloc(sizeof(categories_t));
    if (maillon != NULL)
    {
        strcpy(maillon->nom,nom);
        maillon->liste_livres_categorie = liste_livres;

        maillon->suiv = *biblio;
        *biblio = maillon;
    }
    else
    {
        free(maillon);
        *code = 1;
    }
}

void RemplirListe(FILE * fichier, liste_categories_t * biblio, int * code)
{
    char nom[4];
    liste_livres_t liste_livres;
    liste_livres_t * cour_l;
    char ligne[TAILLE_MAX];
    int nombre_livres, numero_livre, i;
    char nom_livre[11];

    fgets(ligne, TAILLE_MAX, fichier); //Duplication de code nécessaire pour faire fonction feof                           

    while (!feof(fichier))
    {
        liste_livres = NULL;
        cour_l = &liste_livres;

        sscanf(ligne, "%s %d", nom, &nombre_livres);

        for (i=0; i<nombre_livres; i++)
        {
            fgets(ligne, TAILLE_MAX, fichier);
            sscanf(ligne, "%d %[^\n]s", &numero_livre, nom_livre);
            InsererApresAdr(cour_l, numero_livre, nom_livre, code);
            
            cour_l = &((*cour_l)->suiv);
            
        }

        InsererEnTete(biblio, nom, liste_livres, code);
        fgets(ligne, TAILLE_MAX, fichier);
    }
}

void LibererListeLivre(liste_livres_t livres)
{
    liste_livres_t cour = livres;
    liste_livres_t tmp;
    while (cour)
    {
        tmp = cour;
        cour = cour->suiv;
        free(tmp);
    }
}

void LibererBibliotheque(liste_categories_t biblio)
{
    liste_categories_t cour = biblio;
    liste_categories_t tmp;
    while (cour)
    {
        tmp = cour;
        LibererListeLivre(cour->liste_livres_categorie);
        cour = cour->suiv;
        free(tmp);
    }
}
