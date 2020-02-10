#include "../liste_livre.h"
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

static void test_liste_vide(void **frame)
{
	liste_livre_t liste = init_liste_livre();
	assert_null(liste);
}

static void test_liste_fichier(void **frame)
{
	liste_livre_t liste = init_liste_livre();
	int numero;
	char titre[30];
	assert_null(liste);
	FILE * file;
	file = fopen("tests_unitaires/test_livre.txt", "r");
	if (file != NULL)
	{
		while(!feof(file))
		{
			lire_livre(file, &numero, titre);
			liste = inserer_livre(liste, numero, titre);
		}
		assert_non_null(liste);
		fclose(file);
		afficher_liste_livre(liste);
	}
}

int main(void)
{
	

	const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_liste_vide),
        cmocka_unit_test(test_liste_fichier)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}