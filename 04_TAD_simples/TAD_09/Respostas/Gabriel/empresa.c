#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

tEmpresa criaEmpresa(int id)
{
    tEmpresa empresa;
    empresa.qtdFuncionarios = 0;
    empresa.id = id;
    return empresa;
}

tEmpresa leEmpresa()
{
    int id, i, qtdFuncionarios; 
    scanf("%d %d", &id, &qtdFuncionarios);
    tEmpresa empresa = criaEmpresa(id);
    for (i = 0; i < qtdFuncionarios; i++)
    {
        tFuncionario funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
    }

    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario)
{
    int i, id = getIdFuncionario(funcionario);
    for (i = 0; i < empresa.qtdFuncionarios; i++)
    {
        if (id == getIdFuncionario(empresa.funcionarios[i]))
        {
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, empresa.funcionarios[i].id);
            return empresa;
        }
    }
    empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
    empresa.qtdFuncionarios++;

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa)
{
    int i;
    printf("Empresa %d:\n", empresa.id);
    for (i = 0; i < empresa.qtdFuncionarios; i++)
    {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}