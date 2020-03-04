/********************************************/
/* Fichier "tests_pile.c"                   */
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient les tests unitaires du module	*/
/* de la pile 						     	*/
/********************************************/

#include "pile.h"
#include <stdio.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

/********************************************/
/* Test de l'initialisation d'une pile      */
/********************************************/
static void test_init_pile(void ** frame)
{
	Pile_t * pile = InitPile(20);
	
	assert_non_null(pile);
	assert_int_equal(pile->capacite, 20);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);
}

/********************************************/
/* Test de la libération d'une pile      	*/
/********************************************/
static void test_free_pile(void ** frame)
{
	Pile_t * pile = InitPile(20);

	assert_non_null(pile);
	assert_int_equal(pile->capacite, 20);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	LibererPile(&pile);
	assert_null(pile);
}

/********************************************/
/* Test d'empilement dans une pile      	*/
/********************************************/
static void test_empilement_pile(void ** frame)
{
	Pile_t * pile = InitPile(5);
	int code = -1;

	assert_non_null(pile);
	assert_int_equal(pile->capacite, 5);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	if (pile != NULL)
	{
		code = Empiler(pile, 5);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, 0);
		assert_int_equal((pile->base)[pile->sommet], 5);
	}
}

/********************************************/
/* Test de dépilement d'une pile 		    */
/********************************************/
static void test_depilement_pile(void ** frame)
{
	Pile_t * pile = InitPile(5);
	int code = -1;
	std_type_t var;

	assert_non_null(pile);
	assert_int_equal(pile->capacite, 5);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	if (pile != NULL)
	{
		code = Empiler(pile, 5);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, 0);
		assert_int_equal((pile->base)[pile->sommet], 5);

		code = Depiler(pile, &var);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, -1);
		assert_int_equal(var, 5);
	}
}

/********************************************/
/* Test de vérification de pile vide	    */
/********************************************/
static void test_vide_pile(void ** frame)
{
	Pile_t * pile = InitPile(5);
	int code = -1;
	std_type_t var;

	assert_non_null(pile);
	assert_int_equal(pile->capacite, 5);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	if (pile != NULL)
	{
		assert_true(EstVide(*pile));

		code = Empiler(pile, 5);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, 0);
		assert_int_equal((pile->base)[pile->sommet], 5);

		assert_false(EstVide(*pile));
	}
}

int main(void)
{
	const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_init_pile),
        cmocka_unit_test(test_free_pile),
        cmocka_unit_test(test_empilement_pile),
        cmocka_unit_test(test_depilement_pile),
        cmocka_unit_test(test_vide_pile)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}