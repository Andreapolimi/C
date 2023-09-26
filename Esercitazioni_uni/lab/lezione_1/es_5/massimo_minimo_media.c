/*
Leggere in input una sequenza di numeri naturali (interi positivi strettamente maggiori di zero) e calcolare e visualizzare il massimo,
il minimo e la media.
La sequenza si interrompe non appena viene introdotto un numero negativo o uguale a zero
Per esempio, data la sequenza 5, 1, 2, 3, 6, -5, l'output deve essere: "Il massimo è 6, il minimo è 1, la media è 3.4".
Data la sequenza -2, l'output deve essere "La sequenza inserita è nulla".*/

#include <stdio.h>

int main()
{
    int num = 1, cont = 0, min, max, media, controllo = 0;

    do
    {
        printf("Inserisci il %d° numero: ", cont + 1);
        scanf("%d", &num);
        if (num <= 0)
            controllo = 1;
        else
        {
            if (cont == 1)
            {
                min = num;
                max = num;
                media = num;
            }
            else
            {
                if (num > max)
                    max = num;
                if (num < min)
                    min = num;
                media += num;
            }
            ++cont;
        }

    } while (controllo == 0);

    if (cont == 0)
        printf("La sequenza inserita e' nulla");
    else
    {
        media /= cont;
        printf("Il massimo  e' %d, il minimo e' %d e la media e' %d", max, min, media);
    }

    return 0;
}