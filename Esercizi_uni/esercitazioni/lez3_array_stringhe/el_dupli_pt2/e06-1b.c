/*
 * Es. 1b
 * Eliminazione duplicati da array già riempito
 */

#include <stdio.h>

#define N 20
#define MIN 10
#define MAX 100

int main() {
  // Dichiarazione variabili
  int v[N];     // valori già letti
  int dim;      // dimensione effettiva di v (quanti elementi validi contiene)
  int i,j;      // indici cicli
  int trovato;  // flag (sentinella)

  // Lettura di tutto l'array dall'utente
  printf("Di seguito, sara' richiesto l'inserimento di una sequenza di %d numeri.\n", N);
  for(dim=0; dim < N; dim++) {
    do {
      printf("Inserire numero tra %d e %d (inclusi): ", MIN, MAX);
      scanf("%d", &v[dim]);
      if(v[dim] < MIN || v[dim] > MAX) {
        printf("Errore, il numero inserito non e' nel range consentito, ripetere.\n");
      }
    }while(v[dim] < MIN || v[dim] > MAX); // Ripeti l'inserimento se n e' *fuori* dal range di valori permessi

  }

  for(i = 0; i < dim; i++) {

    trovato = 0;
    for(j=0; j < i && !trovato; j++) {
      if(v[j] == v[i]) {
        trovato = 1;
      }
    }

    if(trovato) {
      // Shift a sinistra di tutti i valori dopo v[i]
      for(j = i ; j < dim - 1; j++) {
        v[j] = v[j+1];
      }
      dim--;
      i--;
    }
  }

  // Stampa di v a video (non richiesto dall'esercizio)
  printf("I numeri inseriti senza duplicati sono: ");
  for(i = 0; i < dim; i++){
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}
