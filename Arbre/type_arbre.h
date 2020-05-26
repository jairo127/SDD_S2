#ifndef TYPE_ARBRE
#define TYPE_ARBRE

#include <stdio.h>
#include <stdlib.h>

typedef char std_type_arbre_t;

typedef struct arbre
{
	std_type_arbre_t sommet;
	struct arbre * lv; // lien vertical
	struct arbre * lh; // lien horizontal
} Arbre_t;

typedef Arbre_t ** std_type_pile_t;

#endif