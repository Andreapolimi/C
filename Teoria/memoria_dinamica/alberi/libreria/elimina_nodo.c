#include "treelib.h"
#include <stdio.h>
#include <stdlib.h>

void elimina_nodo(nodo_t *radice)
{
    nodo_t *posizione, *temp, *temp2;
    bool_t esci;

    posizione = ricerca_nodo(radice, 0);

    if (posizione == radice)
        printf("\nNon puoi eliminare la radice\n\n");
    else
    {
        temp = posizione->padre->primo_figlio;
        esci = False;
        while (esci == False)
        {
            if (temp == posizione)
            {
                temp->padre->primo_figlio = temp->el_successivo;
                free(temp);
                esci = True;
            }
            else if (temp->el_successivo == posizione)
            {
                temp2 = temp->el_successivo;
                temp->el_successivo = temp->el_successivo->el_successivo;
                free(temp2);
                esci = True;
            }
            else
                temp = temp->el_successivo;
        }
    }
}