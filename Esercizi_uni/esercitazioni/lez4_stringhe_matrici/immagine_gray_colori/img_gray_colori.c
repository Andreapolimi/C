#include <stdio.h>
#include <stdlib.h>

#define const_red 0.2989
#define const_green 0.5870
#define const_blue 0.1140

typedef int contatori;

typedef struct colori
{
    int red, green, blue;
} immagine_colori;

int main()
{
    contatori i, j;
    immagine_colori **img;
    int **matrice_gray;
    int col, righe;

    printf("Inserire le righe e le colonne della matrice rappresentante la tua immagine:\n");
    scanf("%d", &righe);
    scanf("%d", &col);

    img = (immagine_colori **)calloc(righe, righe * sizeof(immagine_colori *));
    matrice_gray = (int **)calloc(righe, righe * sizeof(int *));

    for (i = 0; i < righe; i++)
    {
        img[i] = (immagine_colori *)calloc(col, col * sizeof(immagine_colori));
        matrice_gray[i] = (int *)calloc(col, col * sizeof(int));

        printf("\tInserire i valori della %d° riga\n", i + 1);
        for (j = 0; j < col; j++)
        {
            printf("\t%d° pixel:\n", j + 1);
            printf("\t\tRED: ");
            scanf("%d", &img[i][j].red);
            while (img[i][j].red < 0 || img[i][j].red > 255)
            {
                printf("Inserire un valore compreso tra 0 e 255, riprova\n\t\tRED: ");
                scanf("%d", &img[i][j].red);
            }
            printf("\t\tGREEN: ");
            scanf("%d", &img[i][j].green);
            while (img[i][j].green < 0 || img[i][j].green > 255)
            {
                printf("Inserire un valore compreso tra 0 e 255, riprova\n\t\tGREEN: ");
                scanf("%d", &img[i][j].green);
            }
            printf("\t\tBLUE: ");
            scanf("%d", &img[i][j].blue);
            while (img[i][j].blue < 0 || img[i][j].blue > 255)
            {
                printf("Inserire un valore compreso tra 0 e 255, riprova\n\t\tBLUE: ");
                scanf("%d", &img[i][j].blue);
            }

            matrice_gray[i][j] = const_red * img[i][j].red + const_green * img[i][j].green + const_blue * img[i][j].blue;
        }
    }

    for (i = 0; i < righe; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", matrice_gray[i][j]);
        }
        printf("\n");
    }
}