/* Esercizio 2 – Temperature

Scrivere un programma che:
• chiede all'utente di inserire le misure della temperatura corporea di un paziente rilevate nell'arco
di 7 giorni e salva l'input in un array;
• stampa i risultati sotto forma di tabella con allineamento a destra;
• stampa accanto ai risultati un istogramma con allineamento a sinistra (un * per ogni valore di
temperatura superiore a 34 con approssimazione per difetto);
• calcola la temperatura media, massima e minima.

Esempio:
GIORNO VALORE ISTOGRAMMA
     1   37.8 ***
     2   40.6 ******

Utilizzare il costrutto #define per definire la durata del periodo di osservazione del paziente (7 giorni).
N.B.: nel caso di costanti definite con #define per convenzione si consiglia di usare nomi
di costante scritti tutti con caratteri maiuscoli per distinguerle dalle variabili.*/

#include <stdio.h>

#define TEMP_MEDIA 34
#define GIORNI 7

typedef int contatori;
typedef int controllo;

int main()
{
    float dati[GIORNI];
    contatori i, j;
    controllo num_ast;

    for (i = 0; i < GIORNI; i++)
    {
        printf("Inserisci i dati della temperatura relativa al %d° giorno: ", i + 1);
        scanf("%f", &dati[i]);
    }

    printf("GIORNO  Valore  Istogramma\n");

    for (i = 0; i < GIORNI; i++)
    {
        num_ast = (int)dati[i] - TEMP_MEDIA;
        printf("%6d%8.1f  ", i + 1, dati[i]);
        for (j = 0; j < num_ast; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}