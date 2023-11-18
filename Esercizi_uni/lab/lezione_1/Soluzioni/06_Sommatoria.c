/*y = SUM (i=q...r) 1/i
(Sommatoria per i che va da q a r di 1 fratto i)
Si scirva un programma per il calcolo di y.
Si assuma di acquisire r e q dall'esterno (dati di  input)
Si controlli che r e q siano interi positivi tali che r > q
*/
#include <stdio.h>

int main()
{
	int r, q;
	float y;
	float i;

	printf("Inserisci i valori di q e r: ");
	scanf("%d %d", &q, &r);

	if ((r > 0) && (q > 0) && (r > q))
	{
		y = 0;
		i = q;

		while (i <= r)
		{

			y += 1 / i;
			i++;
		}

		printf("Il risultato e' %f", y);
	}
	else
		printf("Errore nell'immissione dei dati");

	return 0;
}