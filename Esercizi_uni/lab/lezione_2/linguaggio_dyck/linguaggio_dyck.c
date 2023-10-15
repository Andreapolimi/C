/*Esercizio 4 – Linguaggio di Dyck

Nella teoria dei linguaggi formali il linguaggio di Dyck consiste in stringhe bilanciate di parentesi quadre ‘[‘ e ‘]’.
Codificare un programma C che sappia riconoscere se una stringa inserita dall’utente appartiene al linguaggio di Dyck o meno,
e che stampi a video il risultato del controllo.

Esempio: La stringa [[[][]][]] appartiene al linguaggio di Dyck.
La stringa [[[]][]]]] non appartiene al linguaggio di Dyck.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_MAX 50

typedef int contatori;
typedef enum controllo
{
    False,
    True
} bool;

int main()
{
    char *stringa;
    contatori i = 0, j = 0;
    bool esci = False;

    stringa = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));

    printf("Inserisci la stringa da controllare: ");
    scanf("%[^\n]s", stringa);

    stringa = (char *)realloc(stringa, ((int)strlen(stringa) + 1) * sizeof(char));

    while (stringa[i] != '\0' && j >= 0 && esci == False)
    {
        if (stringa[i] == '[')
            j++;
        else
        {
            if (stringa[i] == ']')
                j--;
            else
            {
                printf("Presente carattere non appartenente al linguaggio di Dyck");
                esci = True;
            }
        }
        i++;
    }

    if (j == 0)
        printf("Stringa appartenente al linguaggio di Dyck");
    else
    {
        if (esci == False)
            printf("Stringa non appartenente al linguaggio di Dyck");
    }

    free(stringa);

    return 0;
}