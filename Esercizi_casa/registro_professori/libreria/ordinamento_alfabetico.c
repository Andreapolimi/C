#include "lib_registro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// la funzione viene chiamata dopo aver controllato che nessuno degli studenti è stato inserito due volte,
// quindi non serve effettuare nuovamente il controllo
// Ogni qual volta viene chiamata tutti gli elementi dell'elenco sono già ordinati, perciò basta inserire l'utente al posto giusto rispetto all'elenco fornito

studente *riordina_elenco(studente *elenco, int num_studenti)
{
    contatori i, j;
    studente temp;

    for (i = 0; i < num_studenti - 2; i++)
    {
        if (strcmp(elenco[num_studenti - 1].cognome, elenco[i].cognome) != 0)
        {
            if (strcmp(elenco[num_studenti - 1].cognome, elenco[i].cognome) < 0)
            {
                temp = elenco[num_studenti - 1];
                for (j = num_studenti - 1; j > i; j--)
                {
                    elenco[j] = elenco[j - 1];
                }
                elenco[i] = temp;
            }
        }
        else
        {
            if (strcmp(elenco[num_studenti - 1].nome, elenco[i].nome) < 0)
            {
                temp = elenco[num_studenti - 1];
                for (j = num_studenti - 1; j > i; j--)
                {
                    elenco[j] = elenco[j - 1];
                }
                elenco[i] = temp;
            }
        }
    }
    printf("Utente inserito secondo l'ordinamento alfabetico\n");

    return elenco;
}