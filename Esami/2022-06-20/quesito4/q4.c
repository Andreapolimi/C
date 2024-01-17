#include <stdio.h>
#include <stdlib.h>

#define DIM 5

void Scrivi_picchi(int mat[][DIM], FILE *ptr_file)
{
    int i, j, k, s, conta_supera;

    for (i = 1; i < DIM - 1; i++)
    {
        for (j = 1; j < DIM - 1; j++)
        {
            conta_supera = 0;
            for (k = i - 1; k < i + 2; k++)
            {
                for (s = j - 1; s < j + 2; s++)
                {
                    if (mat[i][j] >= mat[k][s] + 10)
                        conta_supera++;
                }
            }
            if (conta_supera == 8)
                fprintf(ptr_file, "%d %d\n", i, j);
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *ptr_file;
    int mat[DIM][DIM], i, j;

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("Inserire l'elemento della cella %d-%d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    ptr_file = fopen(argv[1], "w");
    Scrivi_picchi(mat, ptr_file);

    return 0;
}