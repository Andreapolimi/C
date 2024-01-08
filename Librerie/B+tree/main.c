#include <stdio.h>_
#include <stdlib.h>
#include <stdbool.h>
#include "B+tree.h"

int main()
{
    Bplus_node_t *radice;
    data_t *data;
    bool esci = false;
    int key;

    radice = (Bplus_node_t *)malloc(sizeof(Bplus_node_t));
    radice->cont_keys = 0;
    radice->isleaf = true;
    radice->next_leaf = NULL;

    while (!esci)
    {
        printf("\nInserire il valore da attribuire al nuovo nodo (inserire 0 se si vuole terminare l'operazione): ");
        scanf("%d", &key);
        if (key != 0)
        {
            data = (data_t *)malloc(sizeof(data_t));
            data->key = key;
            InsertKey(&radice, data, data->key, NULL, NULL);
            printf("Inserimento avvenuto con successo\n\n");
            printfLevel(radice);
            printf("\n");
        }
        else
            esci = true;
    }

    return 0;
}