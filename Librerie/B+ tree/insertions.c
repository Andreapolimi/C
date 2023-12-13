#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "B+tree.h"

Bplus_node_t *SearchLeafCollocation(Bplus_node_t *radice, int new_key)
{
    int i = 0;
    bool trovato = false;
    Bplus_node_t *node;

    if (!(radice->isleaf))
    {
        for (i = 0; i < radice->cont_keys && trovato == false; i++)
            if (radice->keys[i] > new_key)
            {
                trovato = true;
                node = SearchLeafCollocation(radice->pointer.low_level[i], new_key);
            }
        if (!trovato)
            node = SearchLeafCollocation(radice->pointer.low_level[i], new_key);
    }
    else
        node = radice;

    return node;
}

Bplus_node_t *SearchPointer(Bplus_node_t *radice, Bplus_node_t *node)
{
    int i;
    bool trovato = false;
    Bplus_node_t *next_node;

    for (i = 0; i < radice->cont_keys && trovato == false; i++)
    {
        if (radice->keys[i] > node->keys[0])
            node = SearchPointer(radice->pointer.low_level[i], node);
        else if ()
    }
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

void SimpleAddKey(Bplus_node_t *node, Bplus_node_t *new_node, int next_key_index, int new_key, data_t *new_data)
{
    int i;

    node->cont_keys += 1;
    for (i = node->cont_keys - 1; i > next_key_index; i--)
    {
        node->keys[i] = node->keys[i - 1];
        if (node->isleaf)
            node->pointer.data[i] = node->pointer.data[i - 1];
        else
            node->pointer.low_level[i] = node->pointer.low_level[i - 1];
    }
    node->keys[next_key_index] = new_key;
    if (node->isleaf)
        node->pointer.data[next_key_index] = new_data;
    else
        node->pointer.low_level[i] = new_node;
}

bool Redistribution(Bplus_node_t **radice, Bplus_node_t *node, int new_key, data_t *new_data);

void SplitNode(Bplus_node_t **radice, Bplus_node_t *node, int next_key_index, int new_key, data_t *new_data)
{
    bool inserito;
    int i, j;
    Bplus_node_t *new_node;

    node->cont_keys += 1;
    new_node = (Bplus_node_t *)malloc(sizeof(Bplus_node_t));
    if (node->isleaf)
    {
        new_node->next_leaf = node->next_leaf;
        node->next_leaf = new_node;
        new_node->isleaf = true;
    }
    else
        new_node->isleaf = false;

    node->cont_keys = node->cont_keys / 2;
    new_node->cont_keys = (MAX_KEYS + 1) - node->cont_keys;

    for (i = node->cont_keys, j = new_node->cont_keys - 1; j >= 0; j--)
    {
        if (node->keys[i] > new_key && inserito == false)
        {
            new_node->keys[j] = node->keys[i];
            node->keys[i] = 0;
            if (node->isleaf)
            {
                new_node->pointer.data[j] = node->pointer.data[i];
                node->pointer.data[i] = NULL;
            }
            else
            {
                new_node->pointer.low_level[j] = node->pointer.low_level[i];
                node->pointer.low_level[i] = NULL;
            }
            i--;
        }
        else
        {
            new_node->keys[j] = new_key;
            if (node->isleaf)
                new_node->pointer.data[j] = new_data;
            else
                new_node->pointer.low_level[j] = node;
            inserito = true;
        }
    }
    if (!inserito)
    {
        for (i = node->cont_keys - 1; i > next_key_index; i--)
        {
            node->keys[i] = node->keys[i - 1];
            if (node->isleaf)
                node->pointer.data[i] = node->pointer.data[i - 1];
            else
                node->pointer.low_level[i] = node->pointer.low_level[i - 1];
        }
        node->keys[next_key_index] = new_key;
        if (node->isleaf)
            new_node->pointer.data[j] = new_data;
        else
            new_node->pointer.low_level[j] = node;
    }
    InsertKey(radice, new_node->keys[0], node, new_node, new_data);
}

void InsertKey(Bplus_node_t **radice, int new_key, Bplus_node_t *node, Bplus_node_t *new_node, data_t *new_data)
{
    int i, j, next_key_index;
    bool successo;

    if (node == NULL)
        node = SearchLeafCollocation(*radice, new_key);
    else
        node = SearchPointer(*radice, node);

    next_key_index = SearchNextKeyIndex(node, new_key);

    if (node->cont_keys + 1 < MAX_KEYS)
        SimpleAddKey(node, new_node, next_key_index, new_key, new_data);
    else
    {
        successo = Redistribution(radice, node, new_key, new_data);
        if (!successo)
            SplitNode(radice, node, next_key_index, new_key, new_data);
    }
}