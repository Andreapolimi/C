#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

tree_t *Search(tree_t *radice, char *key)
{
    if (radice == NULL)
    {
        printf("Elemento cercato inesistente\n");
        return NULL;
    }
    else
    {
        if (strcmp(radice->key, key) == 0)
            return radice;
        else if (strcmp(radice->key, key) > 0)
        {
            radice = Search(radice->left_child, key);
            return radice;
        }
        else
        {
            radice = Search(radice->right_child, key);
            return radice;
        }
    }
}

tree_t *SearchParent(tree_t *radice, char *key)
{
    if (radice == NULL)
    {
        printf("La radice non ha parenti\n");
        return NULL;
    }
    else
    {
        if (strcmp(radice->left_child->key, key) == 0 || strcmp(radice->right_child->key, key) == 0)
            return radice;
        else if (strcmp(radice->key, key) > 0)
            return SearchParent(radice->left_child, key);
        else
            return SearchParent(radice->right_child, key);
    }
}

tree_t *FindMin(tree_t *radice)
{
    tree_t *min;
    if (radice->left_child != NULL)
    {
        min = FindMin(radice->left_child);
        return min;
    }
    else
        return radice;
}

tree_t *FindMax(tree_t *radice)
{
    tree_t *max;
    if (radice->right_child != NULL)
    {
        max = FindMin(radice->right_child);
        return max;
    }
    else
        return radice;
}

tree_t *InOrderSuccessor(tree_t *radice, char *key)
{
    if (strcmp(radice->key, key) == 0)
        return FindMin(radice->right_child);
    else if (strcmp(radice->left_child->key, key) == 0)
        if (radice->left_child->right_child != NULL)
            return FindMin(radice->left_child->right_child);
        else
            return radice;
    else if (strcmp(radice->key, key) >= 0)
        return InOrderSuccessor(radice->left_child, key);
    else
        return InOrderSuccessor(radice->right_child, key);
}

tree_t *InOrderPredecessor(tree_t *radice, char *key)
{
    if (strcmp(radice->key, key) == 0)
        return FindMax(radice->left_child);
    else if (strcmp(radice->right_child->key, key) == 0)
        if (radice->right_child->left_child != NULL)
            return FindMax(radice->right_child->left_child);
        else
            return radice;
    else if (strcmp(radice->key, key) >= 0)
        return InOrderPredecessor(radice->left_child, key);
    else
        return InOrderPredecessor(radice->right_child, key);
}