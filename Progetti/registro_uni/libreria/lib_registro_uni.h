#define MAX_RIGA 100

typedef int cont_t;

typedef enum
{
    False,
    True
} bool_t;

typedef struct data
{
    int giorno, mese, anno;
} data_t;

typedef struct tree
{
    char cartella[MAX_RIGA], file_complessivo[MAX_RIGA], file_specifico[MAX_RIGA];
    int byte;
    char identificativo[MAX_RIGA];
    struct tree *padre;
    struct tree *next;
    struct tree *first_child;
} node_t;

typedef struct valutazoni
{
    node_t *nodo_albero;
    char esame[MAX_RIGA];
    int voto;
    data_t data_assegnazione;
} valutazione_t;

typedef struct studente
{
    node_t *nodo_albero;
    char id_persona[MAX_RIGA];
    char nome[MAX_RIGA], cognome[MAX_RIGA];
    data_t data_nascita;
    int num_valutazioni;
    valutazione_t *valutazioni;
} studente_t;

typedef struct scaglione
{
    node_t *nodo_albero;
    char range[MAX_RIGA];
    int num_studenti;
    int *indici_esami;
    char *professori[MAX_RIGA];
    studente_t *studente;
} scaglione_t;

typedef struct anno
{
    node_t *nodo_albero;
    char nome[MAX_RIGA];
    char *esami[MAX_RIGA];
    scaglione_t *scaglione;
} anno_t;

typedef struct corso
{
    node_t *nodo_albero;
    char nome[MAX_RIGA];
    anno_t *anno;
} corso_t;

node_t *cerca_nodo(node_t *, int);
void aggiungi_nodo();
void rimuovi_nodo();
void modifica_nodo();
void stampa_nodo();

node_t *acquisisci_file(node_t *); // ricerca binaria
void scrivi_file();                // trova modo per scrivere in mezzo