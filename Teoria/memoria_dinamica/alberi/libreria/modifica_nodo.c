#include "treelib.h"
#include <stdio.h>

void modifica_nodo(nodo_t *radice)
{
    nodo_t *posizione;

    posizione = ricerca_nodo(radice, 0);

    if (posizione == radice)
        printf("\nStai modificando la radice\n");

    printf("\nInserire l' elemento da attribuire al nodo: ");
    scanf("%d", &posizione->valore);
}