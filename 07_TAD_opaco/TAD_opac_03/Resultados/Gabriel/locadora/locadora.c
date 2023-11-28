#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

struct Locadora
{
	int numFilmes;
	int lucro;
	tFilme** filme;
};

tLocadora* CriarLocadora()
{
    tLocadora* locadora = (tLocadora*)calloc(1, sizeof(tLocadora));
    locadora->numFilmes = 0;
    locadora->lucro = 0;
    locadora->filme = NULL;


    return locadora;
}

void DestruirLocadora (tLocadora* locadora)
{
	for (int i = 0; i < locadora -> numFilmes; i++)
	{
		DestruirFilme(locadora -> filme[i]);
	}
	free(locadora -> filme);
	free(locadora);
}

int VerificarFilmeCadastrado (tLocadora* locadora, int codigo)
{
	for (int i = 0; i < locadora -> numFilmes; i++)
	{
		if (EhMesmoCodigoFilme(locadora -> filme[i], codigo))
		{
			return 1;
		}
	}
	return 0;
}

void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme)
{
	for (int i = 0; i < locadora -> numFilmes; i++)
	{
		if (!CompararNomesFilmes(locadora -> filme[i], filme) || ObterCodigoFilme(locadora -> filme[i]) == ObterCodigoFilme(filme))
		{
			printf("Filme ja cadastrado no estoque\n");
			DestruirFilme(filme);
			return;
		}
	}
	locadora->numFilmes++;
	locadora->filme = (tFilme**)realloc(locadora->filme, sizeof(tFilme*) * locadora->numFilmes);
	locadora->filme[locadora->numFilmes-1] = filme;
	printf("Filme cadastrado %d - ", ObterCodigoFilme(locadora -> filme[locadora -> numFilmes-1]));
	ImprimirNomeFilme(locadora -> filme[locadora -> numFilmes-1]);
	printf("\n");
}

void LerCadastroLocadora (tLocadora* Locadora)
{
	int codigo = 0;
	while (scanf("%d", &codigo) == 1)
	{
		tFilme* filme = CriarFilme();
		scanf(",");
		LeFilme(filme, codigo);
		CadastrarFilmeLocadora(Locadora, filme);
	}
	scanf("%*c");
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
	int cont, contTotal = 0, total = quantidadeCodigos, custo = 0;
	for (int i = 0; i < quantidadeCodigos; i++)
	{
		cont = 0;
		for (int j = 0; j < locadora -> numFilmes; j++)
		{
			if (EhMesmoCodigoFilme(locadora -> filme[j], codigos[i]))
			{
				contTotal++;
				cont++;
				if (ObterQtdEstoqueFilme(locadora -> filme[j]) > 0)
				{
					custo += (ObterValorFilme(locadora -> filme[j]));
					AlugarFilme(locadora -> filme[j]);
				}
				else
				{
					total--;
					printf("Filme %d - ", ObterCodigoFilme(locadora -> filme[j]));
					ImprimirNomeFilme(locadora -> filme[j]);
					printf(" nao disponivel no estoque. Volte mais tarde.\n");
				}
			}
		}
		if (cont == 0)
		{
			total--;
			printf("Filme %d nao cadastrado.\n", codigos[i]);
		}
	}
	if (contTotal > 0 && total > 0 && custo > 0)
	{
		printf("Total de filmes alugados: %d com custo de R$%d\n", total , custo);
	}
}

void LerAluguelLocadora (tLocadora* locadora)
{
	int quantidadeCodigos = 0, temp;
	int* alugar = (int*) malloc (sizeof(int));
	while (scanf("%d", &temp) == 1)
	{
		quantidadeCodigos++;
		alugar = (int*) realloc (alugar, sizeof(int) *quantidadeCodigos);
		alugar [quantidadeCodigos-1] = temp;
	}
	scanf("%*c");
	AlugarFilmesLocadora(locadora, alugar, quantidadeCodigos);

	free(alugar);
}

void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
	int cont;
	for (int i = 0; i < quantidadeCodigos; i++)
	{
		cont = 0;
		for (int j = 0; j < locadora -> numFilmes; j++)
		{
			if (EhMesmoCodigoFilme(locadora -> filme[j], codigos[i]))
			{
				cont++;
				if (ObterQtdAlugadaFilme(locadora -> filme[j]) == 0)
				{
					printf("Nao e possivel devolver o filme %d - ", ObterCodigoFilme(locadora -> filme[j]));
					ImprimirNomeFilme(locadora -> filme[j]);
					printf(".\n");
				}
				else
				{
					printf("Filme %d - ", ObterCodigoFilme(locadora -> filme[j]));
					ImprimirNomeFilme(locadora -> filme[j]);
					printf(" Devolvido!\n");
					DevolverFilme(locadora -> filme[j]);
					locadora -> lucro += (ObterValorFilme(locadora -> filme[j]));
				}
			}
		}
		if (cont == 0)
		{
			printf("Filme %d nao cadastrado.\n", codigos[i]);
		}
	}
}

void LerDevolucaoLocadora (tLocadora* locadora)
{
	int quantidadeCodigos = 0, temp;
	int* devolver = (int*) malloc (sizeof(int));
	while (scanf("%d", &temp) == 1)
	{
		quantidadeCodigos++;
		devolver = (int*) realloc (devolver, sizeof(int) *quantidadeCodigos);
		devolver [quantidadeCodigos-1] = temp;
	}
	scanf("%*c");
	DevolverFilmesLocadora(locadora, devolver, quantidadeCodigos);
	free(devolver);
}

void OrdenarFilmesLocadora(tLocadora* locadora)
{
    int n = locadora->numFilmes;
    int trocado = 1; 

    while (trocado)
    {
        trocado = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            if (CompararNomesFilmes(locadora->filme[i], locadora->filme[i + 1]) < 0)
            {
                tFilme* temp = locadora->filme[i];
                locadora->filme[i] = locadora->filme[i + 1];
                locadora->filme[i + 1] = temp;
                trocado = 1;
            }
        }

        n--; 
    }
}

void ConsultarEstoqueLocadora (tLocadora* locadora)
{
	OrdenarFilmesLocadora(locadora);
	printf("~ESTOQUE~\n");
	for (int i = locadora -> numFilmes-1; i > -1; i--)
	{
		printf("%d - ", ObterCodigoFilme(locadora -> filme[i]));
		ImprimirNomeFilme(locadora -> filme[i]);
		printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora -> filme[i]));
	}
	scanf("%*c");
}

void ConsultarLucroLocadora (tLocadora* locadora)
{
	if (locadora -> lucro > 0)
		printf("\nLucro total R$%d\n", locadora -> lucro);
}
