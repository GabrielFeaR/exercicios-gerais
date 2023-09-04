#include <stdio.h>
#include <string.h>

void ImprimeInvertido(char* string)
{
	int tamanho = strlen (string);
	int i = tamanho-1;
	printf("%c", string[i]);
	string[i] = '\0';
	char string_aux[1000];
	if (string[0] != '\0')
	{
		strcpy(string_aux, string);
		if (string_aux[0] != '\0')
		{
			ImprimeInvertido(string_aux);
		}
	}
}

int main() 
{
	char palavras[1000];
	while (scanf("%s", palavras) == 1)
	{
		ImprimeInvertido(palavras);
		printf(" ");
	}
	return 0;
}