/* Su una scacchiera 8x8 sono posizionati due pezzi: il Re bianco e la Regina nera.
Si scriva un programma in linguaggio C che, acquisite le posizioni del Re e della Regina,
determini se la Regina è in posizione tale da poter mangiare il Re. Le posizioni dei due pezzi
sono identificate da mediante la riga e la colonna su cui si trovano, espresse come numeri
interi tra 1 e 8 */

#include <stdio.h>
#include <stdlib.h>

void Mangia(int r1, int c1, int r2, int c2)
{
    // verificare se è sulla stessa riga
    if (r1 == r2)
        printf("La regina si trova sulla stessa riga e può mangiare il re");
    else
    {
        // verificare se è sulla stessa colonna
        if (c1 == c2)
            printf("La regina è sulla stessa colonna e può mangiare il re");
        else
        {
            // verificare se è sulla diagonale
            if (abs(r1 - r2) == abs(c1 - c2))
                printf("La regina è sulla stessa diagonale");
            else
                printf("La regina non può mangiare il re");
        }
    }
}

int main()
{
    int rowking, colking, rowqueen, colqueen;

    // Richiesta in input delle posizioni del re e della regina
    do
    {
        printf("Inserisci la posizione del re (prima la riga e poi la colonna, da 1 a 8:\n)");
        scanf("%d", &rowking);
        scanf("%d", &colking);
        if (rowking < 1 || rowking > 8 || colking < 1 || colking > 8)
            printf("Valore della cella non valido\n");
    } while (rowking < 1 || rowking > 8 || colking < 1 || colking > 8);

    do
    {
        printf("Inserisci la posizione della regina (prima la riga e poi la colonna, da 1 a 8:\n)");
        scanf("%d", &rowqueen);
        scanf("%d", &colqueen);
        if (rowqueen < 1 || rowqueen > 8 || colqueen < 1 || colqueen > 8)
            printf("Valore della cella non valido\n");
        if (rowking == rowqueen && colking == colqueen)
            printf("Posizione non valida, inserirne una diversa da quella del re\n");
    } while ((rowqueen < 1 || rowqueen > 8 || colqueen < 1 || colqueen > 8) || (rowking == rowqueen && colking == colqueen));

    // Richiamo la funzione per vedere se la regina può mangiare o meno
    Mangia(rowking, colking, rowqueen, colqueen);

    return 0;
}