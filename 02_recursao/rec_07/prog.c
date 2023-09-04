#include <stdio.h>


int somaDigitos(int n)
{
	int soma = n%10;
	
	if (n > 9)
		n = n/10;
	else
		return n;

	if (n > 0)
	{
		return soma + (somaDigitos(n));
	}
	return 0;
}

int main()
{
	int num, resultado;
	scanf("%d", &num);
	resultado = somaDigitos(num);
	printf("%d\n", resultado);
	return 0;
}