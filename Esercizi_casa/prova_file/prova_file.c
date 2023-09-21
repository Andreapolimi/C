#include <stdio.h>
#include <stdlib.h>
#define DIM 50

int main()
{
    FILE *prova;

    prova = fopen("/Users/andreavaccai/Coding/C/Esercizi_casa/prova_file/docprova.txt", "r");
    char riga[DIM];

    if (prova)
    {
        printf("OK");
        while (!feof(prova))
        {
            fgets(riga, DIM, prova);
            printf("%s", riga);
        }
    }
    else
    {
        printf("ERRORE");
    }

    fclose(prova);

    return 0;
}