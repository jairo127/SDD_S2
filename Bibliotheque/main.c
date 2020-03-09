#include "Biblio/biblio.h"
#include "Listes/listes.h"
#include "Dates/dates.h"
#include "Menu/menu.h"

int main(int argc, char * * argv)
{
    if (argc !=4 )
    {
        printf("Compiler avec :\n- Le nom du fichier de la bibliotheque (ex : Livres)\n- Le nom du fichier d'emprunts (ex : Emprunts)\n- Le nom du fichier de rendus (ex : Rendus)\n");
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
            RemplirListe(fichier, &biblio, &code);
            if (!code)
            {
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
                            Emprunter(biblio, &dates, argv[2]); 
                            break;
                        case 4:
                            Rendre(biblio, &dates, argv[3]); 
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
                printf("Erreur : Plus de place dans la mémoire\n");
            }
        }
        else
        {
            printf("Erreur de lecture du fichier fourni\n");
        }
        fclose(fichier);
        LibererBibliotheque(biblio);
        LibererEmprunts(dates);
    }
    return 0;
}
