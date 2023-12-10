#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

tree_t *NewNode(char *key)
{
    tree_t *nuovo_nodo;

    nuovo_nodo = (tree_t *)malloc(sizeof(tree_t));
    nuovo_nodo->left_child = NULL;
    nuovo_nodo->right_child = NULL;
    strcpy(nuovo_nodo->key, key);

    return nuovo_nodo;
}

void InsertTree(tree_t **radice, char *key)
{
    if (*radice == NULL)
        *radice = NewNode(key);
    else if (strcmp((*radice)->key, key) >= 0)
        InsertTree(&((*radice)->left_child), key);
    else
        InsertTree(&((*radice)->right_child), key);
}