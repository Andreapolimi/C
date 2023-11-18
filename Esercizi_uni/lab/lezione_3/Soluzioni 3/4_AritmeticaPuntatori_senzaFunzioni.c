/*
 * Politecnico di Milano
 * Dipartimento di Elettronica e Informazione
 * Fondamenti di Informatica
 *
 * --------------------------------
 *    Puntatori.c
 * --------------------------------

In questo esercizio dimostrerete le relazioni esistenti tra puntatori e array, utilizzando l’aritmetica dei puntatori per scorrere un array.

L'esercizio è da risolvere un passo dopo l'altro, secondo questa sequenza:

Passo 1 - dichiarare due variabili: un array di interi e un puntatore a intero a cui assegnare il nome dell'array; dimostrare l'equivalenza tra l'indirizzo dell'array, l'indirizzo del primo elemento dell'array e il contenuto del puntatore stampandoli;

Passo 2 - mostrare come dereferenziando il puntatore si ottiene il valore del primo elemento dell'array;

Passo 3 - stampare l'array non accedendo al suo contenuto tramite gli indici, ma incrementando il valore del puntatore all'array o direttamente il nome dell'array avvalendosi dell'aritmetica dei puntatori;

*/


#include <stdio.h>

#define LENGTH 4

int main(){

    printf("\n## PASSO 1 ##\n");

    int interi[] = {10, 20, 30, 40};
    int *interiPtr = interi;

    printf("L'indirizzo dell'array interi[] e': %p\n", interi);
    printf("L'indirizzo del primo elemento dell'array interi[] e': %p\n", &interi[0]);
    printf("Il valore di interiPtr e': %p\n", interiPtr);

    printf("\n## PASSO 2 ##\n");
    printf("Il valore a cui punta interiPtr e': %d\n", *interiPtr);

    printf("\n## PASSO 3 ##\n");
    printf("Stampo l'array utilizzando il puntatore al suo indirizzo mediante incremento del puntatore \n");
    int offset;
    for (offset = 0; offset < LENGTH; offset++){
        printf("*(interiPtr + %d) = %d \n", offset, *(interiPtr + offset));
    }

    printf("Dimostro che ottengo la stessa cosa utilizzando il nome dell'array \n");
    for (offset = 0; offset < LENGTH; offset++){
        printf("*(interi + %d) = %d \n", offset, *(interi + offset));
    }

    return 0;
}

