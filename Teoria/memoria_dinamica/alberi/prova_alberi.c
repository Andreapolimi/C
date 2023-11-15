#include <stdio.h>
#include <stdlib.h>

typedef struct albero
{
    int valore;
    struct albero *padre;
    struct albero *el_successivo;
    struct albero *primo_figlio;
} nodo_t;
typedef int cont_t;
typedef enum
{
    False,
    True
} bool_t;

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

void aggiungi_nodo(nodo_t *radice)
{
    nodo_t *posizione, *temp, *temp2;

    posizione = ricerca_nodo(radice, 0);

    if (posizione == radice)
        printf("\nStai inserendo un ramo alla radice\n");

    temp = posizione->primo_figlio;
    temp2 = posizione;

    posizione->primo_figlio = (nodo_t *)malloc(sizeof(nodo_t));
    posizione = posizione->primo_figlio;

    posizione->el_successivo = temp;
    posizione->primo_figlio = NULL;
    posizione->padre = temp2;

    printf("\nInserire l' elemento da attribuire al nuovo nodo: ");
    scanf("%d", &posizione->valore);
}

void modifica_nodo(nodo_t *radice)
{
    nodo_t *posizione;

    posizione = ricerca_nodo(radice, 0);

    if (posizione == radice)
        printf("\nStai modificando la radice\n");

    printf("\nInserire l' elemento da attribuire al nodo: ");
    scanf("%d", &posizione->valore);
}

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

void stampa_albero(nodo_t *posizione, int i)
{
    printf("\n");
    while (posizione != NULL)
    {
        for (int j = 0; j < i; j++)
            printf("\t");

        if (posizione->primo_figlio != NULL)
        {
            printf("%d", posizione->valore);
            printf("\n");
            stampa_albero(posizione->primo_figlio, i + 1);
        }
        else
            printf("%d\t", posizione->valore);
        posizione = posizione->el_successivo;
    }
    printf("\n");
}

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