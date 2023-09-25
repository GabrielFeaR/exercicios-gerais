#include <stdio.h>
#include "conta.h"
#include "usuario.h"

int main()
{
	int qtdContas, opcao, numConta = 0, valorSaque, valorDeposito;
	scanf("%d", &qtdContas);
	tConta conta[qtdContas];
	tUsuario user;
	char nome[20], cpf[15];
	int i;
	for (i = 0; i < qtdContas; i++)
	{
		scanf("%d", &opcao);
		if (opcao == 3) // cadastro de usuário e conta
		{
			scanf("%s", nome);
			scanf("%s", cpf);
			scanf("%d", &numConta);
			user = CriaUsuario(nome, cpf);
			conta[i] = CriaConta(numConta, user);
		}
	}
	while (scanf("%d", &opcao) == 1)
	{
		if (opcao == 0) // sair 
		{
			break;
		}
		else if (opcao == 1) // saque
		{
			scanf("%d %d", &numConta, &valorSaque);
			for (i = 0; i < qtdContas; i++)
			{
				if (VerificaConta(conta[i], numConta) == 1)
				{
					conta[i] = SaqueConta(conta[i], valorSaque);
					break;
				}
			}
		} 
		else if (opcao == 2) // depósito
		{
			scanf("%d %d", &numConta, &valorDeposito);
			for (i = 0; i < qtdContas; i++)
			{
				if (VerificaConta(conta[i], numConta) == 1)
				{
					conta[i] = DepositoConta(conta[i], valorDeposito);
					break;
				}
			}
		}
		else if (opcao == 4) // relatório
		{
			printf("===| Imprimindo Relatorio |===\n");
			for (i = 0; i < qtdContas; i++)
			{
				ImprimeConta(conta[i]);
				printf("\n");
			}
		}
	}
	return 0;
}