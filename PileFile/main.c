#include<stdio.h>

#include "File/file.h"
#include "Pile/pile.h"

/******************************************/
/* Fonction d'inversion de pile 		  */
/******************************************/
void Inverser_Pile(Pile_t * pile)
{
	int tmp, code; // Variables de stockage
	File_t * file = InitFile(pile->capacite); // File temporaire
	
	// On vide la pile et on enfile les éléments au fur et à mesure
	while(!EstVidePile(*pile))
	{
		code = Depiler(pile, &tmp);
		if (code == 0)
		{
			code = Enfiler(file, tmp);
		}
	}

	// On défile la file et on empile au fur et à mesure
	while(!EstVideFile(*file))
	{
		code = Defiler(file, &tmp);
		if (code == 0)
		{
			code = Empiler(pile, tmp);
		}
	}
	LibererFile(&file);
}

int Ackermann(int m, int n, int MAX)
{
	int code;
	Pile_t * pile = InitPile(MAX);
	int fin = 0;

	while(fin != 1)
	{
		if(m != 0)
		{
			while(n != 0)
			{
				code = Empiler(pile, m);
				n--;
			}
			m--;
			n = 1;
		}
		else
		{
			n++;
			if(!EstVidePile(*pile))
			{
				code = Depiler(pile, &m);
				m--;
			}
			else
			{
				fin = 1;
			}
		}
	}
	LibererPile(&pile);
	return n;
}

int main(void)
{
	// Test d'inversion de pile
	int code, res;
	Pile_t * pile = InitPile(5);
	code = Empiler(pile, 1);
	code = Empiler(pile, 2);
	code = Empiler(pile, 3);
	AfficherPile(*pile);
	Inverser_Pile(pile);
	AfficherPile(*pile);
	LibererPile(&pile);

	res = Ackermann(3, 2, 100);
	printf("Ackermann = %d\n", res);

	return 0;
}