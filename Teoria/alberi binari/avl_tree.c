#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    False,
    True
} bool_t;

typedef struct tree
{
    int value;
    struct tree *left_child;
    struct tree *right_child;
} nodeTree_t;

typedef struct queue
{
    nodeTree_t *pointer;
    struct queue *next;
} nodeQueue_t;

nodeQueue_t *InsertTale(nodeTree_t *element)
{
    nodeQueue_t *new_tale;
    new_tale = (nodeQueue_t *)malloc(sizeof(nodeQueue_t));
    new_tale->pointer = element;
    new_tale->next = NULL;
    return new_tale;
}

void printfLevel(nodeTree_t *radice)
{
    nodeQueue_t *head, *tale = NULL, *temp;

    if (radice != NULL)
    {
        head = (nodeQueue_t *)malloc(sizeof(nodeQueue_t));
        head->pointer = radice;
        head->next = NULL;

        while (head != NULL)
        {
            printf("%d\t", head->pointer->value);

            if (head->pointer->left_child != NULL)
            {
                if (tale == NULL)
                    tale = InsertTale(head->pointer->left_child);
                else
                {
                    tale->next = InsertTale(head->pointer->left_child);
                    tale = tale->next;
                }
                if (head->next == NULL)
                    head->next = tale;
            }
            if (head->pointer->right_child != NULL)
            {
                if (tale == NULL)
                    tale = InsertTale(head->pointer->right_child);
                else
                {
                    tale->next = InsertTale(head->pointer->right_child);
                    tale = tale->next;
                }
                if (head->next == NULL)
                    head->next = tale;
            }

            temp = head;
            head = head->next;
            free(temp);
        }
    }
}

void printfInOrder(nodeTree_t *radice)
{
    if (radice != NULL)
    {
        printfInOrder(radice->left_child);
        printf("%d\t", radice->value);
        printfInOrder(radice->right_child);
    }
}

nodeTree_t *LeftRotation(nodeTree_t *radice)
{
    nodeTree_t *x, *y, *z, *w;

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

nodeTree_t *RightRotation(nodeTree_t *radice)
{
    nodeTree_t *x, *y, *z, *w;

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

int TreeHeight(nodeTree_t *radice)
{
    int altezza, altezza_sx, altezza_dx;

    if (radice == NULL)
        return -1;
    else
    {
        altezza_sx = TreeHeight(radice->left_child);
        altezza_dx = TreeHeight(radice->right_child);
        altezza = (altezza_sx > altezza_dx) ? altezza_sx : altezza_dx;
        altezza++;
    }
    return altezza;
}

nodeTree_t *IfBalanced(nodeTree_t *radice)
{
    if (radice->left_child != NULL)
        radice->left_child = IfBalanced(radice->left_child);
    if (radice->right_child != NULL)
        radice->right_child = IfBalanced(radice->right_child);

    int bilance = TreeHeight(radice->left_child) - TreeHeight(radice->right_child);
    if (bilance > 1)
    {
        if (TreeHeight(radice->left_child->left_child) >= TreeHeight(radice->left_child->right_child))
            radice = LeftRotation(radice);
        else
        {
            radice->left_child = RightRotation(radice->left_child);
            radice = LeftRotation(radice);
        }
    }
    else if (bilance < -1)
    {
        if (TreeHeight(radice->right_child->right_child) >= TreeHeight(radice->right_child->left_child))
            radice = RightRotation(radice);
        else
        {
            radice->right_child = LeftRotation(radice->right_child);
            radice = RightRotation(radice);
        }
    }

    return radice;
}

nodeTree_t *NewNode(int value)
{
    nodeTree_t *nuovo_nodo;

    nuovo_nodo = (nodeTree_t *)malloc(sizeof(nodeTree_t));
    nuovo_nodo->left_child = NULL;
    nuovo_nodo->right_child = NULL;
    nuovo_nodo->value = value;

    return nuovo_nodo;
}

nodeTree_t *InsertTree(nodeTree_t *radice, int value)
{
    if (radice == NULL)
        radice = NewNode(value);
    else if (radice->value >= value)
        radice->left_child = InsertTree(radice->left_child, value);
    else
        radice->right_child = InsertTree(radice->right_child, value);

    return radice;
}

int main()
{
    nodeTree_t *radice = NULL;
    bool_t errore;
    int risposta, value = 0;

    while (value != -1)
    {
        printf("Inserire il valore da attribuire al nuovo nodo (inserire '-1' se si vuole terminare l'operazione): ");
        scanf("%d", &value);
        if (value != -1)
        {
            radice = InsertTree(radice, value);
            radice = IfBalanced(radice);
        }
    }

    printf("\n\nStampa in ordine:\n");
    printfInOrder(radice);

    printf("\n\nStampa a livelli:\n");
    printfLevel(radice);

    return 0;
}