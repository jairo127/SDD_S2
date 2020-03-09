#include "biblio.h"
#include "listes.h"
#include "dates.h"
#include "menu.h"

int main(int argc, char * * argv)
{
    if (argc==1)
    {
        printf("Compiler avec :\n- Le nom du fichier de la bibliotheque (ex : Livres)\n- Le nom du fichier d'emprunts (ex : Emprunts)\n- Le nom du fichier de rendus (ex : Rendues\n");
    }
    else
    {
        int code = 0;
        int choix = 0;
        long choix_date;
        char tmp;
        char nom_fichier[30];
        FILE * sauvegarde;

        liste_categories_t biblio = NULL;
        liste_emprunt_t dates = NULL;

        FILE * fichier = OuvrirFichier(argv[1], &code, "r");
        if (!code)
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
                        printf("Entrer le nom du fichier d'emprunt (30 carac max)\n");
                        scanf("%s", nom_fichier);
                        Emprunter(biblio, &dates, nom_fichier, &code); 
                        break;
                    case 4:
                        printf("Entrer le nom du fichier de rendus (30 carac max)\n");
                        scanf("%s", nom_fichier);
                        Rendre(biblio, &dates, nom_fichier, &code); 
                        break;
                    case 5:
                        printf("Entrer une date limite sous le format aaaammjj : ");
                        scanf("%ld", &choix_date);
                        Imprimer(dates, choix_date);
                        break;
                    case 6:
                        printf("Entrer le nom du fichier de sauvegarde (30 carac max) \n /!\\ Si le fichier existe déjà, il sera écrasé\n");
                        scanf("%s", nom_fichier);
                        sauvegarde = OuvrirFichier(nom_fichier, &code, "w");
                        if (code)
                        {
                            printf("Erreur d'ouverture du fichier\n");
                        }
                        else
                        {
                            SauvegarderEmprunts(dates, sauvegarde);
                            fclose(sauvegarde);
                        }
                    case 7:
                        break;
                    default:
                        printf("Erreur dans le choix\n"); break;
                }
                printf("Appuyez sur une entrée pour continuer\n");
                scanf("%c%*c", &tmp);
                system("clear");
            } while (choix != 7 && !code);
        }
        else
        {
            printf("Erreur de lecture du fichier fourni\n");
        }
    }
    return 0;
}
