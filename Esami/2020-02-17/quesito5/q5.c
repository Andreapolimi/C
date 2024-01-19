#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 26

int *CalcolaFrequenze(FILE *ptr_file, char *seq)
{
    int *array_frequenze = malloc((int)strlen(seq) * sizeof(int));
    int i, inserito;
    char campione;

    while (!feof(ptr_file))
    {
        inserito = 0;
        campione = fgetc(ptr_file);
        for (i = 0; i < (int)strlen(seq) && inserito == 0; i++)
            if (campione == seq[i])
            {
                array_frequenze[i]++;
                inserito = 1;
            }
    }

    return array_frequenze;
}

int main(int argc, char *argv[])
{
    char seq[MAX_CHAR];
    FILE *ptr_file = fopen(argv[1], "r");
    int i, *array_frequenze;

    printf("Inserire la sequenza (max 26 caratteri): ");
    scanf("%s", seq);
    array_frequenze = CalcolaFrequenze(ptr_file, seq);
    for (i = 0; i < (int)strlen(seq); i++)
        printf("%c: %d\n", seq[i], array_frequenze[i]);

    return 0;
}