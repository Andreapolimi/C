/*
Creare un algoritmo che dopo aver inserito l'id di un lavoratore (o 0 se si vogliono analizzare tutti i lavoratori), legga un file
in cui sono salvati gli orari di entrata e uscita dal posto di lavoro. Deve restituire quanto ha/hanno lavorato.
- tenere conto del fatto che l'id inserito può non essere presente nel file
- tenere conto del fatto che il lavoratore può non aver finito il turno
- tenere conto che il lavoratore può fare più turni
*/

// dichiarazione librerie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// dichiarazione costanti
#define DIM_ID 6
#define MIN_ORA 60
#define DIM_MAX 50

// dichiarazione tipi di dati
typedef int contatori;

typedef int traccia_dati;

typedef enum bool
{
    False,
    True
} bool;

typedef char gestione_file;

typedef struct riga
{
    int ora, min;
    char id[DIM_ID];
} riga;

// funzione per il calcolo del tempo di lavoro
void calcola_tempo_lavoro(riga entrata, riga uscita)
{
    int ore, min;

    if (uscita.min > entrata.min)
        min = uscita.min - entrata.min;
    else
    {
        min = uscita.min + MIN_ORA - entrata.min;
        uscita.ora--;
    }

    ore = uscita.ora - entrata.ora;

    printf("%d ore e %d minuti\n", ore, min);
}

// funzione principale
int main()
{
    traccia_dati indice_entrata, indice_uscita, turno, num_dati, num_id;
    bool esci_while, controllo;
    contatori i, j, k;
    gestione_file file_name[] = "/Users/andreavaccai/Coding/C/Esercizi_casa/minuti_lavorati/raccolta_attraversamenti.txt";
    gestione_file file_mode[] = "r";
    char *id_scelto, **id_totali;
    riga *dati;
    FILE *file_handle = fopen(file_name, file_mode);

    // apertura file e controllo successo
    if (file_handle == NULL)
    {
        printf("Lettura file fallita, chiusura del programma");
        exit(1);
    }

    dati = (riga *)calloc(1, sizeof(riga));

    // creazione delle celle con tutti i dati necessari
    i = 0;
    num_dati = 0;
    while (!feof(file_handle))
    {
        dati = (riga *)realloc(dati, (i + 1) * sizeof(riga));

        fscanf(file_handle, "%d:%d %s", &dati[i].ora, &dati[i].min, dati[i].id);

        num_dati += 1;
        i++;
    }

    // acquisizione dell'id scelto
    id_scelto = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));

    printf("Inserire l'id del lavoratore da controllare, composto da 6 caratteri alfanumerici (inserire 0 per visualizzarli tutti): ");
    scanf("%s", id_scelto);

    while (strlen(id_scelto) > DIM_ID)
    {
        printf("L'ID ha dimensione massima 6 caratteri, riprova\n");
        printf("Inserire l'id del lavoratore da controllare, composto da 6 caratteri alfanumerici (inserire 0 per visualizzarli tutti): ");
        scanf("%s", id_scelto);
    }

    id_scelto = (char *)realloc(id_scelto, DIM_ID * sizeof(char));

    // diramazione dei calcoli in base alla scelta dell'utente
    if (strcmp(id_scelto, "0") == 0)
    {
        // creazione di una matrice di stringhe per tutti gli id presenti nel file
        esci_while = False;
        num_id = 0;
        id_totali = (char **)calloc(num_id + 1, (num_id + 1) * sizeof(char *));
        for (i = 0; i < num_dati; i++)
        {
            controllo = False;
            // controllo se l'id esiste già nella lista id_totali
            for (j = 0; j < num_id && controllo == False; j++)
            {
                if (strcmp(id_totali[j], dati[i].id) == 0)
                    controllo = True;
            }
            // inserimento id nella matrice
            if (controllo == False)
            {
                num_id++;
                id_totali = (char **)realloc(id_totali, num_id * sizeof(char *));
                id_totali[num_id - 1] = (char *)calloc(strlen(dati[i].id), strlen(dati[i].id) * sizeof(char));
                id_totali[num_id - 1] = dati[i].id;
            }
        }

        k = 0;
        while (esci_while == False)
        {
            // ricerca e stampa di tutti i turni di tutti i lavoratori
            turno = 0;
            controllo = False;
            for (i = 0; i < num_dati; i++)
            {
                if (strcmp(dati[i].id, id_totali[k]) == 0)
                {
                    if (controllo == False)
                    {
                        // salvataggio dell'inizio del turno del lavoratore
                        turno++;
                        controllo = True;
                        indice_entrata = i;
                    }
                    else
                    {
                        // stampa tempo del turno del lavoratore
                        controllo = False;
                        indice_uscita = i;
                        printf("Il lavoratore con id %s nel %d° turno ha lavorato per ", dati[indice_entrata].id, turno);
                        calcola_tempo_lavoro(dati[indice_entrata], dati[indice_uscita]);
                    }
                }
            }

            // gestione del caso che il lavoratore non ha finito il turno
            if (controllo == True)
                printf("Il lavoratore con id %s nel %d° turno e' entrato alle %d:%d ma non ha ancora timbrato l'uscita\n", dati[indice_entrata].id, turno, dati[indice_entrata].ora, dati[indice_entrata].min);

            // controllo per uscire dal while + liberazione memoria allocata a matrice degli id
            k++;
            if (k == num_id)
            {
                esci_while = True;
                free(id_totali);
            }
        }
    }
    else
    {
        // ricerca delle righe in cui è presente l'id selezionato
        controllo = False;
        turno = 0;
        for (i = 0; i < num_dati; i++)
        {
            if (strcmp(dati[i].id, id_scelto) == 0)
            {
                if (controllo == False)
                {
                    // salvataggio dell'inizio del turno del lavoratore
                    turno++;
                    indice_entrata = i;
                    controllo = True;
                }
                else
                {
                    // stampa tempo del turno del lavoratore
                    indice_uscita = i;
                    controllo = False;
                    printf("Il lavoratore nel %d° turno con id %s ha lavorato per ", turno, id_scelto);
                    calcola_tempo_lavoro(dati[indice_entrata], dati[indice_uscita]);
                }
            }
        }

        // gestione caso turno non terminato o lavoratore non trovato
        if (turno == 0)
            printf("Lavoratore con ID inserito in input non trovato");
        else
        {
            if (controllo == True)
                printf("Il lavoratore nel %d° turno e' entrato alle %d:%d, ma non ha ancora timbrato l'uscita", turno, dati[indice_entrata].ora, dati[indice_entrata].min);
        }
    }

    // liberazione memoria allocata
    free(dati);
    fclose(file_handle);

    return 0;
}