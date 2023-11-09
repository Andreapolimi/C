/*Quesito 2 (5 punti).
Si formuli la funzione strcmpRicorsiva(char s1[], char s2[]), come versione ricorsiva della ben nota
funzione  strcmp(char  s1[],  char  s2[]),  definita  in  string.h,  che  confronta  due  stringhe  in  base
all’ordinamento alfabetico e restituisce:
● 0 se le stringhe sono uguali,
● un valore < 0 se s1 precede alfabeticamente s2
● un valore > 0 se s1 segue alfabeticamente s2*/

#include <stdio.h>
#include <string.h>

typedef int contatore_t;

int strcmpRicorsiva(char s1[], char s2[])
{
    int confronto;
    contatore_t i = 0;

    if (s1[i + 1] == '\0' && s2[i + 1] == '\0')
    {
        confronto = s1[i] - s2[i];
    }
    else
    {
        if (s1[i + 1] == '\0')
        {
            confronto = -s2[i];
        }
        else
        {
            if (s2[i + 1] == '\0')
            {
                confronto = s1[i];
            }
            else
            {
                if (s1[i] == s2[i])
                {
                    i++;
                    confronto = strcmpRicorsiva(&s1[i], &s2[i]);
                }
                else
                    confronto = s1[i] - s2[i];
            }
        }
    }

    return confronto;
}

int main()
{
    char s1[] = "ciaoo", s2[] = "ciao";

    printf("%d\n %d", strcmpRicorsiva(s1, s2), strcmp(s1, s2));

    return 0;
}