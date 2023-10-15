/* Esercizio 6 - Triangolo di Tartaglia

Scrivete un programa che mostri a video il triangolo di Tartaglia per una dimensione chiesta all'utente.

Esempio:
Inserisci dimensione triangolo: 5
1
11
121
1331
14641 */

#include <stdio.h>
#include <stdlib.h>

typedef int contatori;

int main()
{
    int dim, **matrice;
    contatori i, j;

    printf("Inserire la dimensione del triangolo: ");
    scanf("%d", &dim);

    while (dim < 0)
    {
        printf("La dimensione deve essere necessariamente positiva, riprova\n");
        printf("Inserire la dimensione del triangolo: ");
        scanf("%d", &dim);
    }

    matrice = (int **)calloc(dim, dim * sizeof(int *));

    for (i = 0; i <= dim; i++)
    {
        int *p;
        p = (int *)calloc(dim, dim * sizeof(int));

        matrice[i] = p;
        matrice[i][0] = 1;
    }

    for (i = 0; i <= dim; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == 0)
                printf("%d ", matrice[i][j]);
            else
            {
                matrice[i][j] = matrice[i - 1][j] + matrice[i - 1][j - 1];
                printf("%d ", matrice[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}