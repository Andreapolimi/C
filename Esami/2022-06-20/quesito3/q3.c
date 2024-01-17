#include <stdio.h>
#include <stdlib.h>

#define N 32

typedef struct mem
{
    char carattere;
    int freq;
} memorizza_t;

char Max(memorizza_t *array, int dim)
{
    memorizza_t più_freq = array[0];
    int i;

    for (i = 1; i < dim; i++)
        if (array[i].freq > più_freq.freq)
            più_freq = array[i];
    return più_freq.carattere;
}

char PiùFrequente(char *array, int *indice)
{
    memorizza_t *array_freq;
    int i = 0, dim = 0, inserito;

    array_freq = (memorizza_t *)malloc(sizeof(memorizza_t));
    array_freq[i].carattere = array[*indice];
    array_freq[i].freq = 1;
    dim++;
    (*indice)++;

    while (array[*indice] != ')')
    {
        inserito = 0;
        for (i = 0; i < dim && inserito == 0; i++)
            if (array[*indice] == array_freq[i].carattere)
            {
                array_freq[i].freq++;
                inserito = 1;
            }
        if (!inserito)
        {
            array_freq[dim - 1].carattere = array[*indice];
            array_freq[dim - 1].freq = 1;
        }
        (*indice)++;
    }
    return Max(array_freq, dim);
}

char *Modifica(char *array_iniziale)
{
    char *nuovo_array;
    int j = 0, i;

    for (i = 0; i < N; i++)
    {
        if (j == 0)
            nuovo_array = (char *)malloc((j + 1) * sizeof(char));

        if (array_iniziale[i] != '(')
        {
            nuovo_array = (char *)realloc(nuovo_array, (j + 1) * sizeof(char));
            nuovo_array[j] = array_iniziale[i];
            j++;
        }
        else
        {
            nuovo_array = (char *)realloc(nuovo_array, (j + 3) * sizeof(char));
            nuovo_array[j] = array_iniziale[i];
            j++;
            nuovo_array[j] = PiùFrequente(array_iniziale, &i);
            j++;
            nuovo_array[j] = array_iniziale[i];
            j++;
        }
    }
    return nuovo_array;
}

int main()
{
    char array[N + 1], *nuovo_array;

    printf("inserire la stringa da modificare: ");
    scanf("%s", array);
    printf("%s\n", array);
    nuovo_array = Modifica(array);
    printf("%s", nuovo_array);

    return 0;
}
