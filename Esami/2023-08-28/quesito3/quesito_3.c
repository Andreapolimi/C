/*Quesito 3 (9 punti).
Si consideri una matrice di dimensioni MxN che contiene valori binari 0 e 1. La matrice rappresenta una griglia
di possibili percorsi, in cui 0 indica un varco attraversabile e 1 rappresenta un muro invalicabile. I movimenti
all'interno di questa griglia avvengono in orizzontale e verticale, e possono essere rappresentati da coppie di
valori (±i, 0), per gli spostamenti verticali (verso l'alto o il basso), e (0, ±j) per gli spostamenti orizzontali (a destra
o a sinistra). i e j rappresentano cioè scostamenti di riga e di colonna, rispettivamente.

Dopo aver opportunamente dichiarato le strutture dati necessarie, e cioè la matrice e l’array delle mosse, si
definisca una funzione che, ricevuti come parametri la matrice dei percorsi, l’array di mosse, e qualsiasi altro
parametro  ritenuto  necessario,  verifichi  che  partendo  dalla  cella  iniziale  della  matrice  di  coordinate  (0,  0)
l'applicazione sequenziale dei movimenti sulla matrice porti a un percorso valido, ovvero un percorso che non
incontri muri.

La funzione stampa quindi un messaggio opportuno che indichi se il percorso è stato completamente applicato
oppure se è stato applicato parzialmente, e riporti le coordinate dell’elemento della matrice su cui il cammino
è terminato.

Per esempio, si consideri la seguente matrice:
0 1 0 1 1
0 0 1 1 0
1 0 0 0 0
1 1 0 1 0
1 1 1 1 0
● La  sequenza  di mosse  (1, 0),  (0,  1),  (1,  0),  (0,  3),  (-1, 0) è interamente realizzabile e porta nell’elemento di
indici [1, 4]. La funzione stampa un messaggio indicante il successo e la coppia di indici di arrivo, [1, 4].
● La sequenza (1, 0), (0, 2), (2, 0), invece, si ferma alla seconda mossa, poiché la cella di indici [1, 2] memorizza
un muro. La funzione, quindi, stampa un messaggio di insuccesso e gli indici dell’ultima cella attraversata,
[1,0].
● La sequenza (1, 0), (0, 2), (5, 0) porta oltre i limiti della matrice a causa della terza mossa. In tal caso, la funzione
stampa un messaggio di insuccesso e gli indici dell’ultima cella valida, [1,2].
N.B.: Per l’array contenente le mosse si può ipotizzare una dimensione massima predefinita e costante, K. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_MOSSE 5
#define MAX_COL 5
#define MAX_RIGHE 5

typedef enum
{
    False,
    True
} bool;
typedef int contatore_t;
typedef struct mosse
{
    int orizzontale, verticale;
} mossa_t;

void controllo_mossa(int cella_matrice, int mossa, int *indice, bool *blocca, int operazione)
{
    contatore_t h;

    for (h = 0; h < operazione * mossa; h++)
    {
        (*indice) += operazione;
        if ((*indice) == MAX_RIGHE || (*indice) == -1)
        {
            (*indice) -= operazione;
            *blocca = True;
        }
        else
        {
            if (cella_matrice == 1)
            {
                (*indice) -= operazione;
                *blocca = True;
            }
        }
    }
}

void controlla_percorso(int matrice[MAX_RIGHE][MAX_COL], mossa_t mosse[MAX_MOSSE])
{
    contatore_t i = 0, j = 0, k, h;
    bool blocca = False;
    int operazione;

    for (k = 0; k < MAX_MOSSE && blocca == False; k++)
    {
        if (mosse[k].verticale == 0)
        {
            operazione = (mosse[k].orizzontale > 0) ? 1 : -1;
            controllo_mossa(matrice[i][j], mosse[k].orizzontale, &i, &blocca, operazione);
        }
        else
        {
            operazione = (mosse[k].verticale > 0) ? 1 : -1;
            controllo_mossa(matrice[i][j], mosse[k].verticale, &j, &blocca, operazione);
        }
    }

    if (blocca == False)
        printf("Mosse valide, sei arrivato a %d,%d", i, j);
    else
        printf("Percorso non valido, ti sei fermato alla posizione %d,%d", i, j);
}

int main()
{
    int matrice[MAX_RIGHE][MAX_COL] = {{0, 1, 0, 1, 1}, {0, 0, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 0}, {1, 1, 1, 1, 0}};
    mossa_t mosse[MAX_MOSSE];
    contatore_t i;

    for (i = 0; i < MAX_MOSSE; i++)
    {
        printf("Inserire prima il movimento orizzontale poi verticale della %d° mossa con la sintassi ORIZ,VERT :\n", i + 1);
        scanf("%d,%d", &mosse[i].orizzontale, &mosse[i].verticale);
    }

    controlla_percorso(matrice, mosse);

    return 0;
}