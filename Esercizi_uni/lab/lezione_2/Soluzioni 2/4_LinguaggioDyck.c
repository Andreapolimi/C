#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_LEN 512

int main()
{

	char stringa_input[MAX_LEN];

	printf("Inserisci una stringa di Dyck:\n");
	fgets(stringa_input, MAX_LEN, stdin);

	int aperte = 0;
	bool dyck = true;
	size_t lunghezza = strlen(stringa_input);
	for (int i = 0; i < lunghezza && dyck; i++)
	{
		switch (stringa_input[i])
		{
			case '[':
				aperte++;
				break;
			case ']':
				aperte--;
				if (aperte < 0)
					dyck = false;
				break;
		}
	}
	if (aperte != 0)
		dyck = false;

	if (dyck)
		printf("Ottimo, grazie!\n");
	else
		printf("Ehi, questa non è una stringa di Dyck!\n");
}