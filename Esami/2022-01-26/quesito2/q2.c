#include <stdio.h>
#include <stdlib.h>

#define N 7

int SegnoDominante(int *array, int dim)
{
    int sgn = 0;
    if (dim != 0)
    {
        if (*array >= 0)
            sgn++;
        else
            sgn--;
        sgn += SegnoDominante(array + 1, dim - 1);
    }

    if (dim == N - 1)
        return sgn / (abs(sgn));
    else
        return sgn;
}

int main()
{
    int array[7] = {1, 2, -2, 5, 3, 8, 0};

    printf("%d", SegnoDominante(array, N - 1));

    return 0;
}