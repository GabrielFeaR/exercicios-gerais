#include <stdio.h>
#include "data.h"


void InicializaDataParam( int dia, int mes, int ano, tData *data)
{
    data -> dia = dia;
    data -> mes = mes;
    data -> ano = ano;
}

void LeData( tData *data )
{
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, data);
}

void ImprimeData( tData *data )
{
    printf("'%02d/%02d/%02d'\n", data -> dia, data -> mes, data -> ano);
}

int EhBissexto( tData *data )
{
    if ((data -> ano % 4 == 0 && data -> ano % 100 != 0) || (data -> ano % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int InformaQtdDiasNoMes( tData *data )
{
    int dia = data -> dia, mes = data -> mes, ano = data -> ano;
    if (mes == 1)
    {
        return 31;  
    }
    else if (mes == 2)
    {
        if (EhBissexto  (data) == 1)
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

void AvancaParaDiaSeguinte( tData *data )
{
    int dia = data -> dia, mes = data -> mes, ano = data -> ano;
    int qtdDia = InformaQtdDiasNoMes(data);
    if (dia == qtdDia)
    {
        dia = 1;
        if (mes != 12)
        {
            mes++;
        }
        else if (mes == 12)
        {
            mes = 1;
            ano++;
        }
    }
    else
    {
        dia++;
    }
    data -> dia = dia;
    data -> mes = mes;
    data -> ano = ano;
}

int EhIgual( tData *data1, tData *data2 )
{
    if (data1 -> dia == data2 -> dia && data1 -> mes == data2 -> mes && data1 -> ano == data2 -> ano)
    {
        return 1;
    }
    return 0;
}

