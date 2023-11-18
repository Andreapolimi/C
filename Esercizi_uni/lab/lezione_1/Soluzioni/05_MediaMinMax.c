/*Leggere in input una sequenza di numeri naturali 
(interi positivi strettamente maggiori di zero) 
e calcolare e visualizzare il massimo, il minimo e la media. 
La sequenza si interrompe non appena viene introdotto un numero negativo o uguale a zero

Per esempio, data la sequenza 5, 1, 2, 3, 6, -5, l'output deve  essere:
"Il massimo è 6, il minimo è 1, la media è 3.4" 
Data la sequenza -2, l'output deve essere
"La sequenza inserita è nulla"
 */
#include <stdio.h>

int main()
{
	int x;
	int max = 0, min = 0;
	int n = 0;
	float media = 0.0;

	printf("Inserisci un valore: ");
	scanf("%d", &x);

	if (x > 0)
	{

		max = x;
		min = x;

		while (x > 0)
		{
			if (x > max)
				max = x;

			if (x < min)
				min = x;

			media += x;
			n++;

			printf("Inserisci un valore: ");
			scanf("%d", &x);
		}

		media = media / n;
		printf("Massimo = %d, Minimo = %d, Media = %f", max, min, media);
	}
	else
		printf("La sequenza inserita e' nulla");
	return 0;
}