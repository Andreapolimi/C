#include "lib_registro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

studente *aggiunta_studente(studente *elenco, int num_studenti, char file_classe[], char classe[])
{
    FILE *nuovo_studente;
    gestione_file file_mode[] = "w";
    int i;

    elenco = (studente *)realloc(elenco, (num_studenti) * sizeof(studente));

    i = num_studenti - 1;

    elenco[i].nome = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));
    printf("Inserire il nome dello studente: ");
    scanf("%s", elenco[i].nome);
    elenco[i].nome = (char *)realloc(elenco[i].nome, (strlen(elenco[i].nome) + 1) * sizeof(char));

    elenco[i].cognome = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));
    printf("Inserire il cognome dello studente: ");
    scanf("%s", elenco[i].cognome);
    elenco[i].cognome = (char *)realloc(elenco[i].cognome, (strlen(elenco[i].cognome) + 1) * sizeof(char));

    printf("Inserire la data di nascita dello studente nel formato DD:MM:YYYY: ");
    scanf("%d:%d:%d", &elenco[i].data_nascita.giorno,
          &elenco[i].data_nascita.mese,
          &elenco[i].data_nascita.anno);

    elenco[i].percorso_file = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));
    strcat(elenco[i].percorso_file, "file_classi/");
    strcat(elenco[i].percorso_file, classe);
    strcat(elenco[i].percorso_file, "/file_studenti/");
    strcat(elenco[i].percorso_file, elenco[i].cognome);
    strcat(elenco[i].percorso_file, "_");
    strcat(elenco[i].percorso_file, elenco[i].nome);
    strcat(elenco[i].percorso_file, ".txt");
    elenco[i].percorso_file = (char *)realloc(elenco[i].percorso_file, (strlen(elenco[i].percorso_file) + 1) * sizeof(char));

    nuovo_studente = fopen(elenco[i].percorso_file, file_mode);

    fclose(nuovo_studente);

    printf("Studente aggiunto alla struttura dati con successo\n");

    return elenco;
}

void riscrivi_file_classe(studente elenco[], char file_classe[], int num_studenti)
{
    gestione_file file_mode[] = "w";
    FILE *modifica_classe;
    contatori i;

    modifica_classe = fopen(file_classe, file_mode);
    for (i = 0; i < num_studenti; i++)
    {
        fprintf(modifica_classe, "%s %s %d:%d:%d %s\n", elenco[i].cognome, elenco[i].nome,
                elenco[i].data_nascita.giorno, elenco[i].data_nascita.mese, elenco[i].data_nascita.anno, elenco[i].percorso_file);
    }

    fclose(modifica_classe);

    printf("File classe riscritto con successo");
}