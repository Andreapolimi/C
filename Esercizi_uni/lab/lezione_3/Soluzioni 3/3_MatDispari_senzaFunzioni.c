/*
 * Politecnico di Milano
 * Dipartimento di Elettronica e Informazione
 * Fondamenti di Informatica
 *
 * --------------------------------
 *    MatDispari.c
 * --------------------------------
 *
 * Scrivere una funzione in C che data una matrice Mat1 di interi NxN, con N costante opportunamente definita, copia i soli elementi dispari in una nuova matrice Mat2 della stessa dimensione, senza lasciare posizioni vuote intermedie.
 * Implementare un main che, dopo aver richiamato la funzione implementata, stampa a video la nuova matrice, visualizzando gli elementi per righe.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){

    int Mat1[N][N] = {{4,5,6,2,9}, {3,1,7,6,4}, {4,6,9,0,8}, {6,8,3,65,23}, {4,776,21,98,7}};
    int Mat2[N][N];

    int i,j,k,l;

    printf("La matrice di partenza è: \n");

    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            printf("%d ", Mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // inizializzo Mat2

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            Mat2[i][j] = 0;
        }
    }


    // copia elementi dispari

    k=0;l=0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++) {
            if(Mat1[i][j]%2!=0) {
                Mat2[l][k] = Mat1[i][j];
                k++;
                if(k==N) {
                    k=0;
                    l++;
                }
            }
        }
    }


    // stampa dei valori di Mat2

    printf("La matrice formata dai soli valori dispari è: \n");

    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            printf("%d ", Mat2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;

}


