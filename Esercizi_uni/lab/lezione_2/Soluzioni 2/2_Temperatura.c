/*
 *Politecnico di Milano
 *Dipartimento di Elettronica e Informazione
 *Fondamenti di Informatica
 *Laboratorio 2
 *
 * --------------------------------
 *   Temperatura.c
 *--------------------------------
 *
 *	Scrivere un programma che:
 *	- chiede all'utente di inserire le misure della temperatura corporea di un paziente rilevate nell'arco di 7 giorni e salva l'input in un array
 * - stampa i risultati sotto forma di tabella con allineamento a destra
 * - stampa accanto ai risultati un istogramma con allineamento a sinistra (un *per ogni valore di temperatura superiore a 34)
 *	- calcola la temperatura media, massima e minima
 *Esempio: GIORNO	VALORE	ISTOGRAMMA
 *		 1	  37.8 	***
 *		 2	  40.6 	******
 *
 *	Utilizzare il costrutto "define" per definire la durata del periodo di osservazione del paziente (7 giorni).
 *	N.B.: nel caso di variabili definite con "define" è consigliabile usare nomi di variabile scritte tutte con caratteri maiuscoli per distinguerle dalle altre variabili.
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

	/*
	 *	Esecuzione
	 */

	// Lettura dei valori di temperatura nel periodo
	for (giorno = 0; giorno < PERIODO; giorno++)
	{
		printf("Inserisci il valore di temperatura corporea del paziente del giorno %d: ", giorno + 1);
		scanf("%f", &temperatura[giorno]);
	}

	printf("GIORNO\tTEMPERATURA\tISTOGRAMMA\n");

	for (giorno = 0; giorno < PERIODO; giorno++)
	{
		printf("%6d\t%11.1f\t", giorno + 1, temperatura[giorno]);
		int j;
		for (j = 0; j <= temperatura[giorno] - 35; j++) /*una riga di ‘*’ */
			printf("*");
		printf("\n");
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

	// Stampa del risultato
	printf("La temperatura media del paziente e': %.2f\n", temperaturaMedia);
	printf("La temperatura massima e': %.1f\n", temperaturaMax);
	printf("La temperatura minima e': %.1f\n", temperaturaMin);

	// Termina correttamente
	return 0;
}