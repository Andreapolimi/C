#include <stdio.h>

int main()
{
	printf("Convertitore v1.0\n\n");
	printf("Inserire un valore (base 10):");

	// Variabili locali
	int base10;
	int base2 = 0;
	int base8 = 0;

	// Acquisizione input da utente
	scanf("%d", &base10);
	printf("Il numero inserito è: %d in base 10\n", base10);

	// Conversione in base 2
	int dividendo = base10;
	int potenza = 1;
	while (dividendo != 0)
	{
		// Calcolo cifra in codifica binaria
		int resto = dividendo % 2;
		// Salvo il resto come cifra di un numero decimale
		base2 += resto * potenza;
		dividendo /= 2;
		potenza *= 10;
	}
	printf("                      %d in base 2\n", base2);

	// Conversione in base 8
	dividendo = base10;
	potenza = 1;
	while (dividendo != 0)
	{
		// Calcolo cifra in codifica ottale
		int resto = dividendo % 8;
		// Salvo il resto come cifra di un numero decimale
		base8 += resto * potenza;
		dividendo /= 8;
		potenza *= 10;
	}
	printf("                      %d in base 8\n", base8);
}