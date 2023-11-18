#include <stdio.h>
#include <stdlib.h>
#include "libreria/treelib.h"

int main()
{
    nodo_t *radice;
    bool_t termina, errore, errore2;
    int azione;

    radice = (nodo_t *)malloc(sizeof(nodo_t));
    radice->padre = NULL;
    radice->el_successivo = NULL;
    radice->primo_figlio = NULL;
    radice->valore = 0;
    radice->num_figli = 0;

    termina = False;
    while (termina == False)
    {
        errore = True;
        while (errore == True)
        {
            printf("\nCosa vuoi fare?\n1 AGGIUNGI NODO\n2 MODIFICA NODO\n3 ELMINA NODO\n4 STAMPA ALBERO\nScelta: ");
            scanf("%d", &azione);
            if (azione == 1)
            {
                errore = False;
                aggiungi_nodo(radice);
            }
            else if (azione == 2)
            {
                errore = False;
                modifica_nodo(radice);
            }
            else if (azione == 3)
            {
                errore = False;
                elimina_nodo(radice);
            }
            else if (azione == 4)
            {
                errore = False;
                stampa_albero(radice, 0);
            }
            else
                printf("Scelta non valida, riprova\n");
        }
        errore2 = True;
        while (errore2 == True)
        {
            printf("\nVuoi fare qualcos'altro?\n1 SI\n2 NO\nScelta: ");
            scanf("%d", &azione);
            if (azione == 2)
            {
                errore2 = False;
                termina = True;
            }
            else
            {
                if (azione == 1)
                    errore2 = False;
                else
                    printf("Scelta non valida, riprova\n");
            }
        }
    }

    printf("\nCompilazione terminata con successo");
    return 0;
}