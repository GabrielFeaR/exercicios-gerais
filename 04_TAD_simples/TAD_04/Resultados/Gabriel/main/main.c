#include <stdio.h>
#include "aluno.h"

int main()
{
	int qtdAlunos, aprovados = 0;
	scanf("%d", &qtdAlunos);
	tAluno aluno[qtdAlunos], aprovado[qtdAlunos], aux;
	int i, j;
	for (i = 0; i < qtdAlunos; i++)
	{
		aluno[i] = LeAluno();
		if (VerificaAprovacao (aluno[i]) == 1)
		{
			aprovado[aprovados] = aluno[i];
			aprovados++;
		}
	}
	for (i = 0; i < aprovados; i++)
	{
		for (j = i+1; j < aprovados; j++)
		{
			if (ComparaMatricula(aprovado[i], aprovado[j]) == 1)
			{
				aux = aprovado[i];
				aprovado[i] = aprovado[j];
				aprovado[j] = aux;
			}
		}
	}
	for (i = 0; i < aprovados; i++)
	{
		ImprimeAluno(aprovado[i]);
	}
	return 0;
}