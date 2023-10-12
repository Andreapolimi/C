#include <stdio.h>

typedef int controllo;
typedef int contatori;

typedef enum bool
{
    False,
    True
} Bool;

int main()
{
    contatori i;
    controllo quoziente, esci = False;
    int num;

    printf("Inserisci il numero: ");
    scanf("%d", &num);
    quoziente = num;

    for (i = 2; i < quoziente && esci == False; i++)
    {
        if (num % i == 0)
        {
            printf("%d non e' primo", num);
            esci = True;
        }
        quoziente = num / i;
    }

    if (esci == 0)
        printf("%d e' primo", num);

    return 0;
}