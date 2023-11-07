#define DIM_MAX 50
#define MAX_CHAR_CLS 3

typedef enum bool
{
    False,
    True
} bool;

typedef struct data
{
    int giorno, mese, anno;
} data;

typedef struct valutazioni
{
    data data_valutazione;
    int voto;
    char *materia;
} valutazioni;

typedef struct studente
{
    char *nome, *cognome;
    data data_nascita;
    valutazioni *voti;
    int conta_valutazioni;
    char *percorso_file;
} studente;

typedef int contatori;
typedef int controllo;
typedef char gestione_file;

void ordina_parole(int, studente[], int, char *, char *, char *);
void riordina_elenco(studente[], int);

char *ottieni_file_classe();

int struttura_valutazioni(valutazioni **, char *, int);
studente *struttura_elenco(contatori *, gestione_file[]);

void stampa_elenco(studente *, int);

void aggiunta_studente(studente **, int);