#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano)
{
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
	{
		if (dia > 31)
		{
			return 0;
		}
	}
	else if (mes != 2)
	{
		if (dia > 30)
		{
			return 0;
		}
	}
	else if (mes == 2)
	{
		if (verificaBissexto(ano) == 1)
		{
			if (dia > 29)
			{
				return 0;
			}
		}
		else
		{
			if (dia > 28)
			{
				return 0;
			}
		}
	}
	if (dia < 1 || mes < 1)
	{
		return 0;
	}
	return 1;
}
void imprimeMesExtenso(int mes)
{
	if (mes == 1)
	{
		printf("Janeiro de ");
	}
	else if (mes == 2)
	{
		printf("Fevereiro de ");
	}
	else if (mes == 3)
	{
		printf("Março de ");
	}
	else if (mes == 4)
	{
		printf("Abril de ");
	}
	else if (mes == 5)
	{
		printf("Maio de ");
	}
	else if (mes == 6)
	{
		printf("Junho de ");
	}
	else if (mes == 7)
	{
		printf("Julho de ");
	}
	else if (mes == 8)
	{
		printf("Agosto de ");
	}
	else if (mes == 9)
	{
		printf("Setembro de ");
	}
	else if (mes == 10)
	{
		printf("Outubro de ");
	}
	else if (mes == 11)
	{
		printf("Novembro de ");
	}
	else if (mes == 12)
	{
		printf("Dezembro de ");
	}
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
	printf("%02d de ", dia);
	imprimeMesExtenso(mes);
	printf("%02d\n", ano);
}

int verificaBissexto(int ano)
{
	if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
	{
		return 1;
	}
	return 0;
}

int numeroDiasMes(int mes, int ano)
{
	if (mes == 1)
	{
		return 31;	
	}
	else if (mes == 2)
	{
		if (verificaBissexto(ano) == 1)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else if (mes == 3)
	{
		return 31;	
	}
	else if (mes == 4)
	{
		return 30;
	}
	else if (mes == 5)
	{
		return 31;	
	}
	else if (mes == 6)
	{
		return 30;
	}
	else if (mes == 7)
	{
		return 31;	
	}
	else if (mes == 8)
	{
		return 31;	
	}
	else if (mes == 9)
	{
		return 30;
	}
	else if (mes == 10)
	{
		return 31;	
	}
	else if (mes == 11)
	{
		return 30;	
	}
	else if (mes == 12)
	{
		return 31;	
	}
	return -1;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
	int diasTotais1 = dia1 + calculaDiasAteMes(mes1, ano1);
	int diasTotais2 = dia2 + calculaDiasAteMes(mes2, ano2);
	if (diasTotais1 == diasTotais2)
	{
		return 0;
	}
	if (diasTotais1 > diasTotais2)
	{
		return 1;
	}
	if (diasTotais1 < diasTotais2)
	{
		return -1;
	}
}

int calculaDiasAteMes(int mes, int ano)
{
	int total = 0;
	int i;
	for (i = 1; i < mes; i++)
	{
		total = total + (numeroDiasMes(i, ano));
	}
	return total;
}


int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
	 int totalDias = 0;
	 int ano, aux;
	 if (ano2 < ano1)
	 {
	 	aux = ano1;
	 	ano1 = ano2;
	 	ano2 = aux;
	 	aux = mes1;
	 	mes1 = mes2;
	 	mes2 = aux;
	 	aux = dia1;
	 	dia1 = dia2;
	 	dia2 = aux-1;
	 }
	
	if (ano1 != ano2)
	{
    	for (ano = ano1+1; ano < ano2; ano++)
    	{
        	totalDias += 365 + verificaBissexto(ano);
    	}
	}

    if (mes1 != mes2)
	    for (int mes = mes1; mes <= 12; mes++)
	    {
	        totalDias += numeroDiasMes(mes, ano1) - dia1;
	        dia1 = 0;
	    }
    if (mes1 != mes2)
	    for (int mes = 1; mes < mes2; mes++)
	    {
	        totalDias += numeroDiasMes(mes, ano2);
	    }

    if (mes1 != mes2)
    	totalDias += dia2;
	else
		totalDias += (dia2-dia1);
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0)
    {
    	totalDias = 0;
    }
    if (ano1 == ano2 && mes1 != mes2)
    {
    	if (verificaBissexto(ano) == 0)
    		totalDias = totalDias-365;
    	else
    		totalDias = totalDias-365;
    }
    if (totalDias < 0)
    {
    	totalDias = totalDias *-1;
    }
    return totalDias;
}
