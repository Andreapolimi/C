typedef struct albero
{
    int valore, num_figli;
    struct albero *padre;
    struct albero *el_successivo;
    struct albero *primo_figlio;
} nodo_t;
typedef int cont_t;
typedef enum
{
    False,
    True
} bool_t;

nodo_t *ricerca_nodo(nodo_t *, int);
void aggiungi_nodo(nodo_t *);
void modifica_nodo(nodo_t *);
void elimina_nodo(nodo_t *);
void stampa_albero(nodo_t *, int);
void quicksort_lista(nodo_t *, nodo_t *);
nodo_t *trova_max(nodo_t *);
