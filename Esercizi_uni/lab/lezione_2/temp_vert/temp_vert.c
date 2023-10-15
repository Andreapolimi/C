/*Esercizio 3 – Temperature Verticali

Modificare l'esercizio precedente in modo che i risultati vengano stampati sotto forma di un istogramma verticale,
usando come carattere un asterisco (inserire un * per ogni valore di temperatura superiore a 34 con approssimazione per difetto),
scrivendo in basso il valore relativo a ogni colonna.

Esempio:

    *
*   *     *
*   *  *  *
*   *  *  *
39 40 36 40
*/

#include <stdio.h>
#include <stdlib.h>

#define TEMP_RIFERIMENTO 34
#define GIORNI 7

typedef int contatori;
typedef int controllo;

int main()
{
    float dati[GIORNI];
    contatori i, j;
    controllo num_ast, max = 0;
    char *vett_ast[GIORNI];

    for (i = 0; i < GIORNI; i++)
    {
        printf("Inserisci i dati della temperatura relativa al %d° giorno: ", i + 1);
        scanf("%f", &dati[i]);

        if (max < (int)dati[i])
            max = dati[i];
    }

    max -= TEMP_RIFERIMENTO;

    for (i = 0; i < GIORNI; i++)
        vett_ast[i] = (char *)calloc(max, max * sizeof(char));

    for (i = 0; i < GIORNI; i++)
    {
        num_ast = (int)dati[i] - 34;
        for (j = 0; j < num_ast; j++)
        {
            vett_ast[i][j] = '*';
        }
    }

    for (j = max; j >= 0; j--)
    {
        for (i = 0; i < GIORNI; i++)
        {
            if (vett_ast[i][j] == '*')
                printf("\t*");
            else
                printf("\t ");
        }
        printf("\n");
    }

    for (i = 0; i < GIORNI; i++)
    {
        printf("\t%0.1f", dati[i]);
    }

    for (i = 0; i < GIORNI; i++)
        free(vett_ast[i]);

    return 0;
}