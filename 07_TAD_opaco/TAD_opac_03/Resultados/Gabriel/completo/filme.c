#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

struct Filme{
	char nome[MAX_CARACTERES];
	int codigo;
	int qtdEstoque;
	int qtdAlugada;
	int valor;
	int devolvido;
};

tFilme* CriarFilme()
{
	tFilme* filme = (tFilme*) malloc(sizeof(tFilme));
	filme -> qtdAlugada = 0;
	filme -> devolvido = 0;
	return filme;
}

void LeFilme(tFilme *filme, int codigo)
{
	filme -> codigo = codigo;
	scanf("%[^,]", filme -> nome);
	scanf("%*c");
	scanf("%d,%d", &filme -> valor, &filme -> qtdEstoque);
}

void DestruirFilme (tFilme* filme)
{
	free(filme);
}

int ObterCodigoFilme (tFilme* filme)
{
	return filme -> codigo;
}

void ImprimirNomeFilme (tFilme* filme)
{
	printf("%s", filme -> nome);
}

int ObterValorFilme (tFilme* filme)
{
	return filme -> valor;
}

int ObterQtdEstoqueFilme (tFilme* filme)
{
	return filme -> qtdEstoque;
}

int ObterQtdAlugadaFilme (tFilme* filme)
{
	return filme -> qtdAlugada;
}

int EhMesmoCodigoFilme (tFilme* filme, int codigo)
{
	if (filme -> codigo == codigo)
		return 1;
	return 0;
}

void AlugarFilme (tFilme* filme)
{
	filme -> qtdAlugada++;
	filme -> qtdEstoque--;
}

void DevolverFilme (tFilme* filme)
{
	filme -> devolvido++;
	filme -> qtdAlugada--;
	filme -> qtdEstoque++;
}

int CompararNomesFilmes (tFilme* filme1, tFilme* filme2)
{
	int tamanho = strcmp(filme1 -> nome, filme2 -> nome);
	if (tamanho == 0)
		return 0;
	if (tamanho > 0)
		return 1;
	if (tamanho < 0)
		return -1;
	return -2;
}