/*
 * Es. 1
 * Eliminazione duplicati (durante lettura)
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
  int n;        // numero appena letto
  int trovato;  // flag (sentinella)

  // Idea: devo ricordarmi i numeri inseriti in passato per poter controllare se un numero è già stato visto

  // Istruzioni per l'utente
  printf("Di seguito, sara' richiesto l'inserimento di una sequenza di %d numeri.\n", N);

  dim = 0; // v attualmente non contiene elementi

  for(i=0; i < N; i++) { // Per ogni numero da dover leggere
    // Lettura nuovo numero
    
    do {
      printf("Inserire numero tra %d e %d (inclusi): ", MIN, MAX);
      scanf("%d", &n);
      if(n < MIN || n > MAX) {
        printf("Errore, il numero inserito non e' nel range consentito, ripetere.\n");
      }
    }while(n < MIN || n > MAX); // Ripeti l'inserimento se n e' *fuori* dal range di valori permessi

    // Cerco se il numero e' gia' stato inserito in passato
    trovato = 0; // fino a prova contraria, assumo di non aver trovato duplicati: trovato = 0 (FALSE)
    for(j=0; j < dim && !trovato; j++) { // Scorro tutti i valori salvati nell'array (ma esco prima se trovo un duplicato)
      if(v[j] == n) { // Se il valore corrente e' uguale al numero appena inserito
        trovato = 1;  // Ho trovato un duplicato: trovato = 1 (TRUE)
      }
    }
    // A questo punto, se trovato vale 1 (TRUE) allora sono entrato nell'if sopra, i.e., ho trovato un duplicato;
    //                 se trovato vale 0 (FALSE), allora non sono mai entrato nell'if sopra, i.e., non ho trovato alcun duplicato.

    if(!trovato) { // Se trovato == 0 (FALSE) --> non ho trovato duplicati --> e' la prima volta che vedo questo numero
      // Aggiungo il numero all'array
      v[dim] = n; // Inserisco n nella prima cella libera di v
                  // Nota: la dimensione effettiva indica anche l'indice della prima cella libera nell'array
      dim++; // Ho aggiunto un valore a v, devo *sempre* mantenere aggiornata la dimensione effettiva

      // Stampo il numero a video
      printf("Il numero inserito %d non e' mai stato inserito prima.\n", n);
    }
  }

  printf("Termine inserimento.\n");

  // Stampa di v a video (non richiesto dall'esercizio)
  printf("Sono stati inseriti i seguenti numeri (senza duplicati): ");
  for(i=0; i < dim; i++){
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}
