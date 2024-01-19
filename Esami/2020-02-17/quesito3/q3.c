#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node_t;

node_t *Rotazione(node_t *testa, int dir)
{
    node_t *temp, *ptr_lista;

    if (testa != NULL && testa->next != NULL)
    {
        if (dir == 0)
        {
            temp = testa;
            testa = testa->next;
            ptr_lista = testa;
            while (ptr_lista->next != NULL)
                ptr_lista = ptr_lista->next;
            ptr_lista->next = temp;
            temp->next = NULL;
        }
        else if (dir == 1)
        {
            temp = testa;
            ptr_lista = testa;
            while (ptr_lista->next->next != NULL)
                ptr_lista = ptr_lista->next;
            testa = ptr_lista->next;
            testa->next = temp;
            ptr_lista->next = NULL;
        }
    }
    return testa;
}

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
                testa->val = valore;
            }
            else
            {
                ptr_nodo->next = (node_t *)malloc(sizeof(node_t));
                ptr_nodo->next->val = valore;
                ptr_nodo = ptr_nodo->next;
                ptr_nodo->next = NULL;
            }
        }
    }
    return testa;
}

void StampaLista(node_t *temp)
{
    while (temp != NULL)
    {
        printf("%d\t", temp->val);
        temp = temp->next;
    }
}

int main()
{
    node_t *testa = NULL;
    int dir;

    testa = inserisci_elementi(testa);

    printf("Inserire direzione (0 a destra, 1 a sinistra): ");
    scanf("%d", &dir);

    StampaLista(testa);
    printf("\n");
    testa = Rotazione(testa, dir);
    StampaLista(testa);

    return 0;
}