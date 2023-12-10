#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

int main()
{
    tree_t *radice = NULL, *search;
    int risposta;
    char key[MAX_CHAR];

    while (strcmp(key, "T") != 0)
    {
        printf("Inserire il valore da attribuire al nuovo nodo (inserire T se si vuole terminare l'operazione): ");
        scanf("%s", key);
        if (strcmp(key, "T") != 0)
        {
            InsertTree(&radice, key);
            IfBalanced(&radice);
        }
    }

    return 0;
}