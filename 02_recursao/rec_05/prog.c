#include <stdio.h>

int fatorial(int n)
{
	int num, resultado = 1;
	num = n-1;
	if (num > 0)
	{
		return n * (fatorial(num));
	}
	else
	{
		return 1;
	}
}

int main()
{
	int num_entrada, num_saida;
	scanf("%d", &num_entrada);
	num_saida = fatorial(num_entrada);
	printf("%d\n", num_saida);
	return 0;
}
