#include <stdio.h>

int main()
{
	int qtd;
	scanf("%d", &qtd);
	int livro[qtd];
	int i;

	for (i = 0; i < qtd; i++)
	{
		scanf("%d", &livro[i]);
	}
	int j;
	int total = 0;
	for (i = 0; i < qtd; i++)
	{
		total = 0;
		for (j = 0; j < qtd; j++)
		{
			if (livro[i] == livro[j] && i != j)
			{
				total++;
			}
		}
		if (total == 0)
		{
			printf("%d ", livro[i]);
		}
	}
	return 0;
}