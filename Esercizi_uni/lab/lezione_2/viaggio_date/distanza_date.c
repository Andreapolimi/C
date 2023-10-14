/*Il Dottor Emmett Brown di "Ritorno al Futuro" ha bisogno del vostro aiuto per sviluppare il software
 del “contachilometri temporale” per la sua DeLorean.
Il programma riceve in input la data di partenza e la data di destinazione. Successivamente calcola
e stampa a video la distanza tra le due date in anni, mesi, giorni, ore e minuti.
Esempio:
Inserisci data e date di partenza della DeLorean (DD-MM-YYYY hh:mm): 12-09-1988 23:45 Inserisci data
e date di destinazione della DeLorean (DD-MM-YYYY hh:mm): 23-01-2022 23:58 Grande Giove! Hai viaggiato
 nel tempo per 33 anni 4 mesi 11 giorni 0 ore e 13 minuti!
Requisiti:
• le date vanno acquisite direttamente in formato DD-MM-YYYY hh:mm
• va verificata la validità delle date inserite: se almeno una delle date non è valida, allora il
programma
stampa a video un messaggio di errore e termina l’esecuzione
• ipotizziamo che la DeLorean possa viaggiare dal 1 gennaio 1888 al 31 dicembre 2100
• le date non devono essere necessariamente inserite in ordine cronologico, in quanto la
DeLorean può viaggiare avanti e indietro nel tempo
• il programma deve tenere conto degli anni bisestili e del numero differente di giorni presenti in
ciascun date dell'date
• per verificare la correttezza del risultato è possibile utilizzare questo calcolatore on-line
https://www.timeanddate.com/date/timeduration.html*/

#include <stdio.h>

// costanti per calcoli
#define MESI_ANNO 12
#define GIORNI_ANNO 365
#define ORE_GIORNO 24
#define MINUTI_ORA 60

// costanti per controllo range date (MIN e MAX)
#define MIN_GIORNI 1
#define MIN_MESI 1
#define MIN_ANNO 1888
#define MIN_ORE 0
#define MIN_MINUTI 0

#define MAX_GIORNI 1
#define MAX_MESI 12
#define MAX_ANNO 2100
#define MAX_ORE 23
#define MAX_MINUTI 59

