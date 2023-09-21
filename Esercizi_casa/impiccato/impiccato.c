/*
    main: creazione gioco (parola, parola vuota e numero di tentativi)
            + acquisizione lettere giocatore 2
    acquisizione lettera: controlla se la lettera è già stata usata, se no la aggiunge alla lista e fa procedere il programma
    controllo_lettera lettera: verifica se la lettera è presente, se si esegue aggiunta lettera
*/

#include <stdio.h>
#define dim 50

int main()
{
    int tent_max, i = 0, j, vittoria = 1, presenza_lettera, controllo_lettera, esci;
    char parola[dim], parola_censurata[dim], tent_utente[dim], lettere_usate[dim];
    ;

    // acquisizione parola e numero di tentativi concessi
    printf("Giocatore 1 inserire la parola da indovinare: ");
    scanf("%s", parola);
    printf("Inserire il numero di tentativi concessi per indovinare (di norma 6): ");
    scanf("%d", &tent_max);

    do
    {
        parola_censurata[i] = '_';
        i += 1;
    } while (parola[i] != '\0');

    printf("Giocatore 2 tocca a te: indivina!\n");
    printf("Ecco la parola: ");
    j = 0;
    do
    {
        printf("%c", parola_censurata[j]);
        j += 1;
    } while (parola[j] != '\0');

    printf("\n");

    // ciclo di acquisizione delle lettere

    for (i = 0; i < tent_max && vittoria != 0; i++)
    {
        // controllo_lettera per vedere se la lettera inserita è già stata utilizzata
        esci = 0;
        do
        {
            printf("Il tuo tentatiivo numero %d? ", (i + 1));
            scanf("%s", &tent_utente[i]);

            controllo_lettera = 0;
            for (j = 0; j < i; j++)
            {
                if (tent_utente[i] == lettere_usate[j])
                    controllo_lettera += 1;
            }

            if (controllo_lettera > 0)
                printf("Lettera già usata, riprova\n");
            else
            {
                lettere_usate[i] = tent_utente[i];
                esci = 1;
            }
        } while (esci == 0);

        // controllo_lettera presenza della lettera nella parola
        presenza_lettera = 0;
        j = 0;
        do
        {
            if (parola[j] == tent_utente[i])
            {
                parola_censurata[j] = tent_utente[i];
                presenza_lettera = 1;
            }
            j += 1;
        } while (parola[j] != '\0');

        // inserimento lettera nella parola censurata
        if (presenza_lettera == 1)
        {
            printf("Lettera presente, la nuova parola e': ");
            j = 0;
            vittoria = 1;
            do
            {
                printf("%c", parola_censurata[j]);
                if (parola_censurata[j] == '_')
                    vittoria += 1;
                j += 1;
            } while (parola[j] != '\0');

            printf("\n");

            // controllo_lettera per vedere se l'utente ha vinto
            if (vittoria == 1)
            {
                vittoria = 0;
                printf("Congratulazioni hai indovinato");
            }
        }
        else
        {
            printf("Mi spiace, lettera non presente, la parola rimane: ");
            j = 0;
            do
            {
                printf("%c", parola_censurata[j]);
                j += 1;
            } while (parola[j] != '\0');

            printf("\n");
        }
    }

    // output in caso di perdita
    if (i == tent_max)
    {
        printf("Mi dispiace, hai finito i tentativi, la parola era %s", parola);
    }

    return 0;
}