#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **matrice, righe, colonne;
    int i, j;

    printf("Inserire il numero di righe della matrice: ");
    scanf("%d", &righe);
    printf("Inserire il numero di colonne della matrice: ");
    scanf("%d", &colonne);

    matrice = (int **)calloc(righe, righe * sizeof(int *));

    for (i = 0; i < righe; ++i)
    {
        int *p;

        p = (int *)calloc(colonne, colonne * sizeof(int));

        matrice[i] = p;
    }

    for (i = 0; i < righe; ++i)
    {
        for (j = 0; j < colonne; ++j)
        {
            matrice[i][j] = i * 10 + j;
        }
    }

    printf("Contenuto dell'matrice:\n");
    for (i = 0; i < righe; ++i)
    {
        for (j = 0; j < colonne; ++j)
        {
            printf("%02d\t", matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}