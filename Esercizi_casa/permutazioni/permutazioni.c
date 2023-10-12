#include <stdio.h>
#include <stdlib.h>

void printArray(int **array, int dim)
{
    printf("[");
    for (int i = 0; i < dim; i++)
    {
        printf("%d", (*array)[i]);
    }
    printf("]");
}

typedef int dimensione;
typedef int contatori;
typedef int puntatori;

typedef enum bool
{
    False,
    True
} Bool;

int main()
{
    puntatori *sequenza1, *sequenza2, *sequenza2_copia;
    dimensione dim1, dim2;
    contatori i, j, k;
    Bool esci;

    printf("Inserire qunati numeri comporranno le sequenze: ");
    scanf("%d", &dim1);
    dim2 = dim1;

    sequenza1 = (int *)calloc(dim1, dim1 * sizeof(int));
    sequenza2 = (int *)calloc(dim2, dim2 * sizeof(int));
    sequenza2_copia = (int *)calloc(dim2, dim2 * sizeof(int));

    for (i = 0; i < dim1; i++)
    {
        printf("Inserire il %d° numero della sequenza 1: ", i + 1);
        scanf("%d", &sequenza1[i]);
    }

    for (i = 0; i < dim2; i++)
    {
        printf("Inserire il %d° numero della sequenza 2: ", i + 1);
        scanf("%d", &sequenza2[i]);
        sequenza2_copia[i] = sequenza2[i];
    }

    for (i = 0; i < dim1 && dim2 != 0; i++)
    {
        esci = False;
        for (j = 0; j < dim2 && esci == False; j++)
        {
            if (sequenza1[i] == sequenza2_copia[j])
            {
                for (k = j; k < dim2; k++)
                {
                    sequenza2_copia[k] = sequenza2_copia[k + 1];
                }
                dim2--;
                esci = True;
                sequenza2_copia = (int *)realloc(sequenza2_copia, dim2 * sizeof(int));
            }
        }
    }

    printf("La sequenza ");
    printArray(&sequenza2, dim1);

    if (dim2 == 0)
    {
        printf(" e' una permutazione di ");
    }
    else
        printf(" non e' una permutazione di ");

    printArray(&sequenza1, dim1);

    return 0;
}