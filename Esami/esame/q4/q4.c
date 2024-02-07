#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valore;
    struct node *next;
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

void modifica(node_t *testa, node_t **testa_pos, node_t **testa_neg)
{
    node_t *ptr_pos, *ptr_neg, *temp;

    while (testa != NULL)
    {
        temp = testa->next;
        if (testa->valore >= 0)
        {
            if ((*testa_pos) == NULL)
            {
                *testa_pos = testa;
                ptr_pos = *testa_pos;
                ptr_pos->next = NULL;
            }
            else
            {
                ptr_pos->next = testa;
                ptr_pos->next->next = NULL;
                ptr_pos = ptr_pos->next;
            }
        }
        else
        {
            if ((*testa_neg) == NULL)
            {
                *testa_neg = testa;
                ptr_neg = *testa_neg;
                ptr_neg->next = NULL;
            }
            else
            {
                ptr_neg->next = testa;
                ptr_neg->next->next = NULL;
                ptr_neg = ptr_neg->next;
            }
        }
        testa = temp;
    }
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
    node_t *testa = NULL, *testa_pos = NULL, *testa_neg = NULL;

    testa = inserisci_elementi(testa);
    StampaLista(testa);
    printf("\n");
    modifica(testa, &testa_pos, &testa_neg);
    testa = NULL;
    StampaLista(testa_pos);
    printf("\n");
    StampaLista(testa_neg);

    return 0;
}