// Dati in input i vertici di un poligono (nel pinao cartesiano) calcolarne il perimetro

#include <stdio.h>
#include <math.h>

typedef struct pt
{
    float x, y;
} punto;

typedef int contatori;

typedef enum bool
{
    False,
    True
} bool;

int main()
{
    bool controllo;
    contatori i;
    int num_punti, pt_fav, indice_partenza, lati_calc, indice_prova;
    float perimetro = 0, dist_prova, dist_confronto, prima_x, prima_y;

    // creazione del vettore di punti
    printf("Inserire il numero di vertici del poligono di cui calcolare il perimetro: ");
    scanf("%d", &num_punti);

    while (num_punti <= 2)
    {
        printf("Inserire una dimensione maggiore a 2 (dimensione di una retta)\n");
        printf("Inserire il numero di vertici del poligono di cui calcolare il perimetro: ");
        scanf("%d", &num_punti);
    }

    punto punti_input[num_punti];

    // acquisizione punti
    for (i = 0; i < num_punti; i++)
    {
        printf("Inserisci l'ascissa del %d° punto: ", i + 1);
        scanf("%f", &punti_input[i].x);
        printf("Inserisci l'ordinata del %d° punto: ", i + 1);
        scanf("%f", &punti_input[i].y);
    }

    // calcolo perimetro (o lunghezza nel caso della retta)
    indice_partenza = 0;
    pt_fav = num_punti;
    lati_calc = 0;
    prima_x = punti_input[indice_partenza].x;
    prima_y = punti_input[indice_partenza].y;

    while (lati_calc != num_punti)
    {
        // inizializzo variabili utili per trovare i punti da usare per il calcolo di ogni lato
        controllo = False;

        // controllo punti in senso anti-orario con x maggiore, i punti favorevoli saranno quelli più vicini a quello iniziale

        // controllo dei punti di indice maggiore di quello di partenza
        for (i = indice_partenza + 1; i < pt_fav; i++)
        {
            if (punti_input[i].x >= punti_input[indice_partenza].x)
            {
                if (controllo == False)
                {
                    indice_prova = i;
                    controllo = True;
                    dist_prova = sqrt(pow(punti_input[indice_partenza].x - punti_input[i].x, 2) + pow(punti_input[indice_partenza].y - punti_input[i].y, 2));
                }
                else
                {
                    dist_confronto = sqrt(pow(punti_input[indice_partenza].x - punti_input[i].x, 2) + pow(punti_input[indice_partenza].y - punti_input[i].y, 2));
                    if (dist_prova > dist_confronto)
                    {
                        indice_prova = i;
                        dist_prova = dist_confronto;
                    }
                }
            }
        }

        // controllo dei punti di indice minore di quello di partenza
        for (i = indice_partenza - 1; i >= 0; i--)
        {
            if (punti_input[i].x >= punti_input[indice_partenza].x)
            {
                if (controllo == False)
                {
                    indice_prova = i;
                    controllo = True;
                    dist_prova = sqrt(pow(punti_input[indice_partenza].x - punti_input[i].x, 2) + pow(punti_input[indice_partenza].y - punti_input[i].y, 2));
                }
                else
                {
                    dist_confronto = sqrt(pow(punti_input[indice_partenza].x - punti_input[i].x, 2) + pow(punti_input[indice_partenza].y - punti_input[i].y, 2));
                    if (dist_prova > dist_confronto)
                    {
                        indice_prova = i;
                        dist_prova = dist_confronto;
                    }
                }
            }
        }

        // controllo in senso antiorario con x minore se non mi erano punti in senso orario, i punti favorevoli saranno quelli più vicini a quello iniziale

        if (controllo == False)
        {
            // controllo dei punti di indice maggiore di quello di partenza
            for (i = indice_partenza + 1; i < pt_fav; i++)
            {
                if (punti_input[i].x <= punti_input[indice_partenza].x)
                {
                    if (controllo == False)
                    {
                        indice_prova = i;
                        dist_prova = sqrt(pow(punti_input[indice_partenza].x - punti_input[i].x, 2) + pow(punti_input[indice_partenza].y - punti_input[i].y, 2));
                    }
                    else
                    {
                        dist_confronto = sqrt(pow(punti_input[indice_partenza].x - punti_input[i].x, 2) + pow(punti_input[indice_partenza].y - punti_input[i].y, 2));
                        if (dist_prova > dist_confronto)
                        {
                            indice_prova = i;
                            dist_prova = dist_confronto;
                        }
                    }
                }
            }

            // controllo dei punti di indice minore di quello di partenza

            for (i = indice_partenza - 1; i >= 0; i--)
            {
                if (punti_input[i].x <= punti_input[indice_partenza].x)
                {
                    if (controllo == False)
                    {
                        indice_prova = i;
                        dist_prova = sqrt(pow(punti_input[indice_partenza].x - punti_input[i].x, 2) + pow(punti_input[indice_partenza].y - punti_input[i].y, 2));
                    }
                    else
                    {
                        dist_confronto = sqrt(pow(punti_input[indice_partenza].x - punti_input[i].x, 2) + pow(punti_input[indice_partenza].y - punti_input[i].y, 2));
                        if (dist_prova > dist_confronto)
                        {
                            indice_prova = i;
                            dist_prova = dist_confronto;
                        }
                    }
                }
            }
        }

        // calcolo perimetro
        perimetro += dist_prova;
        lati_calc++;

        // elimino il punto di partenza già utiliizzato
        for (i = indice_partenza; i < pt_fav - 1; i++)
            punti_input[i] = punti_input[i + 1];

        pt_fav--;

        // inizializzo il prossimo punto di partenza
        indice_partenza = indice_prova;

        // controllo se manca calcolare solo l'ultimo lato
        if (pt_fav == 1)
        {
            perimetro += sqrt(pow(punti_input[indice_partenza].x - prima_x, 2) + pow(punti_input[indice_partenza].y - prima_y, 2));
            lati_calc++;
        }
    }

    printf("Il perimetro ha dimensione %f", perimetro);

    return 0;
}