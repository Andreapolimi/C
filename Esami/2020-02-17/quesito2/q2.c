#include <stdio.h>
#include <stdlib.h>

int SommaIntermedi(int n1, int n2)
{
    int somma = 0;

    if (n1 + 1 < n2)
    {
        n1++;
        somma += n1;
        somma += SommaIntermedi(n1, n2);
    }
    return somma;
}

int main()
{
    int n1 = 2, n2 = 5;

    printf("%d", SommaIntermedi(n1, n2));

    return 0;
}