#include <stdio.h>
#include "data.h"

int main()
{
    tData data1, data2;
    int dia1, dia2, mes1, mes2, ano1, ano2;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    data1 = CriaData(dia1, mes1, ano1);
    data2 = CriaData(dia2, mes2, ano2);
    if (VerificaDataValida(data1) == 0 || VerificaDataValida(data2) == 0)
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }
    else
    {
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda data: ");
        ImprimeDataExtenso(data2);
        int compara = ComparaData(data1, data2);

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
    int diferenca = CalculaDiferencaDias(data1, data2);
    printf("A diferenca em dias entre as datas eh: %02d dias\n", diferenca);
    return 0;
}