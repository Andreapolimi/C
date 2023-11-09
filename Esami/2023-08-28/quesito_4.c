/*Quesito 4.1 (9 punti).
Si definisca una funzione che, ricevuti come parametri di ingresso un array a di n numeri
interi positivi, {x1, x2, ..., xn}, un intero y, (y>= xi, ∀ i = 1, ..., n), e qualsiasi altro parametro ritenuto necessario,
individui le partizioni dell’array costituite da elementi adiacenti con somma minore o uguale a y.
Per esempio, sia a = {2, 8, 0, 3, 9, 6, 1, 3} e sia y = 10. Allora:
{2, 8, 0} {3} {9} {6, 1, 3} sono le possibili partizioni individuabili in base al criterio sopra definito.

La funzione dovrà costruire e restituire al chiamante una lista dinamica i cui elementi memorizzano, per ogni
partizione individuata, gli indici nell’array del primo e dell’ultimo elemento della partizione. Per esempio, per
le partizioni individuate al punto precedente, la lista sarà così costituita:

[0 2] -> [3 3] -> [4 4] -> [5 7] -.

Oltre  a  definire  la  funzione,  si  dichiarino  opportunamente  le strutture  dati su  cui  la  funzione  opera,  e  cioè
l’array, il nodo della lista e la lista stessa.

Quesito 4.2 (3 punti).  Si scriva un programma in C, completo delle sue parti dichiarative che, dopo aver letto i
valori dell’array a  da  un  file,  e  letto  in  input  il valore di  y,  invochi  in modo opportuno  la  funzione  definita  al
punto precedente e utilizzi la lista restituita dalla funzione per stampare a video le partizioni.

Per la lettura della matrice dal file, si consideri che:
1. Il  nome  del  file  deve  essere  fornito  in  input  da  riga  di  comando  (deve  cioè  essere  gestito  come
parametro del main).
2. Il file è organizzato in modo che i valori siano memorizzati in sequenza e siano separati da uno spazio.
Per l’array nell’esempio precedente, il file è così organizzato:
2  8   0  3  9  6  1  3
Si può assumere che il numero dei valori memorizzati nel file sia minore o al più uguale alla dimensione
massima dell’array, definita dalla costante predefinita N.*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_EL 8
#define INIZIALE 0
#define FINALE 1

typedef int cont_t;
typedef struct node
{
    int elementi[2];
    struct node *nodo_succ;
} node_t;

node_t *crea_lista(int *array, int y)
{
    node_t *array_nodi;
    node_t *testa;
    cont_t i, j = 0;
    int somma = 0, num_nodi = 1;

    array_nodi = (node_t *)calloc(num_nodi, num_nodi * sizeof(node_t));
    testa = &array_nodi[j];

    for (i = 0; i < NUM_EL; i++)
    {
        if (somma + array[i] <= y)
        {
            testa->elementi[FINALE] = i;
            somma += array[i];
            j++;
        }
        else
        {
            testa->elementi[FINALE] = i - 1;
            j = 0;
            somma = array[i];
            num_nodi++;
            array_nodi = (node_t *)realloc(array_nodi, num_nodi * sizeof(node_t));
            testa->nodo_succ = &array_nodi[num_nodi - 1];
            testa = testa->nodo_succ;
            testa->elementi[INIZIALE] = i;
        }
    }
    testa->nodo_succ = NULL;

    testa = array_nodi;

    return testa;
}

void stampa_lista(node_t *testa)
{
    cont_t i;

    while (testa != NULL)
    {
        for (i = 0; i < 2; i++)
            printf("%d\t", testa->elementi[i]);
        testa = testa->nodo_succ;
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int y, array[NUM_EL];
    FILE *file_handle;
    node_t *testa;
    cont_t i;

    printf("Inserire il valore y di riferimento: ");
    scanf("%d", &y);

    file_handle = fopen(argv[1], "r");
    if (file_handle == NULL)
    {
        printf("Apertura file fallita");
        exit(1);
    }
    else
        printf("File aperto con successo\n");

    i = 0;
    while (!feof(file_handle))
    {
        fscanf(file_handle, "%d", &array[i]);
        i++;
    }

    testa = crea_lista(array, y);

    stampa_lista(testa);

    fclose(file_handle);

    return 0;
}