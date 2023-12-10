#define MAX_CHAR 50

typedef struct tree
{
    char key[MAX_CHAR];
    struct tree *left_child;
    struct tree *right_child;
} tree_t;

typedef struct queue
{
    tree_t *pointer;
    struct queue *next;
} queue_t;

// INSERTION
void InsertTree(tree_t **, char *);

// BILANCE
void IfBalanced(tree_t **);

// PRINT
void printfLevel(tree_t *);
void printfInOrder(tree_t *);
int TreeHeight(tree_t *);

// SEARCH
tree_t *Search(tree_t *, char *);
tree_t *SearchParent(tree_t *, char *);
tree_t *FindMin(tree_t *);
tree_t *FindMax(tree_t *);
tree_t *InOrderSuccessor(tree_t *, char *);
tree_t *InOrderPredecessor(tree_t *, char *);

// DELETE
void Delete(tree_t **, char *);