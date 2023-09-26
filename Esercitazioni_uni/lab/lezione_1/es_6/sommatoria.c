/*
Considerare la seguente funzione matematica:
y = SUM (i = q...r) 1 / i
(y uguale a sommatoria per i che va da q a r di 1 fratto i)
Si scriva un programma per il calcolo di y.
Si assuma di acquisire r e q dall'esterno (dati di input). Si controlli che r e q siano interi positivi tali che r > q.
*/

#include <stdio.h>

int main()
{
    float q, r, i, y = 0;

    do
    {
        printf("Inserire il valore iniziale e finale da mettere nell'espresione:\n");
        scanf("%f", &q);
        scanf("%f", &r);
        if (r < q)
            printf("Il valore finale deve essere maggiore o uguale a quello inziale, riprova l'inserimento\n");
    } while (r < q);

    for (i = q; i <= r; ++i)
    {
        y += 1 / i;
    }

    printf("Il valore della sommatoria per i che va da %f a %f di 1/i e' uguale a: %f", q, r, y);

    return 0;
}