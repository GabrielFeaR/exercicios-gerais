#include <stdio.h>
#include "utils.h"

void LeIntervalo(int * m, int * n)
{
	scanf("%d %d", m, n);
}

int EhPrimo(int n)
{
	int i, cont = 0;
	for (i = 1; i <= n; i++)
	{
		if (n%i == 0)
		{
			cont++;
		}
	}
	if (cont == 2)
	{
		return 1;
	}
	return 0;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior)
{
	int maa = n, mee = m;
	int Menor = n, Maior = m;
	int i;
	for (m; m <= n; m++)
	{
		if (EhPrimo(m) == 1)
		{
			if (m <= Menor)
			{
				*menor = m;
				Menor = m;
			}
			if (m >= Maior)
			{
				*maior = m;
				Maior = m;
			}
		}
	}
}