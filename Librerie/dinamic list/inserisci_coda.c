#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val, row, col;
    struct nodo *next;
} nodo_t;

node_t *inserisci_elementi(node_t *testa)
{
    node_t *ptr_nodo;
    int valore = 0;

    while (valore != -1)
    {
        printf("Inserire il valore per il nodo (inserire -1 se si vuole terminare l'inserimento)\n");
        scanf("%d", &valore);
        if (valore != -1)
        {
            if (testa == NULL)
            {
                testa = (node_t *)malloc(sizeof(node_t));
                ptr_nodo = testa;
                testa->next = NULL;
                testa->valore = valore;
            }
            else
            {
                ptr_nodo->next = (node_t *)malloc(sizeof(node_t));
                ptr_nodo->next->valore = valore;
                ptr_nodo = ptr_nodo->next;
                ptr_nodo->next = NULL;
            }
        }
    }
    return testa;
}