#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int valore;
    struct lista *next;
} node_t;

typedef enum
{
    False,
    True
} bool_t;

typedef int cont_t;

node_t *ottieni_nodo(node_t *ptr_nodo, int k)
{
    bool_t trovato = False;
    node_t *ptr_salto = ptr_nodo;
    cont_t i = 0;

    while (ptr_salto->next != NULL)
    {
        ptr_nodo = ptr_nodo->next;
        ptr_salto = ptr_salto->next->next;
    }
    while (!trovato && ptr_nodo != NULL)
    {
        if (i == k)
            trovato = True;
        else
        {
            ptr_nodo = ptr_nodo->next;
            i++;
        }
    }

    return ptr_nodo;
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

void stampa_lista(node_t *ptr_nodo)
{
    while (ptr_nodo != NULL)
    {
        printf("%d ", ptr_nodo->valore);
        ptr_nodo = ptr_nodo->next;
    }
}
int main()
{
    node_t *testa = NULL, *nodo_richiesto;
    int k;

    testa = inserisci_elementi(testa);

    printf("Inserire il numero di nodi che separano quello che cerchi dal centro: ");
    scanf("%d", &k);

    stampa_lista(testa);
    printf("\n");

    nodo_richiesto = ottieni_nodo(testa, k);

    if (nodo_richiesto == NULL)
        printf("La posizione indicata supera il numero di nodi della lista");
    else
        printf("%d", nodo_richiesto->valore);

    return 0;
}