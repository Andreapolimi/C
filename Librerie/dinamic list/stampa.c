#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val;
    struct nodo *next;
} node_t;

void StampaLista(node_t *temp)
{
    while (temp != NULL)
    {
        printf("%d\t", temp->val);
        temp = temp->next;
    }
}