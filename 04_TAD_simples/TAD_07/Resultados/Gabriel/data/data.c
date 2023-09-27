#include <stdio.h>
#include "data.h"

tData CriaData(int dia, int mes, int ano)
{
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

int VerificaDataValida(tData data)
{
    int dia = data.dia, mes = data.mes, ano = data.ano;
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
        if (VerificaBissexto(data) == 1)
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

void ImprimeMesExtenso(tData data)
{
    int mes = data.mes;
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

void ImprimeDataExtenso(tData data)
{
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf("%02d\n", data.ano);
}

int VerificaBissexto(tData data)
{
    if ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0))
    {
        return 1;
    }
    return 0;
}

int NumeroDiasMes(tData data)
{
    int dia = data.dia, mes = data.mes, ano = data.ano;
    if (mes == 1)
    {
        return 31;  
    }
    else if (mes == 2)
    {
        if (VerificaBissexto(data) == 1)
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

int ComparaData(tData data1, tData data2)
{
    int diasTotais1 = data1.dia + CalculaDiasAteMes(data1);
    int diasTotais2 = data2.dia + CalculaDiasAteMes(data2);
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
    return -2;
}

int CalculaDiasAteMes(tData data)
{
    int total = 0;
    tData aux;
    aux = data;
    int i;
    for (i = 1; i < data.mes; i++)
    {
        aux.mes = i;
        total = total + (NumeroDiasMes(aux));
    }
    return total;
}


int CalculaDiferencaDias(tData data1, tData data2)
{
    int totalDias = 0;
    int ano1 = data1.ano, mes1 = data1.mes, dia1 = data1.dia;
    int ano2 = data2.ano, mes2 = data2.mes, dia2 = data2.dia;
    int aux;
    tData ano, mes;
    if (ano2 < ano1)
    {
        aux = data1.ano;
        data1.ano = data2.ano;
        ano2 = aux;
        aux = data1.mes;
        data1.mes = data2.mes;
        data2.mes = aux;
        aux = data1.dia;
        data1.dia = data2.dia;
        data2.dia = aux-1;
    }
    
    if (ano1 != ano2)
    {
        for (ano.ano = ano1+1; ano.ano < ano2; ano.ano++)
        {
            totalDias += 365 + VerificaBissexto(ano);
        }
    }

    if (mes1 != mes2)
    {
        mes.ano = ano1;
        for (mes.mes = mes1; mes.mes <= 12; mes.mes++)
        {
            totalDias += NumeroDiasMes(mes) - dia1;
            dia1 = 0;
        }
    }
    if (mes1 != mes2)
    {
        mes.ano = ano2;
        for (mes.mes = 1; mes.mes < mes2; mes.mes++)
        {
            totalDias += NumeroDiasMes(mes);
        }
    }
    if (mes1 != mes2)
        totalDias += dia2;
    else
        totalDias += (dia2-dia1);
    if(ComparaData(data1, data2) == 0)
    {
        totalDias = 0;
    }
    if (ano1 == ano2 && mes1 != mes2)
    {
        if (VerificaBissexto(ano) == 0)
            totalDias = totalDias-365;
        else
            totalDias = totalDias-365;
    }
    return totalDias;
}
