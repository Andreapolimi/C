#include "lib_registro.h"
#include <stdio.h>

void stampa_elenco(studente *elenco, int num_studenti)
{
    contatori i, j;

    for (i = 0; i < num_studenti; i++)
    {
        printf("%s   %s   %d:%d:%d\n\n", elenco[i].cognome, elenco[i].nome,
               elenco[i].data_nascita.giorno, elenco[i].data_nascita.mese, elenco[i].data_nascita.anno);
        for (j = 0; j < elenco[i].conta_valutazioni; j++)
        {
            printf("\t%d %s %d:%d:%d\n", elenco[i].voti[j].voto, elenco[i].voti[j].materia,
                   elenco[i].voti[j].data_valutazione.giorno, elenco[i].voti[j].data_valutazione.mese, elenco[i].voti[j].data_valutazione.anno);
        }
        printf("\n");
    }
}