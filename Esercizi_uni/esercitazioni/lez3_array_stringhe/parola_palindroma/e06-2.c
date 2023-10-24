/*
 * Es. 2
 * Parola palindroma
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
  // Dichiarazione variabili
  char str[MAX+1];  // parola
  int i, j;         // indici cicli
  int palindroma;   // flag (sentinella): indica se str e' palindroma

  // Lettura parola da tastiera
  printf("Inserire parola: ");
  scanf("%s", str); // NOTA: ricordarsi che scanf acquisisce la stringa fino al primo spazio

  // Idea: mantendo due cursori i e j. i scansiona la stringa dall'inizio verso dx; j dalla fine verso sx.
  //       Controllo se il primo carattere e' uguale all'ultimo, poi sposto entrambi gli indici 
  //       verso l'interno e continuo. Gli indici si incontrano al centro.
  //       Se la parola non e' palindroma, allora trovero' una coppia di caratteri non uguali.
  //       Se termino senza trovare coppie di caratteri non uguali, allora e' palindroma.

  palindroma = 1; // Fino a prova contraria, assumo che str sia palindroma --> palindroma = 1 (TRUE)
  for(i=0, j=strlen(str)-1; i < j && palindroma; i++, j--) { // i parte dal primo carattere e si sposta verso dx;
                                                           // j parte dall'ultimo carattere e si sposta in contemporanea verso sx
                                                           // i e j si incontrano in centro (e termino); 
                                                           // termino subito se dimostro che la parola non e' palindroma
    if(str[i] != str[j]) { // Se i due caratteri indicizzati da i e j non sono uguali
      palindroma = 0;      // Allora ho dimostrato che str non e' palindroma --> palindroma = 0 (FALSE) e esco dal ciclo
    }
  }
  // A questo punto, se palindroma vale 0 (FALSE) allora sono entrato nell'if sopra, i.e., ho dimostrato che str non e' palindroma;
  //                 se palindroma vale 1 (TRUE) allora non sono mai entrato nell'if sopra, quindi str e' palindroma.

  // Stampa a video del risultato
  if(palindroma) {
    printf("La parola '%s' e' palindroma\n", str);
  } else {
    printf("La parola '%s' NON e' palindroma\n", str);
  }

  return 0;
}
