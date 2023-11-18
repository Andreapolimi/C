#include "treelib.h"
#include <stdio.h>

void stampa_albero(nodo_t *posizione, int i)
{
    while (posizione != NULL)
    {
        for (int j = 0; j < i; j++)
            printf("\t");
        printf("%d\n", posizione->valore);

        if (posizione->primo_figlio != NULL)
            stampa_albero(posizione->primo_figlio, i + 1);

        posizione = posizione->el_successivo;
    }
}