#include <stdio.h>

char maggiore(char *s)
{
    char prova, prova2;

    if (*s != '\0')
    {
        prova = *s;
        prova2 = maggiore(s + 1);
        prova = (prova > prova2) ? prova : prova2;
    }

    return prova;
}

int main()
{
    char stringa[] = "cibonazionale";

    printf("%c", maggiore(stringa));

    return 0;
}