#include <stdio.h>

void UnisciInOrdine(int *array3, int *array1, int *array2, int dim1, int dim2)
{
    if (dim1 == 0 && dim2 != 0)
    {
        *array3 = *array2;
        UnisciInOrdine(array3 + 1, array1, array2 + 1, dim1, dim2 - 1);
    }
    else if (dim2 == 0 && dim1 != 0)
    {
        *array3 = *array1;
        UnisciInOrdine(array3 + 1, array1 + 1, array2, dim1 - 1, dim2);
    }

    if (dim1 != 0 && dim2 != 0)
    {
        if (*array1 <= *array2)
        {
            *array3 = *array1;
            UnisciInOrdine(array3 + 1, array1 + 1, array2, dim1 - 1, dim2);
        }
        else if (*array1 > *array2)
        {
            *array3 = *array2;
            UnisciInOrdine(array3 + 1, array1, array2 + 1, dim1, dim2 - 1);
        }
    }
}

int main()
{
    int array1[] = {1, 4, 6, 10};
    int array2[] = {2, 3, 6, 9, 12};
    int array3[9];
    int dim1 = 4, dim2 = 5;

    UnisciInOrdine(array3, array1, array2, dim1, dim2);

    for (int i = 0; i < 9; i++)
        printf("%d ", array3[i]);

    return 0;
}