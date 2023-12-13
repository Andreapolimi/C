#define MAX_KEYS 3
#define MAX_POINTERS 4

typedef struct data
{
    int key, value[50];
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

void InsertKey(Bplus_node_t **, int);