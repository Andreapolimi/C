#include "lib_registro.h"

char *ottieni_file_classe()
{
    gestione_file nome_file[] = "classi/percorsi_classi.txt";
    gestione_file file_mode[] = "r";
    gestione_file classe_scelta[MAX_CHAR_CLS], classe_confronto[MAX_CHAR_CLS];
    FILE *file_handle;
    bool esci_while;
    char *file_classe;

    file_classe = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));

    file_handle = fopen(nome_file, file_mode);
    if (file_handle == NULL)
    {
        printf("Errore nella lettura di %s\n", nome_file);
        exit(1);
    }
    else
        printf("%s letto con successo\n\n", nome_file);

    printf("Quale classe vuoi analizzare? ");
    scanf("%s", classe_scelta);
    printf("\n");

    esci_while = False;
    while (!feof(file_handle) && esci_while == False)
    {
        fscanf(file_handle, "%s %s", classe_confronto, file_classe);
        if (strcmp(classe_confronto, classe_scelta) == 0)
            esci_while = True;
    }
    file_classe = (char *)realloc(file_classe, (strlen(file_classe) + 1) * sizeof(char));
    printf("File %s acquisito con successo \n", file_classe);

    return file_classe;
}