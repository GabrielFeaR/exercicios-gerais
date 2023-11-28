#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main()
{
	float x1, y1, raio, x2, y2;
	scanf("%f %f %f %f %f", &x1, &y1, &raio, &x2, &y2);
	tCirculo circulo = Circulo_Cria(x1, y1, raio);
	tPonto ponto = Pto_Cria(x2, y2);

	int teste;
	teste = Circulo_Interior(circulo, ponto);
	printf("%d\n", teste);
	Circulo_Apaga(circulo);
	Pto_Apaga(ponto);

	return 0;
}