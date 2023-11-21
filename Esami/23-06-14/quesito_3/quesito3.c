#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RIGA 100

typedef struct hotel
{
    float voto_complessivo;
    char nome[MAX_RIGA];
} hotel_t;
typedef int cont_t;

float voto_hotel(char *nome_file)
{
    FILE *ptr_file;
    cont_t recensioni = 0;
    float media_s = 0, media_pu = 0, media_po = 0;
    int voto_s, voto_pu, voto_po;
    char buffer[MAX_RIGA];

    ptr_file = fopen(nome_file, "r");
    if (ptr_file == NULL)
    {
        printf("Apertura file %s fallita", nome_file);
        exit(1);
    }
    else
        printf("File %s aperto con successo\n\n", nome_file);

    fscanf(ptr_file, "%s", buffer);

    while (!feof(ptr_file))
    {
        fscanf(ptr_file, "%d %d %d", &voto_s, &voto_pu, &voto_po);
        media_s += voto_s;
        media_pu += voto_pu;
        media_po += voto_po;

        recensioni++;
    }
    media_s /= recensioni;
    media_pu /= recensioni;
    media_po /= recensioni;

    return media_s + media_pu + media_po;
}

hotel_t incubo(char *file_indice)
{
    hotel_t *array_hotel;
    FILE *ptr_file;
    cont_t indice_hotel;
    int indice_peggiore;

    ptr_file = fopen(file_indice, "r");
    if (ptr_file == NULL)
    {
        printf("Apertura file %s fallita", file_indice);
        exit(1);
    }
    else
        printf("File %s aperto con successo\n\n", file_indice);

    array_hotel = (hotel_t *)malloc(sizeof(hotel_t));
    indice_hotel = 1;
    while (!feof(ptr_file))
    {
        array_hotel = (hotel_t *)realloc(array_hotel, indice_hotel * sizeof(hotel_t));
        fscanf(ptr_file, "%s", array_hotel[indice_hotel - 1].nome);

        array_hotel[indice_hotel - 1].voto_complessivo = voto_hotel(array_hotel[indice_hotel - 1].nome);

        if (indice_hotel == 1)
            indice_peggiore = indice_hotel - 1;
        else if (array_hotel[indice_hotel].voto_complessivo < array_hotel[indice_peggiore].voto_complessivo)
            indice_peggiore = indice_hotel - 1;

        indice_hotel++;
    }

    return array_hotel[indice_peggiore];
}

int main(int argc, char *argv[])
{
    hotel_t peggiore;

    peggiore = incubo(argv[1]);
    printf("Hotel peggiore: %s con voto complessivo pari a %f", peggiore.nome, peggiore.voto_complessivo);

    return 0;
}