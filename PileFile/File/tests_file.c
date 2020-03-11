/********************************************/
/* Fichier "tests_file.c"                   */
/* Valentin Guien - William Garrier     	*/
/*											*/
/* Contient les tests unitaires du module	*/
/* de la file 						     	*/
/********************************************/

#include "file.h"
#include <stdio.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

/********************************************/
/* Test de l'initialisation d'une file      */
/********************************************/
static void test_init_file(void ** frame)
{
	File_t * file = InitFile(20); // File
	
	// Tests de bonne initialisation de la file
	assert_non_null(file);
	assert_int_equal(file->capacite, 20);
	assert_int_equal(file->debut, -1);
	assert_int_equal(file->fin, -1);
	assert_non_null(file->base);

	// Libération de l'espace mémoire de la file
	free(file->base);
	free(file);
}

/********************************************/
/* Test de libération d'une file 		    */
/********************************************/
static void test_free_file(void ** frame)
{
	File_t * file = InitFile(20); // File
	
	// Tests de bonne initialisation de la file
	assert_non_null(file);
	assert_int_equal(file->capacite, 20);
	assert_int_equal(file->debut, -1);
	assert_int_equal(file->fin, -1);
	assert_non_null(file->base);

	// Test de bonne libération de la file
	LibererFile(&file);
	assert_null(file);
}

/********************************************/
/* Test d'enfilement dans une file      	*/
/* et tests de EstVide						*/
/********************************************/
static void test_enfilement_file(void ** frame)
{
	File_t * file = InitFile(5); // File
	int code = -1; 				 // Code de retour

	// Tests de bonne initialisation de la file
	assert_non_null(file);
	assert_int_equal(file->capacite, 5);
	assert_int_equal(file->debut, -1);
	assert_int_equal(file->fin, -1);
	assert_non_null(file->base);

	// Si la file a bien été initialisée
	if (file != NULL)
	{
		// Test que la file est bien vide
		assert_true(EstVide(*file));

		// Tests d'enfilement d'un élément dans la File
		code = Enfiler(file, 5);
		assert_int_equal(code, 0);
		assert_int_equal(file->debut, 0);
		assert_int_equal(file->fin, 0);
		assert_int_equal((file->base)[file->debut], 5);

		// Test que la file n'est pas vide
		assert_false(EstVide(*file));

		// Tests d'enfilement d'un élément dans la File
		code = Enfiler(file, 4);
		assert_int_equal(code, 0);
		assert_int_equal(file->debut, 0);
		assert_int_equal(file->fin, 1);
		assert_int_equal((file->base)[(file->debut)+1], 4);
	}

	// Libération de l'espace mémoire de la file
	free(file->base);
	free(file);
}

/********************************************/
/* Test de défilement d'une file 	     	*/
/* et tests de EstVide						*/
/********************************************/
static void test_defilement_file(void ** frame)
{
	File_t * file = InitFile(5); // File
	int code = -1; 				 // Code de retour
	std_type_t var; 			 // Variable de stockage

	// Tests de bonne initialisation de la file
	assert_non_null(file);
	assert_int_equal(file->capacite, 5);
	assert_int_equal(file->debut, -1);
	assert_int_equal(file->fin, -1);
	assert_non_null(file->base);

	// Si la file a bien été initialisée
	if (file != NULL)
	{
		// Test que la file est bien vide
		assert_true(EstVide(*file));

		// Tests d'enfilement d'un élément dans la File
		code = Enfiler(file, 5);
		assert_int_equal(code, 0);
		assert_int_equal(file->debut, 0);
		assert_int_equal(file->fin, 0);
		assert_int_equal((file->base)[file->debut], 5);

		// Test que la file n'est pas vide
		assert_false(EstVide(*file));

		// Tests d'enfilement d'un élément dans la File
		code = Enfiler(file, 4);
		assert_int_equal(code, 0);
		assert_int_equal(file->debut, 0);
		assert_int_equal(file->fin, 1);
		assert_int_equal((file->base)[(file->debut)+1], 4);

		// Tests de défilement de la File
		code = Defiler(file, &var);
		assert_int_equal(code, 0);
		assert_int_equal(file->debut, 1);
		assert_int_equal(file->fin, 1);
		assert_int_equal((file->base)[file->debut], 4);
		assert_int_equal(var, 5);
	}

	// Libération de l'espace mémoire de la file
	free(file->base);
	free(file);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_init_file),
        cmocka_unit_test(test_free_file),
        cmocka_unit_test(test_enfilement_file),
        cmocka_unit_test(test_defilement_file)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}