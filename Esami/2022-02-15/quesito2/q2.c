#include <stdio.h>
#include <stdlib.h>

int VerificaSomma(int mat[][3], int val, int col, int row)
{
    int i, somma = 0;

    if (row >= 0)
    {
        for (i = 0; i < col; i++)
            somma += mat[row][i];
        if (somma == val)
            return VerificaSomma(mat + 1, val, col, row - 1);
        else
            return 0;
    }
    else
        return 1;
}

int main()
{
    int mat[3][3] = {{1, 2, 3}, {3, 2, 1}, {3, 0, 3}};

    printf("%d", VerificaSomma(mat, 6, 3, 2));
    return 0;
}