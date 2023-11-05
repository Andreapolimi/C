#include "lib_registro.h"

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