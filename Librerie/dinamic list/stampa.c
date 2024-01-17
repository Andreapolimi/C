#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val;
    struct nodo *next;
} nodo_t;

void StampaLista(nodo_t *temp)
{
    while (temp != NULL)
    {
        printf("%d %d %d\n", temp->val);
        temp = temp->next;
    }
}