#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 50

int main()
{
    FILE *file;

    char id_scelto[DIM], id_totali[7][DIM], id_groupby[7][DIM];

    int ore[2], minuti[2];

    int i = 0, j = 0, numero_righe, controllo, cont = 0;

    int ora_inziale[DIM], minuto_iniziale[DIM], ora_finale[DIM], minuto_finale[DIM], minuti_lavorati[DIM], ore_lavorate[DIM];

    file = fopen("/Users/andreavaccai/Coding/C/Esercizi_casa/minuti_lavorati/raccolta_attraversamenti.txt", "r");

    if (file == NULL)
    {
        printf("errore");
    }
    else
    {
        printf("Inserisci il codice del lavoratore da analizzare (0 per visionarli tutti): ");
        scanf("%s", id_scelto);

        while (!(feof(file)))
        {
            fscanf(file, "%d %d %s", &ore[i], &minuti[i], id_totali[i]);
            i++;
        }

        numero_righe = i;
        controllo = 0;
        if (strcmp(id_scelto, "0\0") != 0)
        {
            for (i = 0; i < numero_righe; i++)
            {
                if (strcmp(id_scelto, id_totali[i]) == 0)
                {
                    if (controllo == 0)
                    {
                        ora_inziale[0] = ore[i];
                        minuto_iniziale[0] = minuti[i];
                        controllo = 1;
                    }
                    else
                    {
                        ora_finale[0] = ore[i];
                        minuto_finale[0] = minuti[i];
                        i = numero_righe;
                    }
                }
            }

            minuti_lavorati[0] = 60 - minuto_iniziale[0] + minuto_finale[0];
            ore_lavorate[0] = ora_finale[0] - (ora_inziale[0] - 1);

            printf("Il lavoratore %s ha lavorato per %d ore e %d minuti", id_scelto, ore_lavorate[0], minuti_lavorati[0]);
        }
        /*else
        {
            for (i = 0; i < numero_righe; i++)
            {
                if (i == 0)
                {
                    for (j = 0; id_totali[i][j] != "\0"; j++)
                    {
                        id_groupby[i][j] = id_totali[i][j];
                        cont++;
                    }
                    ora_inziale[i] = ore[i];
                    minuto_iniziale[i] = minuti[i];
                }
                else
                {
                    controllo = 0;
                    for (j = 0; j < i && controllo == 0; j++)
                    {
                        if (strcmp(id_groupby[j], id_totali[i]) == 0)
                        {
                            controllo = j;
                        }
                    }
                    if (controllo == 0)
                    {
                        for (j = 0; id_totali[i][j] != "\0"; j++)
                        {
                            id_groupby[i][j] = id_totali[i][j];
                            cont++;
                        }
                        ora_inziale[i] = ore[i];
                        minuto_iniziale[i] = minuti[i];
                    }
                    else
                    {
                        ora_finale[controllo] = ore[i];
                        minuto_finale[controllo] = minuti[i];
                    }
                }
            }
        }
        for (i = 0; i < cont; i++)
        {
            minuti_lavorati[i] = 60 - minuto_iniziale[i] + minuto_finale[i];
            ore_lavorate[i] = ora_finale[i] - (ora_inziale[i] - 1);
            printf("Il lavoratore %s ha lavorato per %d ore e %d minuti\n", id_groupby[i], ore_lavorate[i], minuti_lavorati[i]);
        }*/
    }
    fclose(file);

    return 0;
}