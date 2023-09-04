#include <stdio.h>
#include <string.h>
#include <math.h>

int palindromo(char* string, int tamanho)
{
	tamanho = tamanho - 1;
	int i = 0, j = tamanho, posicao = -2;
	for (i = 0; i <= j; i++)
	{
		if (string[i] != ' ')
		{
			posicao = i;
			break;
		}
	}
	if (tamanho > -1 && posicao != -2)
	{
		if (string[posicao] == string[j])
		{
			string[posicao] = ' ';
			string[j] = ' ';
			return 1 + palindromo(string, tamanho);
		}
		else
		{
			string[posicao] = ' ';
			string[j] = ' ';
			return 0 + palindromo(string, tamanho);
		}
	}
	else
	{
		return 0;
	}
}

int main() 
{
	double tamanho, resultado, numeroDoMeio;
	char palavra[1000];
	while (scanf("%s", palavra) == 1)
	{
		tamanho = strlen (palavra);
		resultado = palindromo(palavra, tamanho);
		numeroDoMeio = ceil(tamanho/2);
		if (resultado == numeroDoMeio)
		{
			printf("SIM\n");
		}
		else
		{
			printf("NAO\n");
		}
	}
	return 0;
}