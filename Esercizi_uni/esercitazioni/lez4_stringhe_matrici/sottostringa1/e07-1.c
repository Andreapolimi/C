/*
 * Es. 1
 * Ricerca sottostringa
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
  int is_substring; // Flag (sentinella)

  // Lettura stringhe da tastiera
  // Nota: utilizzo la gets per consentire l'inserimento di spazi
  printf("Inserire stringa sorgente: ");
  gets(src);
  printf("Inserire stringa target: ");
  gets(tgt);

  // Idea: scorro con indice i la stringa src, per ogni posizione di i mi chiedo "la sottostringa tgt inizia qui?"
  //       l'indice i arriva all'ultima posizione in cui tgt puo' trovarsi senza uscire da src, e cioe' quando i + lunghezza_tgt == lunghezza_src
  //       Dato un i, verifico se la stringa tgt si trova in quella posizione, confrontando a uno a uno ogni carattere. 
  //       Se ogni carattere corrisponde, ho trovato la posizione della sottostringa, e posso uscire; altrimenti, non posso concludere e continuo a cercare per il prossimo valore di i.

  // Calcolo la lunghezza delle due stringhe
  src_len = strlen(src);
  tgt_len = strlen(tgt);

  is_substring = 0; // Setto la sentinella a FALSE per entrare nel ciclo seguente
                    // Idea: continuo a scorrere src finche' non arrivo in fondo o ho dimostrato che tgt non e' sottostringa
  for(i = 0; i + tgt_len <= src_len && !is_substring; i++) {

    // Sottoproblema: verifico se la sottostringa tgt si trova in str a partire dalla posizione i-esima
    is_substring = 1; // Assumo che tgt sia sottostringa fino a prova contraria
    for (j = 0; j < tgt_len && is_substring; j++) { // Scorro ogni carattere di tgt; dovro' confrontarlo con il carattere (i+j)-esimo di src
      if(src[i+j] != tgt[j]) { // Se i caratteri non corrispondono
        is_substring = 0; // Ho dimostrato che tgt non si trova in str a partire dalla posizione i-esima (e posso fermarmi)
      }
    }
    // Fine sottoproblema: se is_substring e' 0 (FALSE), ho dimostrato che tgt NON si trova in str a partire dalla posizione i-esima (per cui continuo)
    //                     se is_substring e' 1 (TRUE), ho dimostrato che tgt si trova in str a partire dalla posizione i-esima, dunque ho dimostrato che e' sottostringa (e posso uscire)
  }
  // A questo punto, is_substring indica se tgt e' sottostringa di src. In caso positivo, la stringa si trova in posizione i-1 (perche' il ciclo for effettua comunque l'incremento)

  // Stampa a video del risultato
  if(is_substring) {
    printf("La stringa \"%s\" contiene la sottostringa \"%s\" alla posizione %d", src, tgt, i-1);
  } else {
    printf("La stringa \"%s\" NON contiene la sottostringa \"%s\"", src, tgt);
  }
  printf("\n");


  return 0;
}
