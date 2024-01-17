#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 3
#define N 5
#define MAX_CHAR 50

int **Decodifica(char *nome_file)
{
    FILE *ptr_file;
    int i, j, val, freq, col_rimaste = N, **mat;

    mat = (int **)malloc(M * sizeof(int *));
    for (i = 0; i < M; i++)
        mat[i] = (int *)malloc(N * sizeof(int));

    ptr_file = fopen(nome_file, "r");

    i = 0;
    j = 0;
    while (!feof(ptr_file))
    {
        fscanf(ptr_file, "%d %d ", &val, &freq);
        while (freq != 0)
        {
            while (col_rimaste != 0 && freq != 0)
            {
                mat[i][j] = val;
                freq--;
                col_rimaste--;
                j++;
            }
            if (col_rimaste == 0)
            {
                i++;
                col_rimaste = N;
                j = 0;
            }
        }
    }
    fclose(ptr_file);
    return mat;
}

void Codifica(int mat[][N], char *nome_file)
{
    FILE *ptr_file = fopen(nome_file, "w");
    int i, j, val, freq;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == 0 && j == 0)
            {
                val = mat[i][j];
                freq = 1;
            }
            else if (val == mat[i][j])
                freq++;
            else
            {
                fprintf(ptr_file, "%d %d ", val, freq);
                val = mat[i][j];
                freq = 1;
            }
        }
    }
    fprintf(ptr_file, "%d %d ", val, freq);
    fclose(ptr_file);
}

int main(int argc, char *argv[])
{
    int i, j, mat[M][N], **mat2;
    char nome_file[MAX_CHAR];

    if (strcmp(argv[1], "codifica") == 0)
    {
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("Inserire il valore della cella %d-%d: ", i, j);
                scanf("%d", &mat[i][j]);
            }
        }
        printf("Inserire il nome del file in cui salvare la codifica: ");
        scanf("%s", nome_file);
        Codifica(mat, nome_file);
    }
    else
    {
        printf("Inserire il nome del file da decodificare: ");
        scanf("%s", nome_file);
        mat2 = Decodifica(nome_file);
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
                printf("%d ", mat2[i][j]);

            printf("\n");
        }
    }

    return 0;
}