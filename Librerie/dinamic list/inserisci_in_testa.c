#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val, row, col;
    struct nodo *next;
} nodo_t;

nodo_t *InserisciInTesta(nodo_t *testa_precedente, int val, int row, int col)
{
    nodo_t *nuova_testa;

    nuova_testa = (nodo_t *)malloc(sizeof(nodo_t));
    nuova_testa->row = row;
    nuova_testa->col = col;
    nuova_testa->val = val;
    nuova_testa->next = testa_precedente;

    return nuova_testa;
}