#include <stdio.h>
#include <stdlib.h>

#define DIM 8

int conta_occorenze(int *array, int x, int y, int conta, int chiamate)
{
    if (DIM != chiamate)
    {
        if (*array == x && *(array + 1) == y)
            if (conta == -1)
                conta = 1;
            else
                conta++;
        else if (*array == x && conta == -1)
            conta = 0;

        conta = conta_occorenze(array + 1, x, y, conta, chiamate + 1);
    }

    return conta;
}

int main()
{
    int array[DIM] = {5, 3, 2, 5, 3, 5, 3, 3};

    int conta = conta_occorenze(array, 5, 4, -1, 0);

    printf("%d", conta);

    return 0;
}