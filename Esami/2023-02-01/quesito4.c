#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valore;
    struct node *next;
} node_t;
typedef int cont_t;
typedef enum
{
    False,
    True
} bool_t;

node_t *rotazione_destra(node_t *testa, int k, int num_nodi)
{
    node_t *ptr_nodo = testa, *temp, *temp2;
    cont_t conta_nodi = 1;

    if (k < num_nodi && testa != NULL)
    {
        while (num_nodi - k != conta_nodi)
        {
            ptr_nodo = ptr_nodo->next;
            conta_nodi++;
        }

        temp = ptr_nodo->next;
        ptr_nodo->next = NULL;
        temp2 = temp;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = testa;
        testa = temp2;
    }
    return testa;
}

node_t *inserisci_elementi(node_t *testa, int *num_nodi)
{
    bool_t esci = False;
    node_t *ptr_nodo;
    int risposta;

    while (esci == False)
    {
        printf("Vuoi inserire un nodo?\n1 SI\n2 NO\n");
        scanf("%d", &risposta);
        if (risposta == 1)
        {
            if (*num_nodi == 0)
            {
                testa = (node_t *)malloc(sizeof(node_t));
                ptr_nodo = testa;
                testa->next = NULL;
                printf("Inserire il valore della testa: ");
                scanf("%d", &testa->valore);
                (*num_nodi)++;
            }
            else
            {
                ptr_nodo->next = (node_t *)malloc(sizeof(node_t));
                printf("Inserire il valore del nodo: ");
                scanf("%d", &ptr_nodo->next->valore);
                ptr_nodo = ptr_nodo->next;
                ptr_nodo->next = NULL;
                (*num_nodi)++;
            }
        }
        else
            esci = True;
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
    node_t *testa = NULL;
    int k, num_nodi = 0;

    printf("Inserire il numero di rotazioni da effettuare a destra: ");
    scanf("%d", &k);

    testa = inserisci_elementi(testa, &num_nodi);
    stampa_lista(testa);
    printf("\n");
    testa = rotazione_destra(testa, k, num_nodi);
    stampa_lista(testa);

    return 0;
}