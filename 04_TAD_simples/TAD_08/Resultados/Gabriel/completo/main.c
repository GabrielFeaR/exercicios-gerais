#include <stdio.h>
#include "departamento.h"

int main()
{
    int qtdDepartamentos;
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX], nome[STRING_MAX], diretor[STRING_MAX];
    int m1, m2, m3, i;
    scanf("%d", &qtdDepartamentos);
    tDepartamento d[qtdDepartamentos];
    for (i = 0; i < qtdDepartamentos; i++)
    {
        scanf("%s", nome);
        scanf("%s", diretor);
        scanf("%s", c1);
        scanf("%s", c2);
        scanf("%s", c3);
        scanf("%d %d %d", &m1, &m2, &m3);
        d[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }
    ordenaPorMediaDepartamentos(d, qtdDepartamentos);
    for (i = 0; i < qtdDepartamentos; i++)
    {
        imprimeAtributosDepartamento(d[i]);
    }
    return 0;
}