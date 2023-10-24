/*
 *  Es. 3
 *  Filtro a media mobile (versione con interi)
 */

#include<stdio.h>

/* Costanti */

#define C 4
#define R 5

/* Main (test delle funzioni) */

int main() {
  // Dichiarazione variabili
  int m_in[R][C] = {
      { 10,  28,  11,   1},
      { 50, 127,  55,   8},
      { 34, 200,  26,  53},
      { 48, 245,   0,  23},
      { 51,  53,  12,   0}
  };                          // Matrice input (pre-inizializzata per comodita', e' possibile altrimenti leggerla da tastiera)
  int m_out[R][C];            // Matrice in cui memorizzare l'output
  int i, j, delta_i, delta_j; // Indici

  // Calcolo filtro a media mobile
  for(i = 0; i < R; i++) { // Per ogni riga di m_out
    for(j = 0; j < C; j++){ // Per ogni riga di m_out
      m_out[i][j] = 0; // Inizializzo la cella da riempire a 0 (IMPORTANTE se dopo utilizzo l'operatore +=)
      // Sono centrato in i,j --> considero le celle di m_in con indici i-1,i,i+1 e j-1,j,j+1
      for(delta_i = -1; delta_i <= 1; delta_i++) {
        for(delta_j = -1; delta_j <= 1; delta_j++) {
          if(i+delta_i >= 0 && i+delta_i < R && j+delta_j >= 0 && j+delta_j < C) { // Controllo che la cella considerata non sia fuori da m_in
            m_out[i][j] += m_in[i+delta_i][j+delta_j]; // Accumulo i valori nella sottomatrice 3x3 intorno a i,j
          }
          // Nota: il testo chiede di considerare le celle fuori da m_in come se valessero 0, quindi non serve gestire il ramo else
        }
      }
      m_out[i][j] /= 9; // Calcolo la media
    }
  }
  
  // Visualizzazione risultati

  printf("Matrice iniziale:\n\n");
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      printf("% 5d", m_in[i][j]);
    }
    printf("\n");
  }
  printf("Matrice risultante:\n\n");
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      printf("% 5d", m_out[i][j]);
    }
    printf("\n");
  }

  return 0;
}
