#include "lib_registro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void riscrivi_file_classe(studente elenco[], char file_classe[], int num_studenti)
{
    gestione_file file_mode[] = "w";
    FILE *modifica_classe;
    contatori i;

    modifica_classe = fopen(file_classe, file_mode);
    for (i = 0; i < num_studenti; i++)
    {
        fprintf(modifica_classe, "%s %s %d:%d:%d %s", elenco[i].cognome, elenco[i].nome,
                elenco[i].data_nascita.giorno, elenco[i].data_nascita.mese, elenco[i].data_nascita.anno, elenco[i].percorso_file);

        if (i != num_studenti - 1)
            fprintf(modifica_classe, "\n");
    }

    fclose(modifica_classe);

    printf("File classe riscritto con successo");
}