int GIORNI_MESI[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// costanti per gestione vettore
#define INIZIALE 0
#define FINALE 1
#define NUM_DATE 2
#define NUM_DATI 5
enum data
{
    GIORNO,
    MESE,
    ANNO,
    ORA,
    MINUTO
};

// costante per bisistilità
#define FEBBRAIO 2
#define BISESTILE 4

// nomi variabili necessarie
typedef int contatori;
typedef int controllo;
typedef enum Bool
{
    False,
    True
} bool;

void conta_tragitto(int data_piccola[], int data_grande[], int giorni_mese_grande, int giorni_anno_grande)
{
    int viaggio[NUM_DATI];

    viaggio[ANNO] = data_grande[ANNO] - data_piccola[ANNO];

    if (data_grande[MINUTO] >= data_piccola[MINUTO])
        viaggio[MINUTO] = data_grande[MINUTO] - data_piccola[MINUTO];
    else
    {
        viaggio[MINUTO] = data_grande[MINUTO] + MINUTI_ORA - data_piccola[MINUTO];
        data_grande[ORA]--;
    }

    if (data_grande[ORA] >= data_piccola[ORA])
        viaggio[ORA] = data_grande[ORA] - data_piccola[ORA];
    else
    {
        viaggio[ORA] = data_grande[ORA] + ORE_GIORNO - data_piccola[ORA];
        data_grande[GIORNO]--;
    }

    if (data_grande[GIORNO] >= data_piccola[GIORNO])
        viaggio[GIORNO] = data_grande[GIORNO] - data_piccola[GIORNO];
    else
    {
        viaggio[GIORNO] = data_grande[GIORNO] + giorni_mese_grande - data_piccola[GIORNO];
        data_grande[MESE]--;
    }

    if (data_grande[MESE] >= data_piccola[MESE])
        viaggio[MESE] = data_grande[MESE] - data_piccola[MESE];
    else
    {
        viaggio[MESE] = data_grande[MESE] + giorni_anno_grande - data_piccola[MESE];
        viaggio[ANNO]--;
    }

    printf("Ha viaggiato nel tempo di %d giorni, %d mesi,%d anni, %d ore e %d minuti", viaggio[GIORNO], viaggio[MESE], viaggio[ANNO], viaggio[ORA], viaggio[MINUTO]);
}

int main()
{
    int date[NUM_DATE][NUM_DATI];
    bool esci_while, esci_for;
    contatori i, j;
    controllo giorni_mese[NUM_DATE], giorni_anno[NUM_DATE], minuti_totali[NUM_DATE];

    // acquisizione date
    for (i = INIZIALE; i < NUM_DATE; i++)
    {
        esci_while = False;
        while (esci_while == False)
        {
            printf("Inserire la data %d in formato DD-MM-YYYY hh:mm (attento alla corrispondenza giorni-date): ", i + 1);
            scanf("%d-%d-%d %d:%d", &date[i][GIORNO], &date[i][MESE], &date[i][ANNO], &date[i][ORA], &date[i][MINUTO]);

            esci_for = False;
            for (j = MIN_MESI; j < (MESI_ANNO + 1) && esci_for == False; j++)
            {
                if (date[i][MESE] == j)
                {
                    if (j == FEBBRAIO && date[i][ANNO] % BISESTILE == 0)
                    {
                        giorni_mese[i] = GIORNI_MESI[j] + 1;
                        giorni_anno[i] = GIORNI_ANNO + 1;
                    }
                    else
                    {
                        giorni_mese[i] = GIORNI_MESI[j];
                        giorni_anno[i] = GIORNI_ANNO;
                    }
                    esci_for = True;
                }
            }

            if (
                date[i][GIORNO] < MIN_GIORNI || date[i][GIORNO] > giorni_mese[i] ||
                date[i][MESE] < MIN_MESI || date[i][MESE] > MAX_MESI ||
                date[i][ANNO] < MIN_ANNO || date[i][ANNO] > MAX_ANNO ||
                date[i][ORA] < MIN_ORE || date[i][ORA] > MAX_ORE ||
                date[i][MINUTO] < MIN_MINUTI || date[i][MINUTO] > MAX_MINUTI)
                printf("Inserire una data valida\n");
            else
                esci_while = True;
        }
    }

    minuti_totali[INIZIALE] = date[INIZIALE][ANNO] * giorni_anno[INIZIALE] * ORE_GIORNO * MINUTI_ORA +
                              date[INIZIALE][MESE] * giorni_mese[INIZIALE] * ORE_GIORNO * MINUTI_ORA +
                              date[INIZIALE][GIORNO] * ORE_GIORNO * MINUTI_ORA +
                              date[INIZIALE][ORA] * MINUTI_ORA + date[INIZIALE][MINUTO];

    minuti_totali[FINALE] = date[FINALE][ANNO] * giorni_anno[FINALE] * ORE_GIORNO * MINUTI_ORA +
                            date[FINALE][MESE] * giorni_mese[FINALE] * ORE_GIORNO * MINUTI_ORA +
                            date[FINALE][GIORNO] * ORE_GIORNO * MINUTI_ORA +
                            date[FINALE][ORA] * MINUTI_ORA + date[FINALE][MINUTO];

    if (minuti_totali[FINALE] > minuti_totali[INIZIALE])
        conta_tragitto(date[INIZIALE], date[FINALE], giorni_mese[FINALE], giorni_anno[FINALE]);
    else
    {
        if (minuti_totali[FINALE] < minuti_totali[INIZIALE])
            conta_tragitto(date[FINALE], date[INIZIALE], giorni_mese[INIZIALE], giorni_anno[INIZIALE]);
        else
            printf("Hai inserito due date identiche, non ha viaggiato nel tempo");
    }

    return 0;
}