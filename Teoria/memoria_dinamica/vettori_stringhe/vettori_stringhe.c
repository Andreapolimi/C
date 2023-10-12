#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_MAX 50

int main()
{
    char **lista_spesa, *elemento;
    int dim_elem, dim_lista = 1, i;

    lista_spesa = (char **)calloc(dim_lista, dim_lista * sizeof(char *));

    elemento = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));

    printf("Inserire la prima stringa: ");
    scanf("%s", elemento);

    for (i = 0; strcmp(elemento, "0") != 0; i++)
    {
        dim_elem = strlen(elemento);

        elemento = (char *)realloc(elemento, dim_elem * sizeof(char));

        lista_spesa[i] = elemento;

        elemento = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));

        printf("Inserisci un altro elemento (se si vuole terminare l'inserimento digitare '0'): ");
        scanf("%s", elemento);

        if (strcmp(elemento, "0") != 0)
        {
            dim_lista += 1;
            lista_spesa = (char **)realloc(lista_spesa, dim_lista * sizeof(char *));
        }
    }

    for (i = 0; i < dim_lista; i++)
    {
        printf("%s, dimensione occupata = %d\n", lista_spesa[i], (int)strlen(lista_spesa[i]));
    }

    return 0;
}