#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "B+tree.h"

void InsertTale(queue_t **tale, Bplus_node_t *element)
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

void printfLevel(Bplus_node_t *radice)
{
    queue_t *head, *tale = NULL;
    int i;

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
            for (i = 0; i < head->pointer->cont_keys; i++)
                printf("%d\t", head->pointer->keys[i]);
            printf("\n");

            if (!(head->pointer->isleaf))
                for (i = 0; i < head->pointer->cont_keys + 1; i++)
                    InsertTale(&tale, head->pointer->pointer.low_level[i]);
            RemoveHead(&head);
        }
    }
}