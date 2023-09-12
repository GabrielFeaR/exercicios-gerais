#include "string_utils.h"
#include <stdio.h>


int string_length(char *str)
{
	int i = 0;
	while (1)
	{
		if (str[i] == '\0')
		{
			break;
		}
			i++;
	}
	return i;
}


void string_copy(char *src, char *dest)
{
	int i = 0;
	int tamanho = string_length(src);
	for (i = 0; i < tamanho; i++)
	{
		dest[i] = src[i];
	}
}

void string_upper(char *str)
{
	int i;
	int tamanho = string_length(str);
	for (i = 0; i < tamanho; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}
}

void string_lower(char *str)
{
	int i;
	int tamanho = string_length(str);
	for (i = 0; i < tamanho; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
	}
}

void string_reverse(char *str)
{
	int tamanho = string_length (str);
	char str_aux[tamanho];
	string_copy(str, str_aux);
	int i = 0;
	int j = tamanho-1;
	for (j = tamanho-1; j > -1; j--)
	{
		str[i] = str_aux[j];
		i++;
	}
}
