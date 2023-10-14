/*
Scrivere un programma che chieda all'utente di inserire due frazioni di segno positivo nel formato numeratore / denominatore
(o inserendo i singoli valori), calcoli il risultato della somma e lo stampi a video.
*/

#include <stdio.h>

int algoritmo_eulero(int n1, int n2)
{
    int max, min, var_appog;

    max = (n1 > n2) ? n1 : n2;
    if (max == n1)
        min = n2;
    else
        min = n1;

    while ((max % min) != 0)
    {
        max -= min;
        if (max < min)
        {
            var_appog = max;
            max = min;
            min = var_appog;
        }
    }
    return min;
}

int main()
{
    int num1, den1, num2, den2, ris_num, ris_den, mcd;

    printf("Inserisci numeratore del primo numero: ");
    scanf("%d", &num1);
    printf("Inserisci denominatore del primo numero: ");
    scanf("%d", &den1);

    printf("Inserisci numeratore del secondo numero: ");
    scanf("%d", &num2);
    printf("Inserisci denominatore del secondo numero: ");
    scanf("%d", &den2);

    ris_den = den1 * den2;

    ris_num = den1 * num2 + den2 * num1;

    mcd = algoritmo_eulero(ris_den, ris_num);

    ris_num /= mcd;
    ris_den /= mcd;

    if (ris_den == 1)
        printf("Il risultato della somma e': %d", ris_num);
    else
        printf("Il risultato della somma e': %d/%d", ris_num, ris_den);

    return 0;
}