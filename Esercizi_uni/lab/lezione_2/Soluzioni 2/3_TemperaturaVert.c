/*
 *Politecnico di Milano
 *Dipartimento di Elettronica e Informazione
 *Fondamenti di Informatica
 *Laboratorio 2
 *
 * --------------------------------
 *   TemperaturaVert.c
 *--------------------------------
 *
 *	Scrivere un programma che:
 *	- chiede all'utente di inserire le misure della temperatura corporea di un paziente rilevate nell'arco di 7 giorni e salva l'input in un array
 * - stampa i risultati sotto forma di un istogramma verticale, usando come carattere un '*' (inserire un *per ogni valore di temperatura con approssimazione per difetto)
 * - in basso scrive i valori relativi a ogni colonna.
 * - calcola la temperatura media, massima e minima
 *
 */
#include <stdio.h>
#define PERIODO 7

int main()
{
	/*
	 *	Dichiarazione variabili
	 */
	float temperaturaMedia, temperaturaMin, temperaturaMax, accTemperatura;
	float temperatura[PERIODO];
	int giorno;

	int j;

	/*
	 *	Esecuzione
	 */

	// Lettura dei valori di temperatura nel periodo
	for (giorno = 0; giorno < PERIODO; giorno++)
	{
		printf("Inserisci il valore di temperatura corporea del paziente del giorno %d: ", giorno + 1);
		scanf("%f", &temperatura[giorno]);
	}

	//calcolo dei valori medio, minimo e massimo
	for (giorno = 0; giorno < PERIODO; giorno++)
	{
		//se sono al primo passo devo ancora inizializzare le variabili
		if (giorno == 0)
		{
			temperaturaMax = temperatura[giorno];
			temperaturaMin = temperatura[giorno];
			accTemperatura = temperatura[giorno];
		}
		//se non sono al primo passo ...
		else
		{
			//sommo il valore della temperatura per il giorno corrente a quelli precedenti
			accTemperatura += temperatura[giorno];
			//confronto la temperatura attuale con quella massima
			if (temperatura[giorno] > temperaturaMax)
				temperaturaMax = temperatura[giorno];
			//confronto la temperatura attuale con quella minima
			if (temperatura[giorno] < temperaturaMin)
				temperaturaMin = temperatura[giorno];
		}
	}

	// Calcolo della media
	temperaturaMedia = accTemperatura / PERIODO;

	/*Stampo l'istogramma riga per riga dall'alto al basso */
	for (j = temperaturaMax; j > 0; j--)
	{
		for (giorno = 0; giorno < PERIODO; giorno++) /*stampa di ogni riga */
			if (temperatura[giorno] >= j)
				printf("  * ");
			else
				printf("     ");
		printf("\n");
	}
	for (giorno = 0; giorno < PERIODO; giorno++)
		printf("%3.0f  ", temperatura[giorno]);

	printf("\n");

	// Stampa del risultato
	printf("La temperatura media del paziente e': %.2f\n", temperaturaMedia);
	printf("La temperatura massima e': %.1f\n", temperaturaMax);
	printf("La temperatura minima e': %.1f\n", temperaturaMin);

	// Termina correttamente
	return 0;
}