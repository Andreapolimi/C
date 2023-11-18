/*
 Programma che:
 - legge il valore delle tre variabili intere: "a", "b" e "c"
 - fa lo shift circolare del contenuto delle tre variabili, cioe':
 	- mette il contenuto di a in b
 	- mette il contenuto di b in c
 	- mette il contenuto di c in a
 - stampa il valore delle tre variabili
 */
#include <stdio.h>

int main()
{
	// Dichiarazione delle variabili
	int a, b, c, temp;

	// Richieste e lettura da stdin
	printf("\nInserire il valore di a: ");
	scanf("%d", &a);

	printf("Inserire il valore di b: ");
	scanf("%d", &b);

	printf("Inserire il valore di c: ");
	scanf("%d", &c);

	// Shift circolare
	temp = c;
	c = b;
	b = a;
	a = temp;

	// Stampa il risultato dello shift
	printf("\nIl valore di a e': %d", a);
	printf("\nIl valore di b e': %d", b);
	printf("\nIl valore di c e': %d \n", c);

	// Terminazione corretta del programma
	return 0;
}
