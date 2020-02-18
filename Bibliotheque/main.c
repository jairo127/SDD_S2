#include "biblio.h"
#include "listes.h"
#include "dates.h"
#include "menu.h"

int main(int argc, char * * argv)
{
    if (argc==1)
    {
        printf("Compiler avec le nom du fichier en parametre\n");
    }
    else
    {
        int code = 1;
    
        liste_categories_t biblio = NULL;
        liste_emprunt_t dates = NULL;

        FILE * fichier = OuvrirFichier(argv[1], &code, "r");
        if (code)
        {
            RemplirListe(fichier, &biblio);
            fclose(fichier);
        }

        AfficherBiblio(biblio);
        InsererEmprunt(biblio, &dates, "POL", 15, 20200312, &code);
        InsererEmprunt(biblio, &dates, "POL", 17, 20200416, &code);
        InsererEmprunt(biblio, &dates, "BD", 21, 20200101, &code);
        //SupprimerEmprunt(biblio, &dates, "POL", 17, 20200416);
        if (code)
        {
        	AfficherBiblio(biblio);
        	AfficherDates(dates);
        }
    }

    return 0;
}
