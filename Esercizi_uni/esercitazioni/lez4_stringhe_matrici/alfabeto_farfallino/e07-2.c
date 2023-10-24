/*
 *  Es. 2
 *  Alfabeto farfallino
 */

#include <stdio.h>
#include <string.h>

#define MAXSTR 100

int main() {
  // Dichiarazione variabili
  char str_in[MAXSTR+1];     // Stringa letta da input
  char str_out[3*MAXSTR+1];  // Stringa in alfabeto farfallino (caso pessimo: str_in e' piena di sole vocali --> str_out = 3*len(str_in), +1 per terminatore)
  int i;                     // Indice per scorrere str_in
  int j;                     // Indice per scorrere str_out
  int len;                   // Lunghezza della stringa in input
  
  // Lettura da tastiera di una stringa terminata da 'a capo' (non da 'spazio')
  printf("Inserire stringa di max %d caratteri: \n", MAXSTR) ;
  gets(str_in);

  // Calcolo lunghezza stringa di input
  len = strlen(str_in);

  // Idea: analogo a Esercizio 2, ma:
  //       - Scorro str_in con i da 0 a lunghezza stringa (invece di controllare posizione di \0)
  //       - Ogni volta che scrivo in str_out, aggiorno j
  //         Idea: j indica sempre la prossima casella vuota in cui posso scrivere
  //       - Utilizzo il costrutto switch invece che if
  for(i = 0, j = 0; i < len; i++) {   // da inizio a fine stringa (i = 0 ... len-1)
    str_out[j] = str_in[i];         // Copio carattere corrente (sia per consonante che vocale)
    j++;                            // Aggiorno j affinche' punti alla prossima casella libera
    switch(str_in[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        // Switch: se si verifica uno dei casi sopra (a,e,i,o,u), eseguo queste istruzioni
        str_out[j] = 'f';       // Aggiungo f in posizione successiva
        j++;                    // Aggiorno j affinche' punti alla prossima casella libera
        str_out[j] = str_in[i]; // Copio la vocale anche nella posizione successiva
        j++;                    // Aggiorno j affinche' punti alla prossima casella libera
        break;                  // Esco dallo switch
                                // IMPORTANTE: lo switch richiede il break a fine blocco di
                                //             istruzioni
                                // NB: unica situazione in cui il break e' concesso
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        // Switch: se si verifica uno dei casi sopra (A,E,I,O,U), eseguo queste istruzioni
        str_out[j] = 'F';       // Aggiungo f in posizione successiva
        j++;                    // Aggiorno j affinche' punti alla prossima casella libera
        str_out[j] = str_in[i]; // Copio la vocale anche nella posizione successiva
        j++;                    // Aggiorno j affinche' punti alla prossima casella libera
        break;                  // Esco dallo switch
                                // IMPORTANTE: lo switch richiede il break a fine blocco di
                                //             istruzioni
                                // NB: unica situazione in cui il break e' concesso
    }
  }
  str_out[j] = '\0';                  // Aggiungo il terminatore alla fine di str_out
                                      // IMPORTANTE: ricordarsi sempre, altrimenti non e' una
                                      //             stringa ben formata
  
  // Stampa a video della stringa originale
  printf("Stringa originale:\n");
  puts(str_in);
  // Stampa a video della stringa modificata
  printf("\nStringa in alfabeto farfallino:\n");
  puts(str_out);
  
  printf("\n");

  return 0;
}

