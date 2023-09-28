#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

int main()
{
    int qtdEmpresas;
    scanf("%d", &qtdEmpresas);
    tEmpresa empresa[qtdEmpresas];
    int i;
    for (i = 0; i < qtdEmpresas; i++)
    {
    	empresa[i] = leEmpresa();
    }
     for (i = 0; i < qtdEmpresas; i++)
    {
    	imprimeEmpresa(empresa[i]);
    	printf("\n");
    }
    return 0;
}