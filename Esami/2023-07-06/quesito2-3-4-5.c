#include <stdio.h>
#include <stdlib.h>

#define INDEX_FILE_TXT 1

typedef struct nodo
{
    int val, row, col;
    struct nodo *next;
} nodo_t;
typedef enum bool
{
    False,
    True
} bool_t;
typedef int cont_t;

nodo_t *InserisciInTesta(nodo_t *testa_precedente, int val, int row, int col)
{
    nodo_t *nuova_testa;

    nuova_testa = (nodo_t *)malloc(sizeof(nodo_t));
    nuova_testa->row = row;
    nuova_testa->col = col;
    nuova_testa->val = val;
    nuova_testa->next = testa_precedente;

    return nuova_testa;
}

nodo_t *Dominante(nodo_t *testa, int n, int m, int **mat)
{
    bool_t fine_controllo;
    cont_t i, j, k, l;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < m - 1; j++)
        {
            fine_controllo = False;
            for (k = i + 1; k < n && fine_controllo == False; k++)
            {
                for (l = j + 1; l < m && fine_controllo == False; l++)
                {
                    if (mat[i][j] <= mat[k][l])
                        fine_controllo = True;
                }
            }
            if (fine_controllo == False)
                testa = InserisciInTesta(testa, mat[i][j], i, j);
        }
    }
    return testa;
}

void StampaLista(nodo_t *temp)
{
    while (temp != NULL)
    {
        printf("%d %d %d\n", temp->val, temp->row, temp->col);
        temp = temp->next;
    }
}

nodo_t *RicercaNodo(nodo_t *temp, nodo_t *ptr_min)
{
    if (temp != ptr_min)
    {
        while (temp->next != ptr_min)
            temp = temp->next;
    }

    return temp;
}

nodo_t *MinimoInTesta(nodo_t *testa)
{
    nodo_t *ptr_min = testa, *temp = testa, *ptr_ptr_min = NULL;
    while (temp != NULL)
    {
        if (temp->val < ptr_min->val)
            ptr_min = temp;

        temp = temp->next;
    }
    ptr_ptr_min = RicercaNodo(testa, ptr_min);
    temp = ptr_min->next;
    ptr_min->next = testa;
    ptr_ptr_min->next = temp;

    return ptr_min;
}

nodo_t *Ordina(nodo_t *testa)
{
    testa = MinimoInTesta(testa);
    if (testa->next != NULL)
        testa->next = MinimoInTesta(testa->next);

    return testa;
}

int main(int argc, char *argv[])
{
    nodo_t *testa = NULL;
    int n, m, val_extra;
    int **mat;
    FILE *ptr_file;
    cont_t i, j;

    ptr_file = fopen(argv[INDEX_FILE_TXT], "r");
    if (ptr_file == NULL)
    {
        printf("Lettura file testuale falllita\n");
        exit(1);
    }
    else
        printf("File letto con successo\n\n");

    fscanf(ptr_file, "%d %d", &n, &m);
    mat = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++)
            fscanf(ptr_file, "%d", &mat[i][j]);

        val_extra = fgetc(ptr_file);
        while (val_extra != '\n' && val_extra != EOF)
            val_extra = fgetc(ptr_file);
    }

    testa = Dominante(testa, n, m, mat);
    free(mat);

    StampaLista(testa);

    printf("\n");
    testa = Ordina(testa);
    StampaLista(testa);

    fclose(ptr_file);

    return 0;
}