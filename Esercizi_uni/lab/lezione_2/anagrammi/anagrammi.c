/*Esercizio 5 – Anagrammi

Si codifichi un programma C che legge due stringhe inserite dall'utente che rappresentano due parole e verifica
 se le parole sono anagrammi, cioè se è possibile ottenere l’una dall’altra tramite permutazione delle loro lettere.
 Stampa infine a schermo il risultato della verifica.

Esempio: Le parole POLENTA e PENTOLA sono anagrammi Le parole TAPPO e PATTO non sono anagrammi*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM_MAX 50

typedef int contatori;
typedef enum BOOL
{
    False,
    True
} bool;

int main()
{
    contatori i, j, k;
    bool esci_for, esci_controllo = False;
    int dim_stringa, lettere_uguali = 0;
    char *stringa_iniziale, *stringa_verifica, *stringa_appoggio;

    stringa_iniziale = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));

    printf("Inserisci la prima stringa da prendere come riferimento: ");
    scanf("%s", stringa_iniziale);

    dim_stringa = strlen(stringa_iniziale) + 1;
    stringa_iniziale = (char *)realloc(stringa_iniziale, dim_stringa * sizeof(char));
    stringa_verifica = (char *)calloc(dim_stringa, dim_stringa * sizeof(char));

    printf("Inserisci la seconda stringa per verificare se è un anagramma della prima: ");
    scanf("%s", stringa_verifica);

    if ((int)strlen(stringa_iniziale) != (int)strlen(stringa_verifica))
        esci_controllo = True;
    else
        esci_controllo = False;

    while (esci_controllo == False)
    {
        stringa_appoggio = (char *)calloc(dim_stringa, dim_stringa * sizeof(char));
        strcpy(stringa_appoggio, stringa_verifica);

        for (i = 0; stringa_iniziale[i] != '\0'; i++)
        {
            esci_for = False;
            for (j = 0; stringa_verifica[j] != '\0' && esci_for == False; j++)
            {
                if (stringa_iniziale[i] == stringa_verifica[j])
                {
                    lettere_uguali++;
                    for (k = j; stringa_appoggio[k] != '\0'; k++)
                    {
                        stringa_appoggio[k] = stringa_appoggio[k + 1];
                    }
                    stringa_appoggio = (char *)realloc(stringa_appoggio, (strlen(stringa_appoggio) + 1) * sizeof(char));
                    esci_for = True;
                }
            }
        }
        if (i == strlen(stringa_iniziale))
            esci_controllo = True;

        free(stringa_appoggio);
    }

    if (lettere_uguali == (dim_stringa - 1))
        printf("La parola %s e' un anagramma della parola %s", stringa_verifica, stringa_iniziale);
    else
        printf("La parola %s non e' un anagramma della parola %s", stringa_verifica, stringa_iniziale);

    free(stringa_iniziale);
    free(stringa_verifica);

    return 0;
}