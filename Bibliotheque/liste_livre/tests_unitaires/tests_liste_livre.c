#include "../liste_livre.h"
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

char *fichier;

static void test_liste_fichier(void **frame)
{
	liste_livres_t liste = InitListeLivre();
	int numero;
	char titre[30];
	FILE * file;

	assert_null(liste);
	
	file = fopen(fichier, "r");

	if (file != NULL)
	{
		while(!feof(file))
		{
			LireLivre(file, &numero, titre);
			InsererLivre(&liste, numero, titre);
		}

		assert_non_null(liste);

		fclose(file);
		AfficherListeLivre(stdout, liste);
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
		strcpy(fichier, argv[1]);
	else
		fichier = "tests_unitaires/test_livre.txt";


	const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_liste_fichier)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}