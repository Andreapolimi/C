/*
 *Politecnico di Milano
 *Dipartimento di Elettronica e Informazione
 *Fondamenti di Informatica
 *
 * --------------------------------
 *Esame.c
 * --------------------------------
 *
 *Scrivere un programma che definisca la struttura di un esame universitario
 *e ne permetta la modifica dei dati da riga di comando.
 *Gli esami vengono rappresentati con:
 *- nome corso (di tipo stringa)
 *- cognome docente (di tipo stringa)
 *- numero di CFU (di tipo intero)
 *- voto (di tipo intero)
 *Per rappresentare in blocco i dati dell'esame si usi una struttura dati
 *di tipo struct.
 *Scrivere un main che permetta l'inserimento da linea di comando di
 *un elemento di tipo esame e che stampi poi a schermo il contenuto.
 *
 *Funzionalità aggiuntiva:
 *Modificare il programma per permettere all'utente di inserire un numero
 *prefissato di esami (es. 5), stamparne i dati e calcolarne la media pesata
 *dei voti.
 */
#include <stdio.h>
#include <string.h>
#define MAX_LEN 40

typedef struct
{
	char corso[MAX_LEN];
	char docente[MAX_LEN];
	int cfu;
	int voto;
} Esame;

int main()
{

	Esame esame;

	// Imposta stdout in modalità unbuffered
	setbuf(stdout, NULL);

	printf("Inserisci i dati dell'esame:\n");
	printf("\tNome corso: ");
	fgets(esame.corso, MAX_LEN, stdin);	// fgets impedisce il buffer overflow
	esame.corso[strlen(esame.corso)-1] = '\0';
	printf("\tCognome Docente: ");
	fgets(esame.docente, MAX_LEN, stdin);	// leggendo al massimo MAX_LEN char
	esame.docente[strlen(esame.docente)-1] = '\0';
	printf("\tNumero CFU: ");
	scanf("%d", &esame.cfu);
	printf("\tVoto conseguito: ");
	scanf("%d", &esame.voto);

	printf("Nell'esame %s tenuto dal Prof. %s di %d CFU hai conseguito il voto %d\n",
		esame.corso, esame.docente, esame.cfu, esame.voto);

	return 0;

}