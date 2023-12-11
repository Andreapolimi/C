#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void InsertTale(queue_t **tale, tree_t *element)
{
    queue_t *new_tale;
    new_tale = (queue_t *)malloc(sizeof(queue_t));
    new_tale->pointer = element;
    new_tale->next = NULL;
    (*tale)->next = new_tale;
    *tale = (*tale)->next;
}

void RemoveHead(queue_t **head)
{
    queue_t *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void printfLevel(tree_t *radice)
{
    queue_t *head, *tale = NULL;
    if (radice == NULL)
        printf("L'albero è vuoto\n");
    else
    {
        head = (queue_t *)malloc(sizeof(queue_t));
        head->pointer = radice;
        head->next = NULL;
        tale = head;
        while (head != NULL)
        {
            printf("%s\t", head->pointer->key);

            if (head->pointer->left_child != NULL)
                InsertTale(&tale, head->pointer->left_child);
            if (head->pointer->right_child != NULL)
                InsertTale(&tale, head->pointer->right_child);
            RemoveHead(&head);
        }
    }
}

void printfInOrder(tree_t *radice)
{
    if (radice != NULL)
    {
        printfInOrder(radice->left_child);
        printf("%s\t", radice->key);
        printfInOrder(radice->right_child);
    }
}