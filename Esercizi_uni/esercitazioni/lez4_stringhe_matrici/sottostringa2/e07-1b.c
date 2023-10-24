/*
 * Es. 1b
 * Ricerca sottostringa
 * Variante: stampa a video la posizione di ogni sottostringa trovata
 */

#include <stdio.h>
#include <string.h>

#define MAX 30

int main() {
  // Dichiarazione variabili
  char src[MAX+1]; // Stringa sorgente (in cui trovare la sottostringa)
  char tgt[MAX+1]; // Stringa target (devo verificare se e' sottostringa di src)
  int src_len, tgt_len; // Lunghezze stringhe src e tgt
  int i, j; // Indici per scansione stringhe
  int subpos[MAX]; // Vettore necessario a memorizzare tutte le posizioni in cui viene trovata la sottostringa tgt in src
  int dim_subpos; // Dimensione effettiva di sub_pos

  // Lettura stringhe da tastiera
  // Nota: utilizzo la gets per consentire l'inserimento di spazi
  printf("Inserire stringa sorgente: ");
  gets(src);
  printf("Inserire stringa target: ");
  gets(tgt);

  // Idea: come per e07-1, ma quando trovo un'occorrenza di tgt in src, salvo i in subpos e continuo comunque la ricerca.

  // Calcolo la lunghezza delle due stringhe
  src_len = strlen(src);
  tgt_len = strlen(tgt);

  // Init dimensione effettiva subpos
  dim_subpos = 0;
  
  // Come in e07-1
  for(i = 0; i + tgt_len <= src_len; i++) {
    for (j = 0; j < tgt_len && src[i+j] == tgt[j]; j++); // Ciclo for senza istruzioni (;), equivalente alla versione con flag is_substring. (Maneggiare con cura!)
    // Se ho trovato la sottostringa tgt in src, salvo la sua posizione in subpos
    if (j == tgt_len) { // Se sono arrivato a fine stringa, i.e. tutti i caratteri sono uguali. Equivalente a if(is_substring) nella versione con flag is_substring.
      subpos[dim_subpos] = i;
      dim_subpos++;
    }
  }

  // Stampa a video del risultato
  if(dim_subpos > 0) {
    printf("La stringa \"%s\" contiene la sottostringa \"%s\" alla/e posizione/i:", src, tgt);
    for(i = 0; i < dim_subpos; i++) {
      printf(" %d", subpos[i]);
    }
  } else {
    printf("La stringa \"%s\" NON e' sottostringa di \"%s\"", tgt, src);
  }
  printf("\n");


  return 0;
}
