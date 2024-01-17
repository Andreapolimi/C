#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valore;
    struct nodo *next;
} node_t;

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

void Modifica(node_t *ptr_nodo, int val_prec)
{
    int temp = ptr_nodo->valore;

    ptr_nodo->valore += val_prec;
    if (ptr_nodo->next != NULL)
        Modifica(ptr_nodo->next, temp);
}

void StampaLista(node_t *temp)
{
    while (temp != NULL)
    {
        printf("%d\t", temp->valore);
        temp = temp->next;
    }
}

int main()
{
    node_t *testa = NULL;

    testa = inserisci_elementi(testa);
    StampaLista(testa);
    Modifica(testa, 0);
    StampaLista(testa);

    return 0;
}