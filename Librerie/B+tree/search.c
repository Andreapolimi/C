#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "B+tree.h"

Bplus_node_t *SearchLeaf(Bplus_node_t *root, int new_key)
{
    int i = 0;
    bool trovato = false;
    Bplus_node_t *node;

    if (!(root->isleaf))
    {
        for (i = 0; i < root->cont_keys && trovato == false; i++)
            if (root->keys[i] > new_key)
            {
                trovato = true;
                node = SearchLeaf(root->pointer.low_level[i], new_key);
            }
        if (!trovato)
            node = SearchLeaf(root->pointer.low_level[i], new_key);
    }
    else
        node = root;

    return node;
}

Bplus_node_t *SearchPointer(Bplus_node_t *root, Bplus_node_t *node)
{
    int i;
    bool trovato = false;
    Bplus_node_t *parent;

    if (!(root->isleaf))
    {
        for (i = 0; i < root->cont_keys && trovato == false; i++)
        {
            if (root->keys[i] > node->keys[0])
            {
                if (root->pointer.low_level[i] == node)
                {
                    parent = root;
                    trovato = true;
                }
                else
                {
                    parent = SearchPointer(root->pointer.low_level[i], node);
                    trovato = true;
                }
            }
        }
        if (!trovato)
        {
            if (root->pointer.low_level[i] == node)
                parent = root;
        }
        else
            node = SearchPointer(root->pointer.low_level[i], node);
    }
    else
        parent = NULL;
    return parent;
}