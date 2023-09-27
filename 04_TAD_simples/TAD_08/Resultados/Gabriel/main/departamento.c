#include <stdio.h>
#include <math.h>
#include <string.h>
#include "departamento.h"

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor)
{
    tDepartamento departamento;
    strcpy(departamento.nome, nome);
    strcpy(departamento.c1, c1);
    strcpy(departamento.c2, c2);
    strcpy(departamento.c3, c3);
    strcpy(departamento.diretor, diretor);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    departamento.media_geral = calculaMediaGeralDepartamento(departamento);

    return departamento;
}

void imprimeAtributosDepartamento (tDepartamento depto)
{
    double Dp = calculaDesvioPadraoDepartamento(depto);
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", depto.media_geral);
    printf("desvio padrao => %.2f\n", Dp);
    printf("\n");
}

int validaMediaDepartamento (int media)
{
    if (media >= 0 && media <= 10)
    {
        return 1;
    }
    return 0;
}

double calculaDesvioPadraoDepartamento(tDepartamento depto)
{
    double m1 = depto.m1, m2 = depto.m2, m3 = depto.m3;
    double Dp;
    double media = depto.media_geral;
    Dp = sqrt((pow(m1-media, 2) + pow(m2-media, 2) + pow(m3-media, 2))/3);
    return Dp;
}

double calculaMediaGeralDepartamento(tDepartamento depto)
{
    double media;
    media = (depto.m1 + depto.m2 + depto.m3);
    media = media/3;

    return media;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho-1; i++)
    {
        for (j = 0; j < tamanho-i-1; j++)
        {
            if (d[j].media_geral < d[j+1].media_geral)
            {
                tDepartamento temp = d[j];
                d[j] = d[j+1];
                d[j+1] = temp;
            }
        }
    }
}