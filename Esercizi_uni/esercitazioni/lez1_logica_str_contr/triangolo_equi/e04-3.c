/*
 * Es. 1
 * Letti A,B,C (decimali)
 * Determinare se il triangolo ABC è: equilatero, isoscele, scaleno, rettangolo
 */

#include <stdio.h>

int main() {
  // Dichiarazione variabili
  float a, b, c;

  // lettura tastiera A,B,C
  printf("Inserire lato A: ");
  scanf("%f", &a);
  printf("Inserire lato B: ");
  scanf("%f", &b);
  printf("Inserire lato C: ");
  scanf("%f", &c);

  // Controllo equilatero, isoscele, scaleno
  if ( (a == b) && (b == c) ) { // Tutti i lati uguali (A == B == C)
    printf("Triangolo equilatero\n");
  } else { // Non sono tutti i lati uguali
    if ( (a == b) || (b == c) || (c == a) ) { // Solo 2 lati uguali
      printf("Triangolo isoscele\n");
    } else { // Tutti i lati diversi
      printf("Triangolo scaleno\n");
    }
  }

  // Controllo rettangolo
  // Teorema pitagora: A^2 + B^2 == C^2 || A^2 + C^2 == B^2 || B^2 + C^2 == A^2
  if ( (a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a) ) {
    printf("Triangolo rettangolo\n");
  }

  return 0;
}
