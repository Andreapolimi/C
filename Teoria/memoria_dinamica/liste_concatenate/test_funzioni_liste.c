// crea un pseudo dictionary di python

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_MAX 50

typedef struct studente
{
    char *nome;
    char *cognome;
    int media;
    struct studente *successivo;
} lista_studenti;

typedef int contatore;

void inserisci_dati(lista_studenti *testa)
{
    contatore i = 0;

    while (testa != NULL)
    {
        testa->nome = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));
        testa->cognome = (char *)calloc(DIM_MAX, DIM_MAX * sizeof(char));

        printf("Inserisci il nome dello studente %d: ", i + 1);
        scanf("%s", testa->nome);
        testa->nome = (char *)realloc(testa->nome, (int)strlen(testa->nome) * sizeof(char));

        printf("Inserisci il cognome dello studente %d: ", i + 1);
        scanf("%s", testa->cognome);
        testa->cognome = (char *)realloc(testa->cognome, (int)strlen(testa->cognome) * sizeof(char));

        printf("Inserisci la media dello studente: ");
        scanf("%d", &(testa->media));

        testa = testa->successivo;
        i++;
    }
}

void stampa_lista(lista_studenti *testa)
{
    contatore i = 0;

    while (testa != NULL)
    {
        printf("Studente %d\n", i + 1);
        printf("\tNome: %s\n", testa->nome);
        printf("\tCognome: %s\n", testa->cognome);
        printf("\tMedia: %d\n", testa->media);
        testa = testa->successivo;
        printf("\n");
        i++;
    }
}

int main()
{
    lista_studenti *studente1;
    lista_studenti *studente2;
    lista_studenti *studente3;

    lista_studenti *testa = studente1;

    // allocazione memoria ai puntatori
    studente1 = (lista_studenti *)calloc(1, sizeof(lista_studenti));
    studente2 = (lista_studenti *)calloc(1, sizeof(lista_studenti));
    studente3 = (lista_studenti *)calloc(1, sizeof(lista_studenti));

    // collego i miei dati tra loro
    studente1->successivo = studente2;
    studente2->successivo = studente3;
    studente3->successivo = NULL;

    testa = studente1;

    inserisci_dati(testa);

    stampa_lista(testa);

    return 0;
}