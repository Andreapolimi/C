#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4
#define R 2
#define C 2

void IndividuaSottoMatrice(int mat[][M], int subamat[][C], int *i, int *j)
{
    int esci, k, s, h, t, x, y, trovato = 0;

    for (k = 0; k <= N - R && trovato == 0; k++)
    {
        for (s = 0; s <= M - C && trovato == 0; s++)
        {
            esci = 0;
            for (h = k, x = 0; h < k + R && esci == 0; h++, x++)
            {
                for (t = s, y = 0; t < s + C; t++, y++)
                {
                    if (mat[h][t] != subamat[x][y])
                        esci = 1;
                }
            }
            if (esci == 0)
            {
                *i = k;
                *j = s;
                trovato = 1;
            }
        }
    }
}

int main()
{
    int mat[N][M] = {{-7, 7 - 4, -34}, {-3, 9, -2, 18}, {-15, -5, 3, 29}}, subamat[R][C] = {{9, -2}, {-5, 3}}, i = -1, j = -1;

    IndividuaSottoMatrice(mat, subamat, &i, &j);
    printf("%d %d", i, j);

    return 0;
}