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