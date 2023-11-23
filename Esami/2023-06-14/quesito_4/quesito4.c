#include <stdio.h>
#include <stdlib.h>

typedef int cont_t;
typedef enum bool
{
    False,
    True
} bool_t;

bool_t VerificaCondizione(int **mat, int n, int m)
{
    bool_t verifica;
    int indici_massimi[n];
    cont_t i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (j == 0)
                indici_massimi[i] = j;
            else if (mat[i][j] > mat[i][indici_massimi[i]])
                indici_massimi[i] = j;
        }
    }

    for (i = 1; i < n && verifica == True; i++)
        if (indici_massimi[i - 1] >= indici_massimi[i])
            verifica = False;

    return verifica;
}

int main()
{
    int **mat;
    int m, n;
    cont_t i, j;
    bool_t verifica;

    printf("Inserire la dimensione della riga e della colonna tali per cui N<M (ricorda, le dimensioni non possono essere <=0):\n");
    scanf("%d", &n);
    scanf("%d", &m);
    while (n >= m || n <= 0 || m <= 0)
    {
        printf("Inserimento non valido, rispettare i criteri\n");
        printf("Inserire la dimensione della riga e della colonna tali per cui N<M:\n");
        scanf("%d", &n);
        scanf("%d", &m);
    }
    mat = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++)
        {
            printf("Inserire il valore della cella %d-%d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    verifica = VerificaCondizione(mat, n, m);
    printf("%d", verifica);

    return 0;
}