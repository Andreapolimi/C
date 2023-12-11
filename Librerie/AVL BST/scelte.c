#include "tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

tree_t *Inserimento(tree_t *radice)
{
    char key[MAX_CHAR];

    while (strcmp(key, "T") != 0)
    {
        printf("\nInserire il valore da attribuire al nuovo nodo (inserire T se si vuole terminare l'operazione): ");
        scanf("%s", key);
        if (strcmp(key, "T") != 0)
        {
            InsertTree(&radice, key);
            IfBalanced(&radice);
        }
        printf("Inserimento avvenuto con successo\n\n");
    }
    printf("\n\n");
    return radice;
}

tree_t *Modifica(tree_t *radice)
{
    char key1[MAX_CHAR], key2[MAX_CHAR];
    tree_t *parent, *node;
    bool delete = true;

    while (strcmp(key1, "T") != 0)
    {
        printf("\nInserire il valore del nodo da modificare (inserire T se si vuole terminare l'operazione): ");
        scanf("%s", key1);
        printf("Inserire il nuovo valore da attribuire al nodo: ");
        scanf("%s", key2);
        parent = SearchParent(radice, key1);
        node = Search(radice, key1);
        if (parent->left_child == node)
        {
            if (key2 < parent->key && (key2 >= node->left_child->key || node->left_child == NULL) && (key2 < node->right_child->key || node->right_child == NULL))
                delete = false;
            else if (key2 > parent->key && (key2 >= node->left_child->key || node->left_child == NULL) && (key2 < node->right_child->key || node->right_child == NULL))
                delete = false;
        }
        if (delete)
        {
            printf("La modifica della chiave necessità di un bilancio dell'albero\n");
            Delete(&radice, key1);
            IfBalanced(&radice);
            InsertTree(&radice, key2);
            IfBalanced(&radice);
        }
        else
            strcpy(node->key, key2);
        printf("Modifica avvenuta con successo\n\n");
    }
    printf("\n\n");
    return radice;
}

tree_t *Rimozione(tree_t *radice)
{
    char key[MAX_CHAR];

    while (strcmp(key, "T") != 0)
    {
        printf("\nInserire il valore del nodo da eliminare (inserire T se si vuole terminare l'operazione): ");
        scanf("%s", key);
        Delete(&radice, key);
        printf("Rimozione avvenuta con successo\n\n");
    }
    printf("\n\n");
    return radice;
}

void Stampa(tree_t *radice)
{
    char key[MAX_CHAR];
    int azione;
    bool esci = false;

    while (!esci)
    {
        printf("\nChe tipo di stampa vuoi effettuare?\n1 STAMPA NODO\n2 STAMPA ALBERO IN ORDINE\n3 STAMPA ALBERO A LIVELLI\n4 TERMINA: ");
        scanf("%d", &azione);

        if (azione == 1)
        {
            printf("Inserire la chiave del nodo da stampare: ");
            scanf("%s", key);
            printf("%s", (Search(radice, key))->key); // in caso che il nodo abbia più di un solo dato
        }
        else if (azione == 2)
            printfInOrder(radice);
        else if (azione == 3)
            printfLevel(radice);
        else
            esci = true;
    }
    printf("\n\n");
}