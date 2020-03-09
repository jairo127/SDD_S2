#include "listes.h"

/****************************************************************/
/* Procédure : Affichage de la bibliothèque			            */
/* Entrée    : Liste d'emprunts					                */
/* Sortie    : Aucune						                    */
/*					                                 			*/
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


/****************************************************************/
/* Procédure : Insertion d'un livre après une adresse           */
/* Entrées   : - Adresse d'une cellule livre                    */
/*             - Numéro du livre à insérer                      */
/*             - Titre du livre à insérer                       */
/*                                                              */
/* Sortie    : - Adresse de la cellule livre                    */
/*             - Code de retour : 0 si ok                       */
/*                                1 si problème d'allocation    */
/*                                                              */
/* Procédure qui insère après une adresse prec donnée une       */
/* cellule livre_t dont les champs sont spécifiés dans les      */
/* paramètres                                                   */
/****************************************************************/

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

/****************************************************************/
/* Procédure : Insertion en tête de la liste des catégories     */
/* Entrées   : - Adresse de la liste des catégories             */
/*             - Nom de la catégorie à insérer                  */
/*             - Liste de livres la catégorie à insérer         */
/*                                                              */
/* Sortie    : - Adresse de la liste des catégories             */
/*             - Code de retour : 0 si ok                       */
/*                                1 si problème d'allocation    */
/*                                                              */
/* La procédure insère en tête de la liste des catégories       */
/* une nouvelle cellule categories_t, dont les champs sont      */
/* spécifiés dans les paramètres                                */
/****************************************************************/

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

/******************************************************************/
/* Procédure : Remplissage de la bibliothèque à partir du fichier */
/* Entrée    : - Fichier contenant les différents livres          */
/*                                                                */
/* Sorties   : - Liste des catégories, ie la bibliothèque associée*/
/*             - Code de retour : 0 si ok                         */
/*                                1 si problème d'insertion       */
/*                                due à une allocation ratée      */
/*                                                                */
/* La procédure met en place la liste des catégories à partir du  */
/* fichier fourni, contenant les divers livres et leurs attributs */ 
/******************************************************************/

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

/****************************************************************/
/* Procédure : Libération d'une liste de livres                 */
/* Entrée    : Liste de livres                                  */
/* Sortie    : Aucune                                           */
/*                                                              */
/* Procédure qui libère une liste chaînée des livres (pointée   */
/* par le champ d'une cellule categories_t)                     */
/*                                                              */
/****************************************************************/

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

/****************************************************************/
/* Procédure : Libération de la bibliothèque                    */
/* Entrée    : Liste des catégories, ie la bibliothèque         */
/* Sortie    : Aucune                                           */
/*                                                              */
/* La procédure rend toute la mémoire qui a été allouée pour    */
/* la bibliothèque libérant chaque cellule categories_t, et pour*/
/* chacune de ces cellules la liste de livres associée          */
/****************************************************************/

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
