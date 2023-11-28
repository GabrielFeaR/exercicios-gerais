#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

int main()
{
	char opcao[20];
	tLocadora* locadora = CriarLocadora();
	while (scanf("%s", opcao) == 1)
	{
		if (!strcmp(opcao, "Cadastrar"))
		{
			LerCadastroLocadora(locadora);
			printf("\n");
		}
		if (!strcmp(opcao, "Estoque"))
		{
			OrdenarFilmesLocadora(locadora);
			ConsultarEstoqueLocadora(locadora);
		}
		if (!strcmp(opcao, "Alugar"))
		{
			LerAluguelLocadora(locadora);
			printf("\n");
		}
		if (!strcmp(opcao, "Devolver"))
		{
			LerDevolucaoLocadora(locadora);
			printf("\n");
		}
		if (!strcmp(opcao, "#"))
		{
			scanf("%*c");
		}
	}
	ConsultarLucroLocadora(locadora);
	DestruirLocadora(locadora);
	return 0;
}