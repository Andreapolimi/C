/*
 * Es. 3
 * Crivello di Eratostene
 */

#include <stdio.h>
#include <math.h>

#define MAX 1000

int main() {
  // Dichiarazione variabili
  int c[MAX]; // crivello
  int i, j; // indici per i cicli

  // Inizializzo ogni elemento di c a 1
  for(i = 0; i < MAX; i++) {
    c[i] = 1;
  }

  // Algoritmo del crivello di Eratostene
  for(i = 2; i < MAX; i++) { // scorro ogni elemento di c
    if (c[i]) { // Se l'elemento corrente e' 1 (quindi i e' primo)
                // Nota: se c[i]==1, significa che non l'ho mai settato a 0, i.e., non ho mai trovato un suo divisore

      // Setto a 0 tutti gli elementi con indice multiplo di i:
      
      // Opzione 1 (inefficiente): scorro tutti gli elementi di c, setto a 0 solo i multipli
      /*
      for(j = i+1; j < MAX; j++) {
        if(j % i == 0) {
          c[j] = 0;
        }
      }
      */

      // Opzione 2 (ok): parto dal prossimo multiplo (2i); uso j per indicizzare c e lo incremento di i posizioni 
      //                 ad ogni iterazione (j=2i, 2i+i, 2i+i+i, ...)
      /*
      for(j = 2*i; j < MAX; j+=i) {
        c[j] = 0;
      }
      */

      // Opzione 3 (ok): parto dal prossimo multiplo (2i); uso j per contare i multipli di i (j=2,3,4,...)
      //                 e indicizzo c con j*i
      for(j = 2; j * i < MAX; j++) {
        c[j*i] = 0;
      }
    }
  }
  
  // Stampa a video del risultato
  printf("Questi sono i numeri primi da 1 a %d:\n", MAX);
  for(i = 0; i < MAX; i++) {
    if (c[i]) { // se c[i] == 1
      printf("%d ", i);
    }
  }
  printf("\n");
  
  
  return 0;
}
