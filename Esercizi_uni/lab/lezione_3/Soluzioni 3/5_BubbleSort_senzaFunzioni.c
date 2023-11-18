/*
 * Politecnico di Milano
 * Dipartimento di Elettronica e Informazione
 * Fondamenti di Informatica
 *
 * --------------------------------
 *    BubbleSortFusione.c
 * --------------------------------
 *
 * Scrivere un programma che:
 * - chiede due volte all'utente di inserire N valori interi, e li salva in due
 *   array di dimensione N;
 * - ordina quindi ciascun array utilizzando il metodo Bubble Sort;
 * - effettua la fusione dei due array, in modo che l'array risultante
 *   mantenga l'ordinamento;
 * - stampa il vettore dopo la fusione.
*/

#include <stdio.h>

#define N 5

int swapCount;
int confrontoCount;

int main(){

    setbuf(stdout, NULL);
    // Dichiarazione delle variabili
    int numbers1[N];
    int numbers2[N];
    int fusione[N+N];
    int i = 0, j = 0, k = 0, temp;

    // Lettura dei valori inseriti dall'utente
    for(i=0; i<N; i++){
        printf("Inserisci il valore dell'elemento %d del primo vettore: ", i);
        scanf("%d",&numbers1[i]);
    }
    for(i=0; i<N; i++){
        printf("Inserisci il valore dell'elemento %d del secondo vettore: ", i);
        scanf("%d",&numbers2[i]);
    }

    printf("I vettori inseriti sono i seguenti: \n");

    //print1
    printf("[");
    for(i=0; i<N; i++){
        if(i<N-1)
            printf("%d, ", numbers1[i]);
        else
            printf("%d]\n", numbers1[i]);
    }

    //print2
    printf("[");
    for(i=0; i<N; i++){
        if(i<N-1)
            printf("%d, ", numbers2[i]);
        else
            printf("%d]\n", numbers2[i]);
    }


    //sort1
    swapCount = 0;
    confrontoCount = 0;
    for (i = N-1; i > 0; i--){
        for (j = 1; j <= i; j++){
            // Ad ogni iterazione sposto il valore più grande nell'ultima posizione
            // non ancora assegnata (che ha come indice il valore di i)
            confrontoCount++;
            if (numbers1[j-1] > numbers1[j]){
                // Scambia l'elemento nella posizione j
                // con l'elemento nella posizione j-
                temp = numbers1[j-1];
                numbers1[j-1] = numbers1[j];
                numbers1[j] = temp;

                swapCount++;
            }
        }
    }

    printf("Il vettore ordinato è il seguente: \n");

    //print1
    printf("[");
    for(i=0; i<N; i++){
        if(i<N-1)
            printf("%d, ", numbers1[i]);
        else
            printf("%d]\n", numbers1[i]);
    }

    printf("Sono stati eseguiti %d confronti e %d swap\n",
           confrontoCount, swapCount);


    //sort2
    swapCount = 0;
    confrontoCount = 0;
    for (i = N-1; i > 0; i--){
        for (j = 1; j <= i; j++){
            // Ad ogni iterazione sposto il valore più grande nell'ultima posizione
            // non ancora assegnata (che ha come indice il valore di i)
            confrontoCount++;
            if (numbers2[j-1] > numbers2[j]){
                // Scambia l'elemento nella posizione j
                // con l'elemento nella posizione j-
                temp = numbers2[j-1];
                numbers2[j-1] = numbers2[j];
                numbers2[j] = temp;

                swapCount++;
            }
        }
    }

    printf("Il vettore ordinato è il seguente: \n");
    //print2
    printf("[");
    for(i=0; i<N; i++){
        if(i<N-1)
            printf("%d, ", numbers2[i]);
        else
            printf("%d]\n", numbers2[i]);
    }

    printf("Sono stati eseguiti %d confronti e %d swap\n",
           confrontoCount, swapCount);


    //fusione

    i = 0;
	j = 0;

    // Fino a che nessuno dei due array è stato tutto copiato
    // confronto gli elementi da copiare e riempio il nuovo array
    while (i < N && j < N){
        if (numbers1[i] < numbers2[j]){
            fusione[k] = numbers1[i];
            i++;
        } else {
            fusione[k] = numbers2[j];
            j++;
        }
        k++;
    }

    // Finchè ci sono ancora elementi in v1 da copiare
    while (i < N){
        fusione[k] = numbers1[i];
        i++;
        k++;
    }
    // Finchè ci sono ancora elementi in v2 da copiare
    while (j < N){
        fusione[k] = numbers2[j];
        j++;
        k++;
    }


    printf("Il vettore ottenuto dalla fusione è: \n");

    //printFusione
    printf("[");
    for(i=0; i<N+N; i++){
        if(i<N+N-1)
            printf("%d, ", fusione[i]);
        else
            printf("%d]\n", fusione[i]);
    }



    return 0;
}
