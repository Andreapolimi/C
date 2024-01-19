#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50

typedef struct node
{
    int freq;
    char parola[MAX_CHAR];
    struct node *next;
} node_t;

node_t *CreaNodo(char *campione)
{
    node_t *new_node = malloc(sizeof(node_t));

    strcpy(new_node->parola, campione);
    new_node->freq = 1;
    new_node->next = NULL;

    return new_node;
}

node_t *Frequenza(FILE *ptr_file)
{
    node_t *testa = NULL, *ptr_lista, *new_node, *prec;
    char campione[MAX_CHAR];
    int inserito;

    while (!feof(ptr_file))
    {
        fscanf(ptr_file, "%s", campione);
        if ((int)strlen(campione) >= 2)
        {
            if (testa == NULL)
                testa = CreaNodo(campione);
            else
            {
                ptr_lista = testa;
                prec = NULL;
                inserito = 0;

                while (!inserito && ptr_lista != NULL)
                {
                    if (strcmp(ptr_lista->parola, campione) > 0)
                    {
                        new_node = CreaNodo(campione);
                        if (prec != NULL)
                            prec->next = new_node;
                        new_node->next = ptr_lista;
                        inserito = 1;
                    }
                    else if (strcmp(ptr_lista->parola, campione) < 0)
                    {
                        prec = ptr_lista;
                        ptr_lista = ptr_lista->next;
                    }
                    else
                    {
                        ptr_lista->freq++;
                        inserito = 1;
                    }
                }
                if (!inserito)
                {
                    new_node = CreaNodo(campione);
                    prec->next = new_node;
                }
            }
        }
    }
    return testa;
}

int Statistiche(node_t *ptr_lista, node_t **min, node_t **max)
{
    int num_parole = 0;

    while (ptr_lista != NULL)
    {
        if ((*min) == NULL)
        {
            *min = ptr_lista;
            *max = ptr_lista;
        }
        else if ((*min)->freq > ptr_lista->freq)
            *min = ptr_lista;
        else if ((*max)->freq < ptr_lista->freq)
            *max = ptr_lista;
        num_parole++;
        ptr_lista = ptr_lista->next;
    }
    return num_parole;
}

void StampaLista(node_t *temp)
{
    while (temp != NULL)
    {
        printf("%s %d->", temp->parola, temp->freq);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

int main(int argc, char *argv[])
{
    node_t *lista, *min = NULL, *max = NULL;
    FILE *ptr_file = fopen(argv[1], "r");
    int num_parole;

    printf("\n");

    lista = Frequenza(ptr_file);
    StampaLista(lista);

    num_parole = Statistiche(lista, &min, &max);
    printf("Numero di parole: %d\nParola con frequenza minima = %d: %s\nParola con frequenza massima = %d: %s",
           num_parole, min->freq, min->parola, max->freq, max->parola);

    fclose(ptr_file);

    return 0;
}