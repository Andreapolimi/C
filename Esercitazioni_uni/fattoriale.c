/*
Scrivi un programma in C che chieda all'utente di inserire un intero non negativo n.
Calcola e stampa il fattoriale di n utilizzando un ciclo che è controllato da una variabile contatore.
*/

#include <stdio.h>

int main()
{
    int n, i, fattone = 1;

    do
    {
        printf("Inserisci il numero non negativo");
        scanf("%d", &n);
        if (n < 0)
            printf("errore sei stupido, riinserisci\n");
    } while (n < 0);

    if (n == 0)
    {
        printf("Sei un poco di buono, e il fattone è 1");
    }
    else
    {
        for (i = n; i > 0; i--)
        {
            fattone *= i;
        }
        printf("%d", fattone);
    }

    return 0;
}