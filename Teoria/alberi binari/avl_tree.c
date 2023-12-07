#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int value;
    struct tree *left_child;
    struct tree *right_child;
} node_t;

typedef enum
{
    False,
    True
} bool_t;

void printfInOrder(node_t *radice)
{
    if (radice != NULL)
    {
        printfInOrder(radice->left_child);
        printf("%d ", radice);
        printfInOrder(radice->right_child);
    }
}

node_t *LeftRotation(node_t *radice)
{
    node_t *x, *y, *z, *w;

    y = radice;
    x = radice->left_child;
    z = x->left_child;
    w = x->right_child;

    radice = x;
    radice->left_child = z;
    radice->right_child = y;
    y->left_child = w;

    return radice;
}

node_t *RightRotation(node_t *radice)
{
    node_t *x, *y, *z, *w;

    y = radice;
    x = radice->right_child;
    z = x->right_child;
    w = x->left_child;

    radice = x;
    radice->left_child = y;
    radice->right_child = z;
    y->right_child = w;

    return radice;
}

int TreeHeight(node_t *radice)
{
    int altezza, altezza_sx, altezza_dx;

    if (radice == NULL)
        return -1;
    else
    {
        altezza_sx = TreeHeight(radice->left_child);
        altezza_dx = TreeHeight(radice->right_child);
        altezza = (altezza_sx > altezza_dx) ? altezza_sx : altezza_dx;
    }
    return altezza;
}

node_t *IfBalanced(node_t *radice)
{
    int bilance = TreeHeight(radice->left_child) - TreeHeight(radice->right_child);
    if (bilance > 1)
        radice = LeftRotation(radice);
    else if (bilance < -1)
        radice = RightRotation(radice);

    radice = IfBalanced(radice->left_child);
    radice = IfBalanced(radice->right_child);

    return radice;
}

node_t *NewNode(int value)
{
    node_t *nuovo_nodo;

    nuovo_nodo = (node_t *)malloc(sizeof(node_t));
    nuovo_nodo->left_child = NULL;
    nuovo_nodo->right_child = NULL;
    nuovo_nodo->value = value;

    return nuovo_nodo;
}

void InsertNode(node_t *radice, int value)
{
    if (radice == NULL)
        radice = NewNode(value);
    else if (radice->value <= value)
        InsertNode(radice->left_child, value);
    else
        InsertNode(radice->right_child, value);
}

int main()
{
    node_t *radice = NULL;
    bool_t errore;
    int risposta, value;

    errore = True;
    while (errore == True)
    {
        printf("Vuoi inserire un nuovo nodo?\n1 SI\n2 NO\nScelta: ");
        scanf("%d", &risposta);

        if (risposta == 1)
        {
            errore = False;
            printf("Inserire il valore da attribuire al nodo: ");
            scanf("%d", &value);
            InsertNode(radice, value);
            printf("Nodo inserito correttamente\n");
            radice = IfBalanced(radice);
            printf("Albero bilanciato correttamente\n");
        }
        else if (risposta != 2)
            printf("Scelta non valida, riprova\n");
        else
            errore = False;
    }
}