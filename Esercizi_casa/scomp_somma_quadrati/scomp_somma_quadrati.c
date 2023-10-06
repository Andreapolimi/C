/*
Scrivere un programma che legge un intero positivo n da stdin e verifica se
n può essere scomposto nella somma di due quadrati. Se sì, stampare a video la/le scomposizione/i
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num, quadrato, i = 1, controllo = 0;

    printf("Inserisci il num di cui vuoi ottenere la scomposizione in 2 quadrati: ");
    scanf("%d", &num);

    while ((num - pow(i, 2)) > 0 && pow(i, 2) <= (num / 2))
    {
        quadrato = num - pow(i, 2);
        if ((quadrato / (int)sqrt(quadrato) == (int)sqrt(quadrato)) && (quadrato % (int)sqrt(quadrato) == 0))
        {
            printf("Si può scomporre come %d^2 + %d^2\n", i, (int)sqrt(quadrato));
            controllo = 1;
        }
        i++;
    }
    if (controllo == 0)
        printf("Nessuna scomposizione possibile");

    return 0;
}