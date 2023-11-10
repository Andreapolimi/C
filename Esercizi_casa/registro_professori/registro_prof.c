#include "libreria/lib_registro.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    studente *elenco;
    contatori num_studenti;
    gestione_file *file_classe, classe[MAX_CHAR_CLS], *file_studente;

    printf("Inserire la classe da analizzare: ");
    scanf("%s", classe);

    file_classe = ottieni_file_classe(classe);

    elenco = struttura_elenco(&num_studenti, file_classe);

    num_studenti++;
    elenco = aggiunta_studente(elenco, num_studenti, file_classe, classe);

    elenco = riordina_elenco(elenco, num_studenti);

    stampa_elenco(elenco, num_studenti);

    riscrivi_file_classe(elenco, file_classe, num_studenti);

    free(elenco);

    return 0;
}