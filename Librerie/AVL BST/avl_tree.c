#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

int main()
{
    tree_t *radice = NULL;
    int azione;
    bool esci = false;

    while (!esci)
    {
        printf("Cosa vuoi fare?\n1 INSERISCI NODO\n2 MODIFICA NODO\n3 ELIMINA NODO\n4 STAMPA\n5 TERMINA: ");
        scanf("%d", &azione);
        if (azione == 1)
            radice = Inserimento(radice);
        else if (azione == 2)
            radice = Modifica(radice);
        else if (azione == 3)
            radice = Rimozione(radice);
        else if (azione == 4)
            Stampa(radice);
        else
            esci = true;
    }

    return 0;
}