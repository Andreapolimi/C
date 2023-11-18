/*
 *Politecnico di Milano
 *Dipartimento di Elettronica e Informazione
 *Fondamenti di Informatica
 *Laboratorio 2
 *
 * --------------------------------
 *   Anagramma.c
 * --------------------------------
 *
 *Si codifichi un programma C che legge due stringhe inserite dall'utente che rappresentano due parole e verifica se le parole sono anagrammi.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//dichiaro le stringhe come array di caratteri
	char a[100], b[100];
	//dichiaro le altre variabili
	int len, contA, contB, i, j, anagramma = 1;
	printf("Inserisci la prima stringa: ");
	scanf("%s", a);
	printf("Inserisci la seconda stringa: ");
	scanf("%s", b);
	len = strlen(a);
	
	if (len != strlen(b))
	{
		anagramma = 0;
	} else {
		for (i = 0; i < len && anagramma == 1; i++)
		{
			//per ogni a[i] in a (escluso il \0)
			contA = 0;
			contB = 0;
			for (j = 0; j < len; j++)
			{
				//scandisco le stringhe
				if (a[j] == a[i])
					++contA;	//conto le occorrenze di a[i] in a
				if (b[j] == a[i])
					++contB;	//e le occorrenze di a[i] in b
			}
			if (contA != contB) anagramma = 0;
		}
	}
	
	if (anagramma == 1)
		printf("Le parole %s e %s sono anagrammi\n", a, b);
	else
		printf("Le parole %s e %s non sono anagrammi\n", a, b);
	
	return 0;
}