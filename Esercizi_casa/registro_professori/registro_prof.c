#include "libreria/lib_registro.h"
#include <stdio.h>

int main()
{
    studente *elenco;
    contatori num_studenti;
    gestione_file *file_classe;

    file_classe = ottieni_file_classe();
    elenco = struttura_elenco(&num_studenti, file_classe);
    stampa_elenco(elenco, num_studenti);

    return 0;
}