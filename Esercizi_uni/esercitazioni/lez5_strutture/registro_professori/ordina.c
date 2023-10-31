#include <stdio.h>
#include <string.h>

typedef enum bool
{
    False,
    True
} bool;
typedef int contatori;

typedef struct data
{
    int giorno, mese, anno;
} data;

typedef struct val
{
    data data_valutazione;
    int voto;
    char *materia;
} valutazioni;

typedef struct stu
{
    char *nome, *cognome;
    data data_nascita;
    valutazioni *voti;
} studente;

void ordina_parole(int i, studente elenco[], int num_studenti, char *parola, char *parola_prima, char *parola_dopo)
{
    contatori j, k;
    bool ordine_corretto;
    studente temporaneo;

    ordine_corretto = False;

    for (j = 0; j < strlen(parola) && ordine_corretto == False; j++)
    {
        if (parola[j] > parola_dopo[j])
        {
            temporaneo = elenco[i + 1];
            elenco[i + 1] = elenco[i];
            elenco[i] = temporaneo;
            if (i != 0)
            {
                for (k = 0; k < strlen(parola) && ordine_corretto == False; k++)
                {
                    if (parola_dopo[k] < parola_prima[k])
                    {
                        temporaneo = elenco[i - 1];
                        elenco[i - 1] = elenco[i];
                        elenco[i] = temporaneo;
                        ordine_corretto = True;
                    }
                    else
                    {
                        if (parola_dopo[k] != parola_prima[k])
                            ordine_corretto = True;
                    }
                }
            }
            else
                ordine_corretto = True;
        }
        else
        {
            if (parola[j] != parola_dopo[j])
                ordine_corretto = True;
        }
    }
}

// la funzione viene chiamata dopo aver controllato che nessuno degli studenti è stato inserito due volte,
// quindi non serve effettuare nuovamente il controllo
void riordina_elenco(studente elenco[], int num_studenti)
{
    contatori i;

    // ordino tutti gli studenti
    for (i = 0; i < num_studenti - 1; i++)
    {
        if (strcmp(elenco[i].cognome, elenco[i + 1].cognome) == 0)
        {
            // scorro ogni lettera del nome finchè non ne trovo una diversa
            ordina_parole(i, elenco, num_studenti, elenco[i].nome, elenco[i - 1].nome, elenco[i + 1].nome);
        }
        else
        {
            // scorro ogni lettera del cognome finche quello dopo non ha almeno una lettera diversa
            ordina_parole(i, elenco, num_studenti, elenco[i].cognome, elenco[i - 1].cognome, elenco[i + 1].cognome);
        }
    }
}

// main per testare la funzione
/*int main()
{
    contatori i;
    studente elenco[] = {{.nome = "Zabn", .cognome = "Rossi"},
                         {.nome = "Tavernello", .cognome = "Rossi"},
                         {.nome = "Rossi", .cognome = "Gianni"}};

    riordina_elenco(elenco, 3);

    for (i = 0; i < 3; i++)
    {
        printf("%s %s", elenco[i].cognome, elenco[i].nome);
        printf("\n");
    }

    return 0;
}*/