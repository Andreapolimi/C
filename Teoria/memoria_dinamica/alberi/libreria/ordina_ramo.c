#include "treelib.h"
#include <stdio.h>

int partiziona(int arr[], int min, int max)
{
    int med = arr[max];
    int i = (min - 1);
    int j;
    int tmp;

    for (j = min; j <= max - 1; j++)
    {
        if (arr[j] < med)
        {
            i++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    tmp = arr[i + 1];
    arr[i + 1] = arr[max];
    arr[max] = tmp;
    return (i + 1);
}

void quick_sort(int arr[], int min, int max)
{
    if (min < max)
    {
        int part = partiziona(arr, min, max);

        quick_sort(arr, min, part - 1);
        quick_sort(arr, part + 1, max);
    }
}

nodo_t *trova_max(nodo_t *posizione)
{
    while (posizione->el_successivo != NULL)
        posizione = posizione->el_successivo;

    return posizione;
}

nodo_t *partiziona_lista(nodo_t *posizionei, nodo_t *last_node)
{
    int pivot = last_node->valore;
    nodo_t *posizionej = posizionei->el_successivo;
    nodo_t *temp, *temp2;
    bool_t esci = False;

    while (esci == False)
    {
        if (posizionej->valore < pivot)
        {
            temp2 = posizionei;
            posizionei = posizionei->el_successivo;
            temp2->el_successivo = posizionei->el_successivo;

            temp = posizionej->el_successivo;
            posizionej->el_successivo = posizionei;
            posizionei->el_successivo = temp;
        }
        if (posizionej->el_successivo == last_node)
            esci = True;
        else
            posizionej = posizionej->el_successivo;
    }
    temp2 = posizionei;
    posizionei = posizionei->el_successivo;
    temp2->el_successivo = posizionei->el_successivo;

    temp = last_node->el_successivo;
    last_node->el_successivo = posizionei;
    posizionei->el_successivo = temp;

    return temp2;
}

void quicksort_lista(nodo_t *el1, nodo_t *last_el)
{
    if (el1->valore < last_el->valore)
    {
        nodo_t *part = partiziona_lista(el1, last_el);

        quicksort_lista(el1, part);
        quicksort_lista(part->el_successivo->el_successivo, last_el);
    }
}