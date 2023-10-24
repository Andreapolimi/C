/*
 * Es. 2
 * Calcolare il fattoriale di un numero dato in input
 */

#include <stdio.h>
#include <math.h>

int main() {
  // Dichiarazione variabili
  int n; // numero in input
  int fatt; // fattoriale di n

  // Lettura di n da tastiera
  do{
    printf("Inserire numero di cui calcolare il fattoriale: ");
    scanf("%d", &n);
    if(n < 0) {
      printf("Errore, il numero deve essere positivo. Riprova\n");
    }
  }while(n < 0); // gestione caso limite n<0: richiedo l'input all'utente con il do-while 
  
  for(fatt = 1; n > 1; n--) {
    fatt = fatt * n;
  }
  // Nota: e' gestito il caso limite n==0?

  // Nota: cosa succede se do in input un numero abbastanza alto (ad es., 20)? Perche'?

  // Stampa a video del risultato
  
  printf("Il fattoriale di %d e' %d\n", n, fatt);
  
  return 0;
}
