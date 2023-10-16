/* Esercizio 7 - Sequenza contenuta

Scrivete un programma che legga da input due array, A da 10 elementi e B da 5 elementi.
Il programma deve stampare "B è contenuto in A" se A contiene la sequenza contigua dei numeri di B,
altrimenti stampa "B non è contenuto in A".

Esempio: Con
A = [8, 55, 72, 44, 93, 27, 68, 3, 12, 66]
B = [44, 93, 27, 68, 3]
B è contenuto in A. */

#include <stdio.h>
#include <stdlib.h>

typedef int contatori;
typedef enum bool
{
    False,
    True
} bool;

#define DIM1 10
#define DIM2 5

int main()
{
    int seq1[DIM1], seq2[DIM2], coincidono;
    contatori i, j, k;
    bool controllo, esci = False;

    printf("Inserire la prima sequenza di numeri:\n");
    for (i = 0; i < DIM1; i++)
    {
        scanf("%d", &seq1[i]);
    }

    printf("Inserire la seconda sequenza di numeri:\n");
    for (i = 0; i < DIM2; i++)
    {
        scanf("%d", &seq2[i]);
    }

    for (j = 0; j <= DIM2 && esci == False; j++)
    {
        controllo = False;
        if (seq2[0] == seq1[j])
        {
            coincidono = 1;
            controllo = True;
            for (k = 1; k < DIM2 && controllo == True; k++)
            {
                if (seq2[k] != seq1[k + j])
                    controllo = False;
                else
                    coincidono += 1;
            }
        }
        if (coincidono == 5)
            esci = True;
    }

    if (esci == False)
        printf("La sequenza 2 non e' contenuta nella sequenza 1");
    else
        printf("La sequenza 2 e' contenuta nella sequenza 1");

    return 0;
}