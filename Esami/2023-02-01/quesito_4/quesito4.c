#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valore;
    struct node *next;
} node_t;
typedef int cont_t;

int rotazione_destra(node_t **testa, int k)
{
    node_t *ptr_nodo = *testa, *scorri = *testa, *temp, *temp2;
    cont_t conta_nodi = 0;

    while (scorri->next != NULL)
    {
        scorri = scorri->next;
        conta_nodi++;
        if (conta_nodi > k)
            ptr_nodo = ptr_nodo->next;
    }
    if (conta_nodi < k)
        return -1;
    else if (conta_nodi == k)
        return 1;
    else
    {
        temp = ptr_nodo->next;
        ptr_nodo->next = NULL;
        temp2 = temp;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = *testa;
        *testa = temp2;
    }

    return 0;
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
    node_t *testa = NULL;
    int k, riscontro_funzione;

    testa = inserisci_elementi(testa);

    printf("Inserire il numero di rotazioni da effettuare a destra: ");
    scanf("%d", &k);

    stampa_lista(testa);
    printf("\n");

    riscontro_funzione = rotazione_destra(&testa, k);
    if (riscontro_funzione == -1)
        printf("Errore, non si possono effettuare le %d rotazioni sulla lista\n", k);
    else if (riscontro_funzione == 1)
        printf("La lista non è stata modificata, numero di rotazioni pari al numero di nodi\n");
    else
        printf("Lista ruotata\n");

    stampa_lista(testa);

    return 0;
}