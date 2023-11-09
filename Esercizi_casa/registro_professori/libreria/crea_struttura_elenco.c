#include "lib_registro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int struttura_valutazioni(valutazioni **voti, char *nome_file)
{
    gestione_file file_mode[] = "r";
    FILE *file_handle;
    contatori j;

    file_handle = fopen(nome_file, file_mode);
    if (file_handle == NULL)
    {
        printf("Errore nella lettura di %s\n", nome_file);
        exit(1);
    }
    else
        printf("%s letto con successo\n", nome_file);

    j = 0;
    while (!feof(file_handle))
    {
        *voti = (valutazioni *)realloc(*voti, (j + 1) * sizeof(valutazioni));
        (*voti)[j].materia = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));
        fscanf(file_handle, "%d %s %d:%d:%d", &(*voti)[j].voto,
               (*voti)[j].materia, &(*voti)[j].data_valutazione.giorno, &(*voti)[j].data_valutazione.mese, &(*voti)[j].data_valutazione.anno);
        (*voti)[j].materia = (char *)realloc((*voti)[j].materia, (strlen((*voti)[j].materia) + 1) * sizeof(char));
        j++;
    }

    return j;
}

studente *struttura_elenco(contatori *i, gestione_file nome_file[])
{
    studente *elenco;
    gestione_file file_mode[] = "r";
    FILE *file_handle;

    file_handle = fopen(nome_file, file_mode);
    if (file_handle == NULL)
    {
        printf("Errore nella lettura di %s\n", nome_file);
        exit(1);
    }
    else
        printf("%s letto con successo\n", nome_file);

    elenco = (studente *)calloc(1, sizeof(studente));

    *i = 0;
    while (!feof(file_handle))
    {
        elenco = (studente *)realloc(elenco, (*i + 1) * sizeof(studente));

        elenco[*i].nome = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));
        elenco[*i].cognome = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));
        elenco[*i].percorso_file = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));

        fscanf(file_handle, "%s %s %d:%d:%d %s", elenco[*i].cognome, elenco[*i].nome,
               &elenco[*i].data_nascita.giorno, &elenco[*i].data_nascita.mese, &elenco[*i].data_nascita.anno,
               elenco[*i].percorso_file);

        elenco[*i].nome = (char *)realloc(elenco[*i].nome, (strlen(elenco[*i].nome) + 1) * sizeof(char));
        elenco[*i].cognome = (char *)realloc(elenco[*i].cognome, (strlen(elenco[*i].cognome) + 1) * sizeof(char));
        elenco[*i].percorso_file = (char *)realloc(elenco[*i].percorso_file, (strlen(elenco[*i].percorso_file) + 1) * sizeof(char));

        elenco[*i].voti = (valutazioni *)calloc(1, sizeof(valutazioni));

        elenco[*i].conta_valutazioni = struttura_valutazioni(&elenco[*i].voti, elenco[*i].percorso_file);

        (*i)++;
    }

    printf("\n");

    fclose(file_handle);

    printf("Struttura studente creata con successo\n");

    return elenco;
}