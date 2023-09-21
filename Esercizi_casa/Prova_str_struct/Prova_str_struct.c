#include <stdio.h>
#include <stdlib.h>
#define DIM 50

struct pers
{
    char nome[DIM];
    char cognome[DIM];
    int sesso;
    char agg[DIM]; 
}pers;

struct pers p[2];

void AGGETTIVO()
{
    for(int i=0;i<2;i++)
    {
        if((p[i].sesso)==1)
        *p[i].agg="stupendo";
        else
        *p[i].agg="stupida in culo";
    }
}

int main()
{  
    for(int i=0;i<2;i++)
    {
        printf("Inserisci nome, cognome e sesso (1 per maschio e 2 per femmina) della %d° persona:\n",(i+1));
        scanf("%s\n%s\n%d",&p[i].nome,&p[i].cognome,&p[i].sesso);
    }

    AGGETTIVO();
    printf("%s %s e' %s \n",p[0].nome,p[0].cognome,p[0].agg);
    printf("%s %s e' %s",p[1].nome,p[1].cognome,p[1].agg);
    return 0;
}