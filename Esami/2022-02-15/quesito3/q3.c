#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val, freq;
    struct node *next;
} node_t;

node_t *CercaPrec(node_t *temp, node_t *ptr_node)
{
    while (temp->next != ptr_node)
        temp = temp->next;
    return temp;
}

node_t *MinimoInTesta(node_t *testa)
{
    node_t *ptr_min = testa, *ptr_ptr_min, *temp = testa->next;

    while (temp != NULL)
    {
        if (temp->val < ptr_min->val)
            ptr_min = temp;
        temp = temp->next;
    }
    if (ptr_min != testa)
    {
        ptr_ptr_min = CercaPrec(testa, ptr_min);
        ptr_ptr_min->next = ptr_min->next;
        ptr_min->next = testa;
    }
    return ptr_min;
}

node_t *Ordina(node_t *testa)
{
    testa = MinimoInTesta(testa);
    if (testa->next != NULL)
        testa->next = Ordina(testa->next);
    return testa;
}

node_t *CreaNodo()
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = NULL;
    return new_node;
}

node_t *CostruisciLista(node_t *ptr_lista1)
{
    node_t *lista2 = NULL, *ptr_lista2;

    ptr_lista1 = Ordina(ptr_lista1);

    while (ptr_lista1 != NULL)
    {
        if (lista2 == NULL)
        {
            lista2 = (node_t *)malloc(sizeof(node_t));
            ptr_lista2 = lista2;
            ptr_lista2->val = ptr_lista1->val;
            ptr_lista2->freq = 1;
            ptr_lista2->next = NULL;
        }
        else if (ptr_lista1->val == ptr_lista2->val)
            ptr_lista2->freq++;
        else
        {
            ptr_lista2->next = CreaNodo();
            ptr_lista2 = ptr_lista2->next;
            ptr_lista2->val = ptr_lista1->val;
            ptr_lista2->freq = 1;
        }
        ptr_lista1 = ptr_lista1->next;
    }
    return lista2;
}

void StampaLista(node_t *temp)
{
    while (temp != NULL)
    {
        printf("%d,%d->", temp->val, temp->freq);
        temp = temp->next;
    }
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
            testa->freq = 1;
        }
    }
    return testa;
}

int main()
{
    node_t *lista1 = NULL, *lista2 = NULL;

    lista1 = inserisci_elementi(lista1);
    StampaLista(lista1);
    printf("\n");
    lista2 = CostruisciLista(lista1);
    StampaLista(lista2);

    return 0;
}