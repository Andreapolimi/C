/*
Scrivere un programma che, dati due fattori interi, sia positivi che negativi, ne calcoli il prodotto mediante somme successive.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, prodotto = 0, num_som, segno;

    printf("Inserisci il primo numero da moltiplicare: ");
    scanf("%d", &num1);
    printf("Inserisci il secondo numero da moltiplicare: ");
    scanf("%d", &num2);

    /*
    Teoricamente con if :

    if (num1 >= 0)
    {
        if (num2 >= 0)
            segno = 1;
        else
        {
            segno = -1;
        }
    }
    else
    {
        if (num2 >= 0)
            segno = -1;
        else
        {
            segno = 1;
        }
    }*/

    // Uso la forma contratta
    segno = (num1 >= 0) ? ((num2 >= 0) ? 1 : -1) : ((num2 >= 0) ? -1 : 1);

    num1 = abs(num1);
    num2 = abs(num2);

    for (num_som = 0; num_som < num2; num_som++)
    {
        prodotto += num1;
    }
    prodotto *= segno;

    printf("Il prodotto e': %d", prodotto);
}
