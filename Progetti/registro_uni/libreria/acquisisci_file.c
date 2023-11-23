#include "lib_registro_uni.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

char *rami[] = {"corso", "anno", "scaglione", "studente"};

node_t *richiesta_collocazione(node_t *ptr_nodo, int i, char *file_ricerca, char *cartella)
{
    int risposta, byte;
    char identificativo_trovato[MAX_RIGA], extra;
    FILE *ptr_file_ricerca;
    bool_t esci, errore;

    printf("In quale %s vuoi cercare?\nInserire il corrispettivo identificativo: ", rami[i]);
    scanf("%s", ptr_nodo->identificativo);

    if ((ptr_file_ricerca = fopen(file_ricerca, "r")) == NULL)
    {
        printf("Lettura file %s fallita\n", file_ricerca);
        exit(1);
    }
    else
        printf("Lettura file %s effettuata con successo", file_ricerca);

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
            strcat(cartella, "/");
            strcat(cartella, identificativo_trovato);

            strcpy(file_ricerca, cartella);
            strcat(file_ricerca, "/file_");
            strcat(file_ricerca, rami[i + 1]);
            strcat(file_ricerca, ".txt");

            ptr_nodo = ptr_nodo->first_child;
            strcpy(ptr_nodo->file_specifico, file_ricerca);
            ptr_nodo = richiesta_collocazione(ptr_nodo, i + 1, file_ricerca, cartella);
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

    nodo_collocazione = richiesta_collocazione(nodo_collocazione, 0, "Corsi/corsi_totali.bin", "Corsi");

    ptr_file = fopen(nodo_collocazione->file_specifico)
}
