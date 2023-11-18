/*
 *Politecnico di Milano
 *Dipartimento di Elettronica e Informazione
 *Fondamenti di Informatica
 *
 * --------------------------------
 *Esame.c
 * --------------------------------
 *
 *Scrivere un programma che definisca la struttura di un esame universitario e ne permetta la modifica dei dati da riga di comando.
 *	Gli esami vengono rappresentati con:
 *		-	nome corso
 *		-	cognome docente
 *		-	numero di CFU
 *		-	voto
 *
 *	Per rappresentare in blocco i dati dell'esame si usi una struttura dati di tipo struct. Scrivere un main che permetta l'inserimento di 5 elementi di tipo esame e dopo aver stampato il contenuto stampi la media pesata.
 *
 */
#include <stdio.h>
#include <string.h>
#define MAX_LEN 40
#define N 3

typedef struct
{
	char corso[MAX_LEN];
	char docente[MAX_LEN];
	int cfu;
	int voto;
} Esame;

int main()
{

	Esame esami[N];
	int i, sommaCFU = 0;
	double media = 0;
	setbuf(stdout, NULL);

	for (i = 0; i < N; i++)
	{
		printf("Inserisci i dati dell'esame %d:\n", i + 1);
		printf("\tNome corso: ");
		fgets(esami[i].corso, MAX_LEN, stdin);	// fgets impedisce il buffer overflow
		esami[i].corso[strlen(esami[i].corso)-1] = '\0';
		printf("\tCognome Docente: ");
		fgets(esami[i].docente, MAX_LEN, stdin);	// leggendo al massimo MAX_LEN char
		esami[i].docente[strlen(esami[i].docente)-1] = '\0';
		printf("\tNumero CFU: ");
		scanf("%d", &esami[i].cfu);
		printf("\tVoto conseguito: ");
		scanf("%d", &esami[i].voto);
		fflush(stdin);
		//while (getchar() != '\n'); // soluzione alternativa a fflush(stdin) per consumare il carattere terminatore
	}

	for (i = 0; i < N; i++)
	{
		printf("Esame: %s \t%s \t%d \t%d\n",
			esami[i].corso, esami[i].docente, esami[i].cfu, esami[i].voto);
	}

	for (i = 0; i < N; i++)
	{
		sommaCFU += esami[i].cfu;
		media += esami[i].voto *esami[i].cfu;
	}

	media = media / sommaCFU;

	printf("La media pesata è %f\n", media);

	return 0;

}