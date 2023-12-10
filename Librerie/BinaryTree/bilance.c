#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree_t *LeftRotation(tree_t *radice)
{
    tree_t *x, *y, *z, *w;

    y = radice;
    x = radice->left_child;
    z = x->left_child;
    w = x->right_child;

    radice = x;
    radice->left_child = z;
    radice->right_child = y;
    y->left_child = w;

    return radice;
}

tree_t *RightRotation(tree_t *radice)
{
    tree_t *x, *y, *z, *w;

    y = radice;
    x = radice->right_child;
    z = x->right_child;
    w = x->left_child;

    radice = x;
    radice->left_child = y;
    radice->right_child = z;
    y->right_child = w;

    return radice;
}

int TreeHeight(tree_t *radice)
{
    int altezza, altezza_sx, altezza_dx;

    if (radice == NULL)
        return -1;
    else
    {
        altezza_sx = TreeHeight(radice->left_child);
        altezza_dx = TreeHeight(radice->right_child);
        altezza = (altezza_sx > altezza_dx) ? altezza_sx : altezza_dx;
        altezza++;
    }
    return altezza;
}

void IfBalanced(tree_t **radice)
{
    int bilance;

    if ((*radice)->left_child != NULL)
        IfBalanced(&((*radice)->left_child));
    if ((*radice)->right_child != NULL)
        IfBalanced(&((*radice)->right_child));

    bilance = TreeHeight((*radice)->left_child) - TreeHeight((*radice)->right_child);
    if (bilance > 1)
    {
        if (TreeHeight((*radice)->left_child->left_child) >= TreeHeight((*radice)->left_child->right_child))
            *radice = LeftRotation(*radice);
        else
        {
            (*radice)->left_child = RightRotation((*radice)->left_child);
            *radice = LeftRotation(*radice);
        }
    }
    else if (bilance < -1)
    {
        if (TreeHeight((*radice)->right_child->right_child) >= TreeHeight((*radice)->right_child->left_child))
            *radice = RightRotation(*radice);
        else
        {
            (*radice)->right_child = LeftRotation((*radice)->right_child);
            *radice = RightRotation(*radice);
        }
    }
}