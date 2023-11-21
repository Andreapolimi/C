#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_MAX 50

typedef struct node
{
    int carattere;
    struct node *next;
} node_t;
typedef enum bool
{
    False,
    True
} bool_t;
typedef int cont_t;

void ModificaLista(node_t *ptr_node, char *stringa)
{
    cont_t i;
    node_t *nuovo_nodo;

    ptr_node->carattere = stringa[0];

    for (i = 1; i < strlen(stringa); i++)
    {
        nuovo_nodo = (node_t *)malloc(sizeof(node_t));
        nuovo_nodo->carattere = stringa[i];
        nuovo_nodo->next = NULL;
        ptr_node->next = nuovo_nodo;
        ptr_node = ptr_node->next;
    }
}

void ComprimiLista(node_t *ptr_node)
{
    int conta_consecutivi = 1;
    node_t *temp;

    while (ptr_node != NULL)
    {
        if (ptr_node->next != NULL)
        {
            if (ptr_node->carattere == ptr_node->next->carattere)
            {
                conta_consecutivi++;
                temp = ptr_node->next;
                ptr_node->next = ptr_node->next->next;
                free(temp);
            }
            else
            {
                temp = ptr_node->next;
                ptr_node->next = (node_t *)malloc(sizeof(node_t));
                ptr_node = ptr_node->next;

                ptr_node->carattere = conta_consecutivi;
                ptr_node->next = temp;
                ptr_node = ptr_node->next;
                conta_consecutivi = 1;
            }
        }
        else
        {
            temp = ptr_node->next;
            ptr_node->next = (node_t *)malloc(sizeof(node_t));
            ptr_node = ptr_node->next;

            ptr_node->carattere = conta_consecutivi;
            ptr_node->next = temp;
            ptr_node = ptr_node->next;
            conta_consecutivi = 1;
        }
    }
}

void StampaLista(node_t *ptr_node)
{
    while (ptr_node != NULL)
    {
        printf("%c", ptr_node->carattere);
        ptr_node = ptr_node->next;
        if (ptr_node->carattere != 1)
            printf("%d", ptr_node->carattere);
        ptr_node = ptr_node->next;
    }
}

int main()
{
    node_t *testa;
    char stringa[DIM_MAX];

    testa = (node_t *)malloc(sizeof(node_t));
    printf("Inserire la stringa da convertire in lista: ");
    scanf("%s", stringa);

    ModificaLista(testa, stringa);

    ComprimiLista(testa);

    StampaLista(testa);

    return 0;
}