#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50
#define MAX_EL 8

typedef struct lista
{
    char el[MAX_CHAR];
    int quant;
} lista_t;

void scriviFile(FILE *ptr_in, FILE *ptr_out)
{

    char campione[MAX_CHAR];
    int quant, num_el = 0, i, trovato = 0;
    lista_t lista[MAX_EL];

    while (!feof(ptr_in))
    {
        fscanf(ptr_in, "%s %d", campione, &quant);

        trovato = 0;
        for (i = 0; i < num_el && trovato == 0; i++)
        {
            if (strcmp(lista[i].el, campione) == 0)
            {
                lista[i].quant += quant;
                trovato = 1;
            }
        }
        if (!trovato)
        {
            strcpy(lista[i].el, campione);
            lista[i].quant = quant;
            num_el++;
        }
    }

    for (i = 0; i < num_el; i++)
    {
        fprintf(ptr_out, "%s %d", lista[i].el, lista[i].quant);
    }
}

int main(int argc, char *argv[])
{
    FILE *ptr_in = fopen(argv[1], "r");
    FILE *ptr_out = fopen(argv[2], "w");

    scriviFile(ptr_in, ptr_out);

    return 0;
}