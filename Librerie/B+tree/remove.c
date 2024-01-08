#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "B+tree.h"

Bplus_node_t *ChangeRoot(Bplus_node_t *root)
{
}

int SearchIndexKey(Bplus_node_t *node, int new_key)
{
    int index_element = -1;
    bool trovato = false;
    int i;

    for (i = 0; i < node->cont_keys && trovato == false; i++)
        if (node->keys[i] == new_key)
        {
            trovato = true;
            index_element = i;
        }

    return index_element;
}

void SimpleRemoveKey(Bplus_node_t *node, int index_element)
{
    int i;

    node->cont_keys--;

    for (i = index_element; i < node->cont_keys; i++)
    {
        node->keys[i] = node->keys[i + 1];
        if (node->isleaf)
            node->pointer.data[i] = node->pointer.data[i + 1];
        else
            node->pointer.low_level[i + 1] = node->pointer.low_level[i + 2];
    }
    node->keys[i] = 0;
    if (node->isleaf)
        node->pointer.data[i] = NULL;
    else
        node->pointer.low_level[i + 1] = NULL;
}

void Remove(Bplus_node_t **root, int key, Bplus_node_t *node)
{
    Bplus_node_t *node, *parent;
    int index_element;

    if (node == NULL)
        node = SearchLeaf(*root, key);
    else
        node = SearchPointer(*root, node);
    index_element = SearchIndexKey(node, key);

    if (node->cont_keys != 1)
    {
        SimpleRemoveKey(node, index_element);
        if (index_element == 0)
        {
            parent = SearchPointer(*root, node);
            if (parent->pointer.low_level[0] == node)
            {
                index_element = SearchIndexKey(parent, key);
                parent->keys[index_element] = node->keys[0];
            }
        }
    }
    else
    {
        Remove(&(*root), key, node);
        if (node == *root)
            *root = (*root)->pointer.low_level[0];
        free(node);
    }
}