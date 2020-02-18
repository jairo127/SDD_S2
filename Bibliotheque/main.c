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
        int choix = 0;
        char tmp;

        liste_categories_t biblio = NULL;
        liste_emprunt_t dates = NULL;

        FILE * fichier = OuvrirFichier(argv[1], &code, "r");
        if (code)
        {
            RemplirListe(fichier, &biblio);
            do
            {
                AfficherMenu();
                choix = GestionChoix();
                system("clear");
                switch(choix)
                {
                    case 1:
                        AfficherBiblio(biblio); break;
                    case 2:
                        AfficherDates(dates); break;
                    case 3:
                        Emprunter(biblio, dates, &code); break;
                    case 4:
                        Rendre(biblio, dates); break;
                    case 5:
                        break;
                    default:
                        printf("Erreur dans le choix\n"); break;
                }
                printf("\n\nAppuyez sur une entrée pour continuer\n");
                scanf("%c%*c", &tmp);
                system("clear");
            } while (choix != 5);
        }
        else
        {
            printf("Erreur de lecture du fichier fourni\n");
        }
    }
    return 0;
}
