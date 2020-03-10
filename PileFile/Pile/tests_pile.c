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
	Pile_t * pile = InitPile(20); // Pile
	
	// Tests de bonne initialisation de la pile
	assert_non_null(pile);
	assert_int_equal(pile->capacite, 20);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	// Libération de la mémoire de la pile
	free(pile->base);
	free(pile);
}

/********************************************/
/* Test de la libération d'une pile      	*/
/********************************************/
static void test_free_pile(void ** frame)
{
	Pile_t * pile = InitPile(20); // Pile

	// Tests de bonne initialisation de la pile
	assert_non_null(pile);
	assert_int_equal(pile->capacite, 20);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	// Tests de bonne libération de la pile
	LibererPile(&pile);
	assert_null(pile);
}

/********************************************/
/* Test d'empilement dans une pile      	*/
/********************************************/
static void test_empilement_pile(void ** frame)
{
	Pile_t * pile = InitPile(5); // Pile
	int code = -1; 				 // Code de retour

	// Tests de bonne initialisation de la pile
	assert_non_null(pile);
	assert_int_equal(pile->capacite, 5);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	// Si la pile à été initialisé alors
	if (pile != NULL)
	{
		// Tests de bon empilement d'une valeur dans la pile
		code = Empiler(pile, 5);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, 0);
		assert_int_equal((pile->base)[pile->sommet], 5);
	}

	// Libération de la mémoire de la pile
	free(pile->base);
	free(pile);
}

/********************************************/
/* Test de dépilement d'une pile 		    */
/********************************************/
static void test_depilement_pile(void ** frame)
{
	Pile_t * pile = InitPile(5); // Pile
	int code = -1; 				 // Code de retour
	std_type_t var; 			 // Variable de stockage

	// Tests de bonne initialisation de la pile
	assert_non_null(pile);
	assert_int_equal(pile->capacite, 5);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	// Si la pile à été initialisé alors
	if (pile != NULL)
	{
		// Tests de bon empilement d'une valeur dans la pile
		code = Empiler(pile, 5);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, 0);
		assert_int_equal((pile->base)[pile->sommet], 5);

		// Tests de bon dépilement d'une valeur de la pile
		code = Depiler(pile, &var);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, -1);
		assert_int_equal(var, 5);
	}

	// Libération de la mémoire de la pile
	free(pile->base);
	free(pile);
}

/********************************************/
/* Test de vérification de pile vide	    */
/********************************************/
static void test_vide_pile(void ** frame)
{
	Pile_t * pile = InitPile(5); // Pile
	int code = -1; 				 // Code de retour
	std_type_t var; 			 // Variable de stockage

	// Tests de bonne initialisation de la pile
	assert_non_null(pile);
	assert_int_equal(pile->capacite, 5);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	// Si la pile à été initialisé alors
	if (pile != NULL)
	{
		// Test que la pile est bien vide
		assert_true(EstVide(*pile));

		// Tests de bon empilement d'une valeur dans la pile
		code = Empiler(pile, 5);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, 0);
		assert_int_equal((pile->base)[pile->sommet], 5);

		// Test que la pile n'est pas vide
		assert_false(EstVide(*pile));
	}

	// Libération de la mémoire de la pile
	free(pile->base);
	free(pile);
}

/********************************************/
/* Test cas d'erreur empilement pile pleine	*/
/* Attention : test fonctionnel quand il 	*/
/* n'y a pas de realloc dans Empiler		*/
/********************************************/
static void test_empilement_pile_pleine(void ** frame)
{
	Pile_t * pile = InitPile(3); // Pile
	int code = -1; 				 // Code de retour

	// Tests de bonne initialisation de la pile
	assert_non_null(pile);
	assert_int_equal(pile->capacite, 3);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	// Si la pile à été initialisé alors
	if (pile != NULL)
	{
		// Tests de bon empilement d'une valeur dans la pile
		code = Empiler(pile, 5);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, 0);
		assert_int_equal((pile->base)[pile->sommet], 5);

		// Tests de bon empilement d'une valeur dans la pile
		code = Empiler(pile, 4);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, 1);
		assert_int_equal((pile->base)[pile->sommet], 4);

		// Tests de bon empilement d'une valeur dans la pile
		code = Empiler(pile, 3);
		assert_int_equal(code, 0);
		assert_int_equal(pile->sommet, 2);
		assert_int_equal((pile->base)[pile->sommet], 3);

		// Tests de l'erreur d'empilement d'une valeur dans la pile
		code = Empiler(pile, 2);
		assert_int_equal(code, 1);
		assert_int_equal(pile->sommet, 2);
		assert_int_equal((pile->base)[pile->sommet], 3);
	}

	// Libération de la mémoire de la pile
	free(pile->base);
	free(pile);
}

/********************************************/
/* Test cas d'erreur dépilement pile vide   */
/********************************************/
static void test_depilement_pile_vide(void ** frame)
{
	Pile_t * pile = InitPile(5); // Pile
	int code = -1; 				 // Code de retour
	std_type_t var; 			 // Variable de stockage

	// Tests de bonne initialisation de la pile
	assert_non_null(pile);
	assert_int_equal(pile->capacite, 5);
	assert_int_equal(pile->sommet, -1);
	assert_non_null(pile->base);

	// Si la pile à été initialisé alors
	if (pile != NULL)
	{
		// Tests d'erreur de dépilement d'une valeur de la pile
		code = Depiler(pile, &var);
		assert_int_equal(code, 2);
		assert_int_equal(pile->sommet, -1);
	}

	// Libération de la mémoire de la pile
	free(pile->base);
	free(pile);
}

/********************************************/
/* Fonction main des tests unitaires	    */
/********************************************/
int main(void)
{
	// Liste des tests unitaires à exécuter
	const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_init_pile),
        cmocka_unit_test(test_free_pile),
        cmocka_unit_test(test_empilement_pile),
        cmocka_unit_test(test_depilement_pile),
        cmocka_unit_test(test_vide_pile),
        cmocka_unit_test(test_empilement_pile_pleine),
        cmocka_unit_test(test_depilement_pile_vide)
    };

    // Exécution des tests unitaires
    return cmocka_run_group_tests(tests, NULL, NULL);
}