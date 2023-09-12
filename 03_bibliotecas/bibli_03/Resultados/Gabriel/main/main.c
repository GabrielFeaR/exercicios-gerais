#include "data.h"
#include <stdio.h>

int main()
{
	int dia1, dia2, mes1, mes2, ano1, ano2;
	scanf("%d/%d/%d", &dia1, &mes1, &ano1);
	scanf("%d/%d/%d", &dia2, &mes2, &ano2);
	if (verificaDataValida(dia1, mes1, ano1) == 0 || verificaDataValida(dia2, mes2, ano2) == 0)
	{
		printf("A primeira e/ou segunda data(s) invalida(s)\n");
		return 0;
	}
	else
	{
		printf("Primeira data: ");
		imprimeDataExtenso(dia1, mes1, ano1);
		printf("Segunda data: ");
		imprimeDataExtenso(dia2, mes2, ano2);
		int compara = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

		if (compara == -1)
		{
			printf("A primeira data eh mais antiga\n");
		}
		else if (compara == 1)
		{
			printf("A segunda data eh mais antiga\n");
		}
		else if (compara == 0)
		{
			printf("As datas sao iguais\n");
		}

	}
	int diferenca = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);
	printf("A diferenca em dias entre as datas eh: %02d dias\n", diferenca);
	return 0;
}