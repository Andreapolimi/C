/*
 * Es. 2
 * Max e min in sequenza di N interi
 * 
 * E.g.
 * N=5
 * Sequenza: 3, 12, 20, 6, 1
 * 
 * Min: 1
 * Max: 20
 */

#include <stdio.h>

int main() {
  // Dichiarazione variabili
  int n;
  int numero;
  int i;
  int max, min;

  // Lettura di N da tastiera (ripeto la lettura se N non valido)
  do {
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
  } while(n <= 0); // continuo a chiedere finche' non ricevo un input valido

  // Se sono arrivato a questo punto, n è valido (>= 1). 
  // Non ci sono altri casi limite da controllare.

  // Lettura da tastiera del primo valore della sequenza. 
  // (Fuori dal ciclo per inizializzare min,max)
  // Nota: assumo che N sia sempre >= 1!
  printf("Inserire numero: ");
  scanf("%d", &numero);
  // Inizializzazione min, max con primo valore della sequenza
  min = numero;
  max = numero;

  // Lettura valori seguenti nella sequenza
  for(i=1; i < n; i++) { // Nota: i parte da 1, perché iteraz. 0-esima già eseguita sopra

    // Lettura valore da tastiera
    printf("Inserire numero: ");
    scanf("%d", &numero);

    // Se il nuovo valore e' piu' piccolo del minimo corrente, e' il nuovo minimo
    if (numero < min) {
      min = numero;
    }

    // Se il nuovo valore e' piu' grande del massimo corrente, e' il nuovo massimo
    if (numero > max) {
      max = numero;
    }
  }

  // Stampa a video dei risultati
  printf("Il minimo della sequenza e': %d\n", min);
  printf("Il massimo della sequenza e': %d\n", max);

  return 0;
}