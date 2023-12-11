#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

void Delete(tree_t **radice, char *key)
{
    tree_t *temp, *temp_left, *temp_right, *max, *parent_max;

    if (*radice != NULL)
    {
        if (strcmp((*radice)->key, key) == 0)
        {
            if ((*radice)->left_child == NULL && (*radice)->right_child == NULL)
                *radice = NULL;
            else if ((*radice)->left_child == NULL)
            {
                temp = *radice;
                *radice = (*radice)->right_child;
                free(temp);
            }
            else if ((*radice)->right_child == NULL)
            {
                temp = *radice;
                *radice = (*radice)->left_child;
                free(temp);
            }
            else
            {
                max = FindMax((*radice)->left_child);
                parent_max = SearchParent(*radice, temp->key);
                parent_max->right_child = temp->left_child;

                temp = *radice;
                temp_left = (*radice)->left_child;
                temp_right = (*radice)->right_child;

                *radice = max;
                (*radice)->left_child = temp_left;
                (*radice)->right_child = temp_right;
                free(temp);
            }
        }
        else if (strcmp((*radice)->key, key) >= 0)
            Delete(&((*radice)->left_child), key);
        else
            Delete(&((*radice)->right_child), key);
    }
}