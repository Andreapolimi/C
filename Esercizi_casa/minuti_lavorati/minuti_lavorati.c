/*  Creare un algoritmo che dopo aver inserito l'id di un lavoratore (o 0 se si vogliono indicare tutti i lavoratori), legga un file
in cui sono salvati gli orari di entrata e uscita dal posto di lavoro. Deve restituire quanto ha/hanno lavorato.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM_ID 6
#define MIN_ORA 60
#define DIM_MAX 50

typedef int contatori;
typedef int controllo;
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

    printf("%d ore e %d minuti", ore, min);
}

int main()
{
    controllo indice_entrata, indice_uscita;
    bool esci_while;
    contatori i, num_dati;
    gestione_file file_name[] = "/Users/andreavaccai/Coding/C/Esercizi_casa/minuti_lavorati/raccolta_attraversamenti.txt";
    gestione_file file_mode[] = "r";
    char *id_scelto;
    riga *dati;

    // apertura file e controllo successo
    FILE *file_handle = fopen(file_name, file_mode);

    if (file_handle == NULL)
    {
        printf("Lettura file fallita, chiusura del programma");
        exit(1);
    }

    dati = (riga *)calloc(1, sizeof(riga));

    i = 0;
    num_dati = 0;

    // creazione delle celle con tutti i dati necessari
    while (!feof(file_handle))
    {
        dati = (riga *)realloc(dati, (i + 1) * sizeof(riga));

        fscanf(file_handle, "%d %d %s", &dati[i].ora, &dati[i].min, dati[i].id);

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
        esci_while = False;
        while (esci_while == False)
        {
            // ricerca id uguale al primo id della tabella
            indice_entrata = 0;
            indice_uscita = -1;
            for (i = 1; i < num_dati && indice_uscita == -1; i++)
            {
                if (strcmp(dati[i].id, dati[indice_entrata].id) == 0)
                    indice_uscita = i;
            }

            // stampa del tempo lavorato
            if (indice_uscita == -1)
                printf("Il lavoratore con id %s e' entrato alle %d:%d ma non ha ancora timbrato l'uscita", dati[indice_entrata].id, dati[indice_entrata].ora, dati[indice_entrata].min);
            else
            {
                printf("Il lavoratore con id %s ha lavorato per ", dati[indice_entrata].id);
                calcola_tempo_lavoro(dati[indice_entrata], dati[indice_uscita]);
            }

            printf("\n");

            // rimozione righe già utilizzate
            for (i = indice_entrata; i < num_dati - 1; i++)
            {
                dati[i].ora = dati[i + 1].ora;
                dati[i].min = dati[i + 1].min;
                strcpy(dati[i].id, dati[i + 1].id);
            }
            num_dati--;

            if (indice_uscita != -1)
            {
                for (i = indice_uscita - 1; i < num_dati - 1; i++)
                {
                    dati[i].ora = dati[i + 1].ora;
                    dati[i].min = dati[i + 1].min;
                    strcpy(dati[i].id, dati[i + 1].id);
                }
                num_dati--;
            }

            if (num_dati == 0)
                esci_while = True;
            else
                dati = (riga *)realloc(dati, num_dati * sizeof(riga));
        }
    }
    else
    {
        // ricerca delle righe in cui è presente l'id selezionato
        indice_entrata = -1;
        indice_uscita = -1;
        for (i = 0; i < num_dati && indice_uscita == -1; i++)
        {
            if (strcmp(dati[i].id, id_scelto) == 0)
            {
                if (indice_entrata == -1)
                    indice_entrata = i;
                else
                {
                    indice_uscita = i;
                }
            }
        }
        if (indice_entrata == -1)
            printf("Lavoratore con ID inserito in input non trovato");
        else
        {
            if (indice_uscita == -1)
                printf("Il lavoratore e' entrato alle %d:%d, ma non ha ancora timbrato l'uscita", dati[indice_entrata].ora, dati[indice_entrata].min);
            else
            {
                printf("Il lavoratore con id %s ha lavorato per ", id_scelto);
                calcola_tempo_lavoro(dati[indice_entrata], dati[indice_uscita]);
            }
        }
    }

    free(dati);
    fclose(file_handle);

    return 0;
}