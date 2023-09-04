#include <stdio.h>
#include <math.h>

int SomaElementosPares(int* vet, int numElementos)
{
	numElementos = numElementos-1;
	int soma;
	if (numElementos > -1)
	{
		int numero = vet[numElementos];
		if (numero % 2 == 0)
		{
			soma = numero;
			return soma + (SomaElementosPares(vet, numElementos));
		}
		else
		{
			SomaElementosPares(vet, numElementos);
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	int qtd, j, soma_par;
	scanf("%d", &qtd);
	for (j = 0; j < qtd; j++)
	{
		int tamanho_vetor;
		scanf("%d", &tamanho_vetor);
		int i;
		int vetor[tamanho_vetor];
		for (i = 0; i < tamanho_vetor; i++)
		{
			scanf("%d", &vetor[i]);
		}
		soma_par = SomaElementosPares(vetor, tamanho_vetor);
		printf("%d\n", soma_par);
	}
	return 0;
}