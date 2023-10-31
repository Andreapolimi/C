/*
Si definisca una struttura dati per gestire un registro elettronico del docente,
contenente le valutazioni di un’intera classe in una disciplina.
Per ogni studente, è necessario memorizzare nome, cognome e data di nascita.
Una valutazione è espressa con un voto da 1 a 10 (senza mezzi voti), è relativa a una data ed è associata a uno studente.
Il registro contiene l’elenco degli studenti e l’elenco di valutazioni assegnate.
Per semplicità, è possibile assumere che non esistano casi di omonimia di cognome.
Dato il nome di uno studente, calcolare la media delle sue valutazioni.
*/

// dichiarazione librerie
#include <stdio.h>
#include <stdlib.h>

// dichiarazione costanti
#define DIM_MAX 50

// dichiarazione tipi variabili aggiuntivi
typedef enum bool
{
    False,
    True
} bool;
typedef int contatori;

typedef int controllo;

typedef struct data
{
    int giorno, mese, anno;
} data;

typedef struct val
{
    data data_valutazione;
    int voto;
    char *materia;
} valutazioni;

typedef struct stu
{
    char *nome, *cognome;
    data data_nascita;
    valutazioni *voti;
} studente;

// funzione per aggiunta studente alla classe
void aggiunta_studente(studente **elenco, int num_studenti)
{
    *elenco = (studente *)realloc(*elenco, (num_studenti) * sizeof(studente));
    elenco[num_studenti - 1]->nome = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));
    printf("Inserire il nome dello studente: ");
    scanf("%s", elenco[num_studenti - 1]->nome);

    elenco[num_studenti - 1]->cognome = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));
    printf("Inserire il cognome dello studente: ");
    scanf("%s", elenco[num_studenti - 1]->cognome);

    printf("Inserire la data di nascita dello studente nel formato DD:MM:YYYY: ");
    scanf("%d:%d:%d", elenco[num_studenti - 1]->data_nascita.giorno,
          elenco[num_studenti - 1]->data_nascita.mese,
          elenco[num_studenti - 1]->data_nascita.anno);
}

// funzione che riordina l'elenco in ordine alfabetico
void riordina_elenco(studente **elenco, int num_studenti)
{
    contatori i, j, k, indice_scambio;
    bool lettera_diversa, cognome_uguale;
    int distanza_minore, distanza_temporanea;
    studente temporaneo;

    for (i = 0; i < num_studenti; i++)
    {
        lettera_diversa = False;
        cognome_uguale = False;
        for (j = 0; j < strlen(elenco[i]->cognome) && lettera_diversa == False; j++)
        {
            if (elenco[i]->cognome[j] > elenco[i + 1]->cognome[j])
            {
                distanza_minore = elenco[i]->cognome[j] - elenco[i + 1]->cognome[j];
                indice_scambio = i + 1;
                for (k = i + 2; k < num_studenti; k++)
                {
                    distanza_temporanea = elenco[i]->cognome[j] - elenco[k]->cognome[j];
                    if (elenco[i]->cognome[j] > elenco[k]->cognome[j] && distanza_minore > distanza_temporanea && distanza_temporanea >= 0)
                    {
                        indice_scambio = k;
                        distanza_minore = distanza_temporanea;
                    }
                }
                temporaneo = *elenco[i];
                for (k = i; k < indice_scambio; k++)
                {
                    *elenco[k] = *elenco[k + 1];
                }
                *elenco[indice_scambio] = temporaneo;
            }
            else
            {
                if (elenco[i]->cognome[j] < elenco[i + 1]->cognome[j])
                {
                    distanza_minore = elenco[i + 1]->cognome[j] - elenco[i]->cognome[j];
                    indice_scambio = i + 1;
                    for (k = i + 2; k < num_studenti; k++)
                    {
                        distanza_temporanea = elenco[k]->cognome[j] - elenco[i]->cognome[j];
                        if (elenco[i]->cognome[j] < elenco[k]->cognome[j] && distanza_minore > distanza_temporanea && distanza_temporanea >= 0)
                        {
                            indice_scambio = k;
                            distanza_minore = distanza_temporanea;
                        }
                    }
                    temporaneo = *elenco[i];
                    for (k = i; k > indice_scambio; k--)
                    {
                        *elenco[k] = *elenco[k - 1];
                    }
                    *elenco[indice_scambio] = temporaneo;
                }
            }
            if (cognome_uguale == True)
            {
                for (j = 0; j < strlen(elenco[i]->nome) && lettera_diversa == False; j++)
                {
                    if (elenco[i]->cognome[j] > elenco[i + 1]->cognome[j])
                    {
                        distanza_minore = elenco[i]->cognome[j] - elenco[i + 1]->cognome[j];
                        indice_scambio = i + 1;
                        for (k = i + 2; k < num_studenti; k++)
                        {
                            distanza_temporanea = elenco[i]->cognome[j] - elenco[k]->cognome[j];
                            if (elenco[i]->cognome[j] > elenco[k]->cognome[j] && distanza_minore > distanza_temporanea && distanza_temporanea >= 0)
                            {
                                indice_scambio = k;
                                distanza_minore = distanza_temporanea;
                            }
                        }
                        temporaneo = *elenco[i];
                        for (k = i; k < indice_scambio; k++)
                        {
                            *elenco[k] = *elenco[k + 1];
                        }
                        *elenco[indice_scambio] = temporaneo;
                    }
                    else
                    {
                        if (elenco[i]->cognome[j] < elenco[i + 1]->cognome[j])
                        {
                            distanza_minore = elenco[i + 1]->cognome[j] - elenco[i]->cognome[j];
                            indice_scambio = i + 1;
                            for (k = i + 2; k < num_studenti; k++)
                            {
                                distanza_temporanea = elenco[k]->cognome[j] - elenco[i]->cognome[j];
                                if (elenco[i]->cognome[j] < elenco[k]->cognome[j] && distanza_minore > distanza_temporanea && distanza_temporanea >= 0)
                                {
                                    indice_scambio = k;
                                    distanza_minore = distanza_temporanea;
                                }
                            }
                            temporaneo = *elenco[i];
                            for (k = i; k > indice_scambio; k--)
                            {
                                *elenco[k] = *elenco[k - 1];
                            }
                            *elenco[indice_scambio] = temporaneo;
                        }
                    }
                }
            }
        }
    }

    // funzione aggiunta valutazione allo studente

    // funzione modifica di una certa caratteristica dello studente

    // funzione per il calcolo della media in una determinata materia

    // main dove il prof può vedere le azioni che può compiere