#include <stdio.h>
#include "vetor.h"

void LeDadosParaVetor(int * vet, int tam)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		scanf("%d", vet + i);
	}
}

void ImprimeDadosDoVetor(int * n, int tam)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		printf("%d ", *(n + i));
	}
	printf("\n");
}	

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar)
{
	int temp;
	int *i;
	for (i = paraTrocar+1; i < vet + tam; i++)
	{
		if (*i <= *paraTrocar)
		{
			temp = *paraTrocar;
			*paraTrocar = *i;
			*i = temp;
		}
	}
}

void OrdeneCrescente(int * vet, int tam)
{
	int i;
	for (i = 0; i < tam - 1; i++)
	{
		TrocaSeAcharMenor(vet, tam, vet+i);
	}
}