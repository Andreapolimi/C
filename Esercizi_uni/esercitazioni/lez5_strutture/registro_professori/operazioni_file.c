#include <stdio.h>
#include <stdlib.h>

typedef enum bool
{
    False,
    True
} bool;
typedef int contatori;

typedef int controllo;

typedef char gestione_file;

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

// prima di chiamare la funzione viene già allocata della memoria al puntatore di studenti
void crea_struttura_file(studente **elenco, int *i, int *j)
{
    gestione_file file_mode[] = "r";
    gestione_file url_file_classe[] = "/Users/andreavaccai/Coding/C/Esercizi_uni/esercitazioni/lez5_strutture/registro_professori/file_classe.txt";
    gestione_file url_file_studente[] = "/Users/andreavaccai/Coding/C/Esercizi_uni/esercitazioni/lez5_strutture/registro_professori/file_studente_voti.txt";
    FILE *file_handle_classe, *file_handle_studente;

    file_handle_classe = fopen(url_file_classe, file_mode);
    if (file_handle_classe == NULL)
    {
        printf("Lettura file classe fallita");
        exit(1);
    }
    else
        printf("File classe letto con successo\n");

    file_handle_studente = fopen(url_file_studente, file_mode);
    if (file_handle_studente == NULL)
    {
        printf("Lettura file classe fallita");
        exit(1);
    }
    else
        printf("File studente letto con successo\n");

    *i = 1;
    while (!feof(file_handle_classe))
    {
        *elenco = (studente *)realloc((*elenco), (*i) * sizeof(studente));
        fscanf(file_handle_classe, "%s %s %d:%d:%d", (*elenco)[*i].nome, (*elenco)[*i].cognome,
               (*elenco)[*i].data_nascita.giorno, (*elenco)[*i].data_nascita.mese, (*elenco)[*i].data_nascita.anno);

        (*elenco)[*i].voti = (valutazioni *)calloc(1, sizeof(valutazioni));

        *j = 1;
        while (!feof(file_handle_studente))
        {
            (*elenco)[*i].voti = (valutazioni *)realloc((*elenco)[*i].voti, (*j) * sizeof(valutazioni));
            fscanf(file_handle_studente, "%s %d %d:%d:%d", (*elenco)[*i].voti[*j].materia, &(*elenco)[*i].voti[*j].voto,
                   (*elenco)[*i].voti[*j].data_valutazione.giorno, (*elenco)[*i].voti[*j].data_valutazione.mese, (*elenco)[*i].voti[*j].data_valutazione.anno);
            (*j)++;
        }
        (*i)++;
    }

    fclose(file_handle_classe);
    fclose(file_handle_studente);
}

void riscrivi_file();

void stampa_elenco(studente *elenco, int num_studenti)
{
    contatori i, j;

    for (i = 0; i < num_studenti; i++)
    {
        printf("%s  %s  %d:%d:%d\n", elenco[i].cognome, elenco[i].nome,
               elenco[i].data_nascita.giorno, elenco[i].data_nascita.mese, elenco[i].data_nascita.anno);
    }
}

void stampa_studente();

int main()
{
    studente *elenco;
    contatori num_studenti, num_valutazioni;

    elenco = (studente *)calloc(1, sizeof(studente));

    crea_struttura_file(&elenco, &num_studenti, &num_valutazioni);

    stampa_elenco(elenco, num_studenti);

    free(elenco);

    return 0;
}