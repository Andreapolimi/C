// Dati in input i vertici di un poligono (nel pinao cartesiano) calcolarne il perimetro

#include <stdio.h>
#include <math.h>
#include <stdlib.h> //libreria necessaria in questo esercizio esclusivamente per l'utilizzo dell'allocazione dinamica della memoria

typedef struct pt
{
    float x, y;
} punto;

typedef int contatori;

int main()
{
    contatori i;
    punto *punti_input;
    /* per non usare il puntatore si può dichiarare 'punti_input[DIM_MAX]' come array a dimensione prefissata (del tipo
    '#define DIM_MAX 50') molto alta oltre la quale l'utente non potrà lavorare, per praticità ho usato un vettore dinamico */
    int dim;
    float perimetro = 0;

    // creazione del vettore di punti
    printf("Inserire il numero di vertici del poligono di cui calcolare il perimetro: ");
    scanf("%d", &dim);

    while (dim <= 2)
    {
        printf("Inserire una dimensione maggiore a 2 (dimensione di una retta)\n");
        printf("Inserire il numero di vertici del poligono di cui calcolare il perimetro: ");
        scanf("%d", &dim);
    }

    // allocazione memoria dinamica, nel caso di vettori statici questo passaggio è da saltare
    punti_input = (punto *)calloc(dim, dim * sizeof(punto));

    // acquisizione punti
    for (i = 0; i < dim; i++)
    {
        printf("Inserisci l'ascissa del %d° punto: ", i + 1);
        scanf("%f", &punti_input[i].x);
        printf("Inserisci l'ordinata del %d° punto: ", i + 1);
        scanf("%f", &punti_input[i].y);
    }

    // calcolo perimetro (o lunghezza nel caso della retta)
    for (i = 0; i + 1 <= dim; i++)
    {
        if (i == dim)
            perimetro += sqrt(pow(punti_input[i - dim].x - punti_input[i - 1].x, 2) + pow(punti_input[i - dim].y - punti_input[i - 1].y, 2));
        else
            perimetro += sqrt(pow(punti_input[i].x - punti_input[i + 1].x, 2) + pow(punti_input[i].y - punti_input[i + 1].y, 2));
    }

    printf("Il perimetro ha dimensione %f", perimetro);

    free(punti_input); // liberazione memoria dinamica, se si usa il vettore statico è da saltare

    return 0;
}
