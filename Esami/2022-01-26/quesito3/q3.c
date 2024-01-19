#include <stdio.h>
#include <stdlib.h>

#define N 7

int *Partiziona(int *array)
{
    int i, j = -1, k = 0, flag = 1, somma = 0, part1 = 0, part2 = 0, *partizione = NULL;

    for (i = 0; i < N; i++)
        somma += array[i];

    if (somma % 2 == 0)
    {
        for (i = 0; i < N && flag; i++)
        {
            if (part1 < somma / 2)
                part1 += array[i];
            else if (part1 == somma / 2 && j == -1)
            {
                j = i;
                part2 += array[i];
                k++;
            }
            else if (j != -1)
            {
                part2 += array[i];
                k++;
            }
            else
                flag = 0;
        }
        if (part1 == part2)
        {
            partizione = (int *)malloc(k * sizeof(int));
            for (i = j, k = 0; i < N; i++, k++)
                partizione[k] = array[i];
        }
    }
    if (partizione != NULL)
        for (int i = 0; i < N - j; i++)
            printf("%d\t", partizione[i]);
    return partizione;
}

int main()
{
    int array[N] = {1, 2, 3, 4, 5, 5, 0}, *partizione;

    partizione = Partiziona(array);
    return 0;
}