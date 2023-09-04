#include <stdio.h>
#include <math.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado)
{
	numElementos = numElementos-1;
	if (numElementos > -1)
	{
		int numero = vet[numElementos];
		if (numero == numeroProcurado)
		{
			return 1 + (ContaOcorrencias(vet, numElementos, numeroProcurado));
		}
		else
		{
			ContaOcorrencias(vet, numElementos, numeroProcurado);
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	int qtd, j, i, numeroProcurado, tamanho_vetor, total_de_ocorrencias;
	scanf("%d", &qtd);
	for (j = 0; j < qtd; j++)
	{
		scanf("%d", &numeroProcurado);
		scanf("%d", &tamanho_vetor);
		int vetor[tamanho_vetor];
		for (i = 0; i < tamanho_vetor; i++)
		{
			scanf("%d", &vetor[i]);
		}
		total_de_ocorrencias = ContaOcorrencias(vetor, tamanho_vetor, numeroProcurado);
		printf("%d\n", total_de_ocorrencias);
	}
	return 0;
}