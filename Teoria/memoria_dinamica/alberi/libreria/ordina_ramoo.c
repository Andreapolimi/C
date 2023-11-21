#include "treelib.h"
#include <stdio.h>

nodo_t *partiziona_ramo(nodo_t *ptr_i, nodo_t *max)
{
    int pivot = max->valore;
    nodo_t *ptr_j = ptr_i->el_successivo;
    nodo_t *temp, temp2;

    while (ptr_j != max)
    {
        if (ptr_j->valore <= pivot && ptr_i->el_successivo != ptr_j)
        {
            temp = ptr_i;
            ptr_i = ptr_i->el_successivo;
            tmp2
        }
    }
}