#include "treelib.h"
#include <stdio.h>

nodo_t *ricerca_nodo(nodo_t *posizione, int ramificazione)
{
    int scelta, valore_ricerca;
    bool_t errore, errore2, termina_ricerca;
    nodo_t *temp;

    if (posizione->primo_figlio != NULL)
    {
        errore = True;
        while (errore == True)
        {
            printf("\nVuoi operare con il nodo alla ramificazione %d?\n1 SI\n2 NO\nScelta:", ramificazione);
            scanf("%d", &scelta);
            if (scelta == 1)
                errore = False;
            else if (scelta == 2)
            {
                errore = False;
                ramificazione++;
                posizione = posizione->primo_figlio;
                errore2 = True;
                while (errore2 == True)
                {
                    temp = posizione;
                    printf("\nIndicare il valore del ramo da considereare: ");
                    scanf("%d", &valore_ricerca);
                    termina_ricerca = False;
                    while (temp != NULL && termina_ricerca == False)
                    {
                        if (temp->valore == valore_ricerca)
                            termina_ricerca = True;
                        else
                            temp = temp->el_successivo;
                    }
                    if (temp == NULL)
                        printf("Elemento inesistente, inserire un altro valore\n");
                    else
                        errore2 = False;
                }
                posizione = ricerca_nodo(temp, ramificazione);
            }
            else
            {
                printf("Scelta non valida, riprova\n");
            }
        }
    }

    return posizione;
}