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

    printf("%d ore e %d minuti\n", ore, min);
}

int main()
{
    controllo indice_entrata, indice_uscita, turno;
    bool esci_while, controllo;
    contatori i, j, k, num_dati, num_id;
    gestione_file file_name[] = "/Users/andreavaccai/Coding/C/Esercizi_casa/minuti_lavorati/raccolta_attraversamenti.txt";
    gestione_file file_mode[] = "r";
    char *id_scelto, **id_totali;
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
        num_id = 0;
        id_totali = (char **)calloc(num_id + 1, (num_id + 1) * sizeof(char *));
        for (i = 0; i < num_dati; i++)
        {
            controllo = False;
            for (j = 0; j < num_id && controllo == False; j++)
            {
                if (strcmp(id_totali[j], dati[i].id) == 0)
                    controllo = True;
            }
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
            // ricerca id uguale al primo id della tabella
            turno = 0;
            controllo = False;
            for (i = 0; i < num_dati; i++)
            {
                if (strcmp(dati[i].id, id_totali[k]) == 0)
                {
                    if (controllo == False)
                    {
                        turno++;
                        controllo = True;
                        indice_entrata = i;
                    }
                    else
                    {
                        controllo = False;
                        indice_uscita = i;
                        printf("Il lavoratore con id %s nel %d° turno ha lavorato per ", dati[indice_entrata].id, turno);
                        calcola_tempo_lavoro(dati[indice_entrata], dati[indice_uscita]);
                    }
                }
            }

            // stampa del tempo lavorato
            if (controllo == True)
                printf("Il lavoratore con id %s nel %d° turno e' entrato alle %d:%d ma non ha ancora timbrato l'uscita\n", dati[indice_entrata].id, turno, dati[indice_entrata].ora, dati[indice_entrata].min);

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
                    turno++;
                    indice_entrata = i;
                    controllo = True;
                }
                else
                {
                    indice_uscita = i;
                    controllo = False;
                    printf("Il lavoratore nel %d° turno con id %s ha lavorato per ", turno, id_scelto);
                    calcola_tempo_lavoro(dati[indice_entrata], dati[indice_uscita]);
                }
            }
        }
        if (turno == 0)
            printf("Lavoratore con ID inserito in input non trovato");
        else
        {
            if (controllo == True)
                printf("Il lavoratore nel %d° turno e' entrato alle %d:%d, ma non ha ancora timbrato l'uscita", turno, dati[indice_entrata].ora, dati[indice_entrata].min);
        }
    }

    free(dati);
    fclose(file_handle);

    return 0;
}