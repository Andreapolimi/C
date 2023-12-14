#define MAX_KEYS 3
#define MAX_POINTERS 4

typedef struct data
{
    int key, value[50];
    struct data *next;
} data_t;

typedef struct Bplus
{
    int keys[MAX_KEYS];
    bool isleaf;
    int cont_keys;
    struct Bplus *next_leaf;
    union pointer
    {
        struct Bplus *low_level[MAX_POINTERS];
        data_t *data[MAX_KEYS];
    } pointer;
} Bplus_node_t;

typedef struct queue
{
    Bplus_node_t *pointer;
    struct queue *next;
} queue_t;

void InsertKey(Bplus_node_t **, data_t *, int, Bplus_node_t *, Bplus_node_t *);

void printfLevel(Bplus_node_t *);