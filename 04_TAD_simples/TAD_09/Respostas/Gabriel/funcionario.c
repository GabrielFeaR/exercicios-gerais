#include <stdio.h>
#include "funcionario.h"

tFuncionario criaFuncionario(int id, float salario)
{
    tFuncionario funcionario;
    funcionario.id = id;
    funcionario.salario = salario;
    return funcionario;
}

tFuncionario leFuncionario()
{
    int id, salario;
    scanf("%d %d", &id, &salario);
    tFuncionario funcionario = criaFuncionario(id, salario);
    return funcionario;
}


int getIdFuncionario(tFuncionario funcionario)
{
    int id;
    id = funcionario.id;
    return id;
}

void imprimeFuncionario(tFuncionario funcionario)
{
    printf("- Funcionario %d: RS %.2f\n", funcionario.id, funcionario.salario);
}