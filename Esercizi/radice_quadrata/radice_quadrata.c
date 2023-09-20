#include <stdio.h>

int main(void)
{
    int x, y = 1, c = 1;

    printf("Inserisci il numero di cui vuoi calcolare la radice quadrata: ");
    scanf("%d", &x);

    do
    {
        if ((y * y) > x)
        {
            y -= 1;
            c = 0;
        }
        else
            y += 1;
    } while (c == 1);

    printf("La radice di %d e' circa %d (arrotondando per difetto)", x, y);

    return 0;
}