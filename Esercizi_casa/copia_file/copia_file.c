#include <stdio.h>

int main(int argc, char *argv[])
{

    if (argc != 3)
    { // voglio tre argomenti(file 1 e file 2 + nome del file corrente)
        printf("usage: copia file1 file2");
        return -1;
    }

    FILE *fileIn;
    FILE *fileOut;
    fileIn = fopen(argv[1], "r"); // passo nome del file e modalità

    if (fileIn == NULL)
    {

        printf("Impossibile aprire il %s", argv[1]);
        return -1; // se metto l'else posso evitarlo
    }
    else
    {

        fileOut = fopen(argv[2], "w");

        if (fileOut == NULL)
        {

            printf("Impossibile aprire il %s", argv[2]);
            return -1; // se metto l'else posso evitarlo
        }
        else
        {
            char c = 0;
            while (!feof(fileIn))
            {
                c = fgetc(fileIn);
                fputc(c, fileOut); // prima il carattere e poi il puntatore;
            }

            fclose(fileOut);
        }

        fclose(fileIn);
    }

    return 0;
}