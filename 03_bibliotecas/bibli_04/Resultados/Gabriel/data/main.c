#include "data.h"
#include <stdio.h>

int main()
{
	int dia, mes, ano, qtdDias;
	scanf("%d/%d/%d", &dia, &mes, &ano);
	if (verificaDataValida(dia, mes, ano) == 1)
	{
		printf("Data informada: ");
		imprimeDataExtenso(dia, mes, ano);
		if (verificaBissexto(ano) == 1)
		{
			printf("O ano informado eh bissexto\n");
		}
		else
		{
			printf("O ano informado nao eh bissexto\n");
		}
		qtdDias = numeroDiasMes(mes, ano);
		printf("O mes informado possui %02d dias\n", qtdDias);
		printf("A data seguinte eh: ");
		imprimeProximaData(dia, mes, ano);
	}
	else
	{
		printf("A data informada eh invalida\n");
	}
	return 0;
}