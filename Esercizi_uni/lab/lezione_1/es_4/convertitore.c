/*
Scrivere un programma che chieda all'utente un valore in base decimale e lo converta in base scelta dall'utente,
stampandone il risultato a video.
*/

#include <stdio.h>
#define dim 50

int main()
{
    int num, controllo = 0, num_bina[dim], c = 0, i, base;

    printf("inserisci il numero da convertire: ");
    scanf("%d", &num);
    printf("Inserisci la base a cui vuoi convertire il numeoro: ");
    scanf("%d", &base);

    do
    {
        num_bina[c] = num % base;
        num /= base;
        c++;
    } while (num >= base - 1);

    for (i = c - 1; i >= 0; i--)
    {
        printf("%d", num_bina[i]);
    }

    return 0;
}