#include "file.h"

int main()
{
    File_t * file = InitFile(5);

    printf("File vide : %s\n", (EstVide(*file))?"Oui":"Non");

    Enfiler(file, 1);

    AfficherFile(*file);

    Enfiler(file, 123);
    Enfiler(file, 9);
    Enfiler(file, 6);

    AfficherFile(*file);


    return 0;
}