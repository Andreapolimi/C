#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef enum
{
    False,
    True
} bool_t;

int AiutaMamma(FILE *ptr_ricetta, FILE *ptr_dispensa)
{
    char ingrediente_cercato[MAX], ingrediente_analizzato[MAX];
    int quantità_richiesta, quantità_presente;
    bool_t trovato, procedi;

    procedi = True;
    while (!feof(ptr_ricetta))
    {
        fscanf(ptr_ricetta, "%s %d", ingrediente_cercato, &quantità_richiesta);

        trovato = False;
        rewind(ptr_dispensa);
        while (!feof(ptr_dispensa) && trovato == False)
        {
            fscanf(ptr_dispensa, "%s %d", ingrediente_analizzato, &quantità_presente);
            if (strcmp(ingrediente_cercato, ingrediente_analizzato) == 0)
            {
                trovato = True;
                if (quantità_richiesta <= quantità_presente)
                    printf("%s OK\n", ingrediente_cercato);
                else
                {
                    printf("%s manca %d\n", ingrediente_cercato, quantità_richiesta - quantità_presente);
                    procedi = False;
                }
            }
        }
    }

    return procedi;
}

int main(int argc, char *argv[])
{
    FILE *ptr_ricetta, *ptr_dispensa;
    bool_t procedi;

    if ((ptr_ricetta = fopen(argv[1], "r")) == NULL)
    {
        printf("File %s non trovato", argv[1]);
        exit(1);
    }
    else
        printf("File %s aperto con successo\n", argv[1]);

    if ((ptr_dispensa = fopen(argv[2], "r")) == NULL)
    {
        printf("File %s non trovato", argv[2]);
        exit(1);
    }
    else
        printf("File %s aperto con successo\n", argv[2]);

    procedi = AiutaMamma(ptr_ricetta, ptr_dispensa);

    if (procedi)
        printf("Puoi cucinare la tua ricetta");
    else
        printf("Non puoi cucinare la tua ricetta");

    return 0;
}
