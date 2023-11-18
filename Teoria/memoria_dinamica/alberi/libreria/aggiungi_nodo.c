#include "treelib.h"
#include <stdio.h>
#include <stdlib.h>

void aggiungi_nodo(nodo_t *radice)
{
    nodo_t *posizione, *temp, *temp2, *temp3;
    bool_t esci, errore;
    int scelta;

    posizione = ricerca_nodo(radice, 0);
    temp3 = posizione->primo_figlio;

    if (posizione == radice)
        printf("\nStai inserendo un ramo alla radice\n");

    temp = posizione->primo_figlio;
    temp2 = posizione;

    posizione->primo_figlio = (nodo_t *)malloc(sizeof(nodo_t));
    posizione = posizione->primo_figlio;

    posizione->el_successivo = temp;
    posizione->primo_figlio = NULL;
    posizione->padre = temp2;
    posizione->num_figli = 0;

    esci = False;
    while (esci == False)
    {

        printf("\nInserire l' elemento da attribuire al nuovo nodo: ");
        scanf("%d", &posizione->valore);

        posizione->num_figli++;

        errore = True;
        while (errore == True)
        {
            printf("\nVuoi inserire un altro nodo?\n1 SI\n2 NO\nScelta: ");
            scanf("%d", &scelta);
            if (scelta == 2)
            {
                esci = True;
                errore = False;
            }
            else if (scelta != 1)
                printf("Risposta non valida, riprova\n");
            else
            {
                posizione = posizione->padre;
                temp = posizione->primo_figlio;
                temp2 = posizione;

                posizione->primo_figlio = (nodo_t *)malloc(sizeof(nodo_t));
                posizione = posizione->primo_figlio;

                posizione->el_successivo = temp;
                posizione->primo_figlio = NULL;
                posizione->padre = temp2;
                posizione->num_figli = 0;

                errore = False;
            }
        }
    }
    nodo_t *last_el = trova_max(temp3);
    quicksort_lista(temp3, last_el);
}