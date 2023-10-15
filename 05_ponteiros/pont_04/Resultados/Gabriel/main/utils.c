#include <stdio.h>
#include "utils.h"

void LeNumeros(int *array, int tamanho)
{
	int i;
	for (i = 0; i < tamanho; i++)
	{
		scanf("%d", array+i);
	}
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media)
{
	*media = 0;
	int* i;
	int* j;
	int temp;
	for (i = array; i < array+tamanho; i++)
	{
		for (j = i+1; j < array+tamanho; j++)
		{
			if (*(i) > *(j))
			{
				temp = *(i);
				*(i) = *(j);
				*(j) = temp;	
			}
		}
		*media += *(i);
	}
	*maior = *(array+tamanho-1);
	*media = *media/tamanho;
	*menor = *(array);
}