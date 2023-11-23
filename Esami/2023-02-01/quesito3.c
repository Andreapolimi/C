#include <stdio.h>

#define N 4
#define M 5
#define MAX_MINRC 4

typedef int cont_t;
typedef enum
{
    False,
    True
} bool_t;
typedef struct minimoRC
{
    int indici_righe[MAX_MINRC], indici_col[MAX_MINRC];
    int valori_minimi[MAX_MINRC];
    int num_minimiRC;
} minimiRC_t;

void minimoRC(int mat[N][M], minimiRC_t *minimi)
{
    cont_t i, j, k, h;
    bool_t esci;

    h = 0;
    minimi->num_minimiRC = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            esci = False;
            for (k = 0; k < N && esci == False; k++)
                if (k != i)
                    if (mat[i][j] >= mat[k][j])
                        esci = True;

            for (k = 0; k < M && esci == False; k++)
                if (k != j)
                    if (mat[i][j] >= mat[i][k])
                        esci = True;

            if (esci == False)
            {
                minimi->num_minimiRC++;
                minimi->indici_righe[h] = i;
                minimi->indici_col[h] = j;
                minimi->valori_minimi[h] = mat[i][j];
                h++;
            }
        }
    }
}

int main()
{
    cont_t i;
    minimiRC_t minimi;

    int mat[N][M] = {{3, 5, 6, 7, 8}, {10, 2, 1, 0, 4}, {2, 4, 8, 3, 9}, {12, 15, 3, 7, 9}};

    minimoRC(mat, &minimi);
    for (i = 0; i < minimi.num_minimiRC; i++)
        printf("%d e' il minimo della riga %d e col %d\n", minimi.valori_minimi[i], minimi.indici_righe[i], minimi.indici_col[i]);

    return 0;
}