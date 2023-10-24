#include <stdio.h>
#include <stdlib.h>

typedef int controllo;
typedef int contatori;

typedef enum bool
{
    False,
    True
} Bool;

typedef int vettori;

int main()
{
    contatori i, j;
    controllo quoziente;
    Bool esci = False;
    int num;

    printf("Inserisci il numero: ");
    scanf("%d", &num);
    quoziente = num;

    for (i = 2; i < quoziente && esci == False; i++)
    // al posto di < quoziente posso mettere <= (int)sqrt(num) e avrò lo stesso numero di iterazioni (usando una variabile in meno)
    {

        if (num % i == 0)
        {
            printf("%d non e' primo", num);
            esci = True;
        }

        quoziente = num / i;
    }

    if (esci == False)
        printf("%d e' primo", num);

    printf("\nNumero di iterazioni: %d", i);

    return 0;
}