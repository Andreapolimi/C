#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "B+tree.h"

Bplus_node_t *SearchLeafCollocation(Bplus_node_t *root, int new_key)
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
                node = SearchLeafCollocation(root->pointer.low_level[i], new_key);
            }
        if (!trovato)
            node = SearchLeafCollocation(root->pointer.low_level[i], new_key);
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
        for (i = 0; i <= root->cont_keys && trovato == false; i++)
        {
            if (root->keys[i] > node->keys[0])
            {
                if (root->pointer.low_level[i] == node)
                {
                    parent = root;
                    trovato = true;
                }
                else
                    node = SearchPointer(root->pointer.low_level[i], node);
            }
        }
        if (!trovato)
            node = SearchPointer(root->pointer.low_level[i], node);
    }
    else
        parent = NULL;

    return parent;
}

Bplus_node_t *NewRoot(Bplus_node_t *root, Bplus_node_t *node, int new_key)
{
    Bplus_node_t *new_root;
    int i;

    new_root = (Bplus_node_t *)malloc(sizeof(Bplus_node_t));
    new_root->isleaf = false;
    new_root->cont_keys = 1;
    new_root->pointer.low_level[0] = root;
    new_root->pointer.low_level[1] = node;
    new_root->keys[0] = new_key;

    return new_root;
}

int SearchNextKeyIndex(Bplus_node_t *node, int new_key)
{
    int next_key_index;
    bool trovato = false;
    int i;

    for (i = 0; i < node->cont_keys && trovato == false; i++)
        if (node->keys[i] > new_key)
        {
            trovato = true;
            next_key_index = i;
        }
    if (!trovato)
        next_key_index = node->cont_keys;

    return next_key_index;
}

void MoveToRight(Bplus_node_t *node, Bplus_node_t *new_node, Bplus_node_t *pointer_new_node, int next_key_index, data_t *new_data, int new_key)
{
    int i, j;
    bool inserita = false;

    for (i = MAX_KEYS - 1, j = new_node->cont_keys; j >= 0; j--)
    {
        if (node->keys[i] > new_key && inserita == false)
        {
            new_node->keys[j] = node->keys[i];
            node->keys[i] = 0;
            i--;
            if (node->isleaf)
            {
                new_node->pointer.data[j] = node->pointer.data[i];
                node->pointer.data[i] = NULL;
            }
            else
            {
                new_node->pointer.low_level[j + 1] = node->pointer.low_level[i + 1];
                node->pointer.low_level[i + 1] = NULL;
            }
        }
        else
        {
            inserita = true;
            new_node->keys[j] = new_key;
            if (node->isleaf)
                new_node->pointer.data[j] = new_data;
            else
                new_node->pointer.low_level[j + 1] = pointer_new_node;
        }
    }

    if (!inserita)
    {
        for (i = node->cont_keys - 1; i > next_key_index; i--)
        {
            node->keys[i] = node->keys[i - 1];
            if (node->isleaf)
                node->pointer.data[i] = node->pointer.data[i - 1];
            else
                node->pointer.low_level[i] = node->pointer.low_level[i - 1];
        }
        node->keys[i] = new_key;
        if (node->isleaf)
            node->pointer.data[i] = new_data;
        else
            node->pointer.low_level[i] = pointer_new_node;
    }
}

void SimpleAddKey(Bplus_node_t *node, Bplus_node_t *pointer_new_node, int next_key_index, data_t *new_data, int new_key)
{
    int i;

    node->cont_keys++;

    for (i = node->cont_keys - 1; i > next_key_index; i--)
    {
        node->keys[i] = node->keys[i - 1];
        if (node->isleaf)
            node->pointer.data[i] = node->pointer.data[i - 1];
        else
            node->pointer.low_level[i] = node->pointer.low_level[i - 1];
    }
    node->keys[i] = new_key;
    if (node->isleaf)
        node->pointer.data[i] = new_data;
    else
        node->pointer.low_level[i + 1] = pointer_new_node;
}

bool Redistribution(Bplus_node_t *root, Bplus_node_t *node, int new_key, data_t *new_data);

void SplitNode(Bplus_node_t *root, Bplus_node_t *node, Bplus_node_t *pointer_new_node, int next_key_index, int new_key, data_t *new_data)
{
    int first_key, i;
    Bplus_node_t *new_node;

    node->cont_keys = (node->cont_keys + 1) / 2;
    new_node = (Bplus_node_t *)calloc(1, sizeof(Bplus_node_t));
    new_node->cont_keys = MAX_KEYS - node->cont_keys;
    if (new_node->isleaf)
    {
        new_node->isleaf = true;
        new_node->next_leaf = node->next_leaf;
        node->next_leaf = new_node;
    }
    else
        new_node->isleaf = false;

    MoveToRight(node, new_node, pointer_new_node, next_key_index, new_data, new_key);

    first_key = new_node->keys[0];
    if (!(node->isleaf))
    {
        for (i = 0; i < new_node->cont_keys; i++)
        {
            new_node->keys[i] = node->keys[i + 1];
            new_node->pointer.low_level[i] = new_node->pointer.low_level[i + 1];
        }
    }
    InsertKey(&root, new_data, first_key, node, new_node);
}

void InsertKey(Bplus_node_t **root, data_t *new_data, int new_key, Bplus_node_t *node, Bplus_node_t *pointer_new_node)
{
    int next_key_index;
    bool successo = false;

    if (node == NULL)
        node = SearchLeafCollocation(*root, new_key);
    else
    {
        node = SearchPointer(*root, node);
        if (node == NULL)
            *root = NewRoot(*root, pointer_new_node, new_key);
        else
        {
            next_key_index = SearchNextKeyIndex(node, new_key);

            if (node->cont_keys + 1 <= MAX_KEYS)
                SimpleAddKey(node, pointer_new_node, next_key_index, new_data, new_key);
            else
            {
                // successo = Redistribution(root, node, new_key, new_data);
                if (!successo)
                    SplitNode(*root, node, pointer_new_node, next_key_index, new_key, new_data);
            }
        }
    }
}