#include "lib_registro_uni.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

char cartella_corsi[] = "file_bin";
char file_corsi[] = "file_bin/corsi.bin";

char *rami[] = {"corso", "anno", "scaglione", "studente"};
char *rami_plurali[] = {"corsi", "anni", "scaglioni", "studenti"};

node_t *ricerca_nodo(node_t *ptr_nodo, char *cartella_ricerca)
{
    bool_t trovato = False;
    while (ptr_nodo != NULL && trovato == False)
    {
        if (strcmp(ptr_nodo->cartella, cartella_ricerca) == 0)
            trovato = True;
        else
            ptr_nodo = ptr_nodo->next;
    }

    return ptr_nodo;
}

node_t *richiesta_collocazione(node_t *ptr_nodo, int i)
{
    int risposta, byte;
    char extra, identificativo_trovato[MAX_RIGA], file_complessivo[MAX_RIGA], file_specifico[MAX_RIGA], cartella_ricerca[MAX_RIGA];
    FILE *ptr_file_ricerca;
    bool_t esci, errore, trovato;
    node_t *temp;

    printf("In quale %s vuoi cercare?\nInserire il corrispettivo identificativo: ", rami[i]);
    scanf("%s", ptr_nodo->identificativo);

    if ((ptr_file_ricerca = fopen(ptr_nodo->file_complessivo, "r")) == NULL)
    {
        printf("Lettura file %s fallita\n", ptr_nodo->file_complessivo);
    }
    else
        printf("Lettura file %s effettuata con successo\n", ptr_nodo->file_complessivo);

    esci = False;
    while (!feof(ptr_file_ricerca) && esci == False)
    {
        byte = ftell(ptr_file_ricerca);
        fscanf(ptr_file_ricerca, "%s", identificativo_trovato);

        extra = 0;
        while (extra != '\n')
            extra = fgetc(ptr_file_ricerca);

        if (ptr_nodo->identificativo == identificativo_trovato)
        {
            ptr_nodo->byte = byte;
            esci = True;
        }
    }

    printf("Vuoi analizzare un %s specifico?\n1 SI\n2 NO\n Risposta: ", rami[i + 1]);
    scanf("%d", &risposta);

    errore = True;
    while (errore)
    {
        if (risposta == 1)
        {
            // crea nuova variabile cartella
            strcat(cartella_ricerca, "/");
            strcat(cartella_ricerca, identificativo_trovato);

            // ricerca nodo se esiste già
            trovato = ricerca_nodo(ptr_nodo->first_child, cartella_ricerca);

            // crea nuovo nodo di ricerca se non esiste
            if (trovato != NULL)
                ptr_nodo = trovato;
            else
            {
                temp = ptr_nodo->first_child;
                ptr_nodo->first_child = (node_t *)malloc(sizeof(node_t));

                ptr_nodo->first_child->next = temp;

                temp = ptr_nodo;
                ptr_nodo = ptr_nodo->first_child;
                ptr_nodo->first_child = NULL;
                ptr_nodo->padre = temp;
                strcpy(ptr_nodo->cartella, cartella_ricerca);

                // costruzione percorso file complessivo
                strcpy(ptr_nodo->file_complessivo, ptr_nodo->cartella);
                strcat(ptr_nodo->file_complessivo, "/");
                strcat(ptr_nodo->file_complessivo, rami_plurali[i + 1]);
                strcat(ptr_nodo->file_complessivo, ".bin");

                // costruzione percorso file specifico (se serve)
                if (i != 0 && i != 3)
                {
                    strcpy(ptr_nodo->file_specifico, ptr_nodo->cartella);
                    strcat(ptr_nodo->file_specifico, "specifiche.bin");
                }
                else
                    strcpy(ptr_nodo->file_specifico, NULL);
            }

            // creazione cartella e file se non esistono ancora

            ptr_nodo = richiesta_collocazione(ptr_nodo, i + 1);
            errore = False;
        }
        else if (risposta != 2)
            printf("Risposta non valida, riprova\n");
        else
            errore = False;
    }

    return ptr_nodo;
}

node_t *acquisisci_file(node_t *nodo_collocazione)
{
    FILE *ptr_file;

    nodo_collocazione = (node_t *)malloc(sizeof(node_t));
    nodo_collocazione->padre = NULL;
    nodo_collocazione->first_child = NULL;
    nodo_collocazione->next = NULL;
    strcpy(nodo_collocazione->file_complessivo, file_corsi);
    strcpy(nodo_collocazione->file_specifico, NULL);
    strcpy(nodo_collocazione->cartella, cartella_corsi);

    nodo_collocazione = richiesta_collocazione(nodo_collocazione, 0);

    return nodo_collocazione;
}