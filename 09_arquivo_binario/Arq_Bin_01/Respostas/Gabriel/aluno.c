#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno
{
	char nome[100];
	char dataNascimento[100];
	char cursoUfes[100];
	char periodoIngresso[100];
	int percConclusao;
	float cra;
};

Aluno** CriaVetorAlunos(int numeroAlunos)
{
	Aluno** aluno = (Aluno**) calloc (numeroAlunos, sizeof(Aluno*));
	if (aluno == NULL)
	{
		printf("Problema de alocação no vetor alunos\n");
		exit (1);
	}
	return aluno;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA)
{
	Aluno* aluno = (Aluno*) calloc (1, sizeof(Aluno));
	if (aluno == NULL)
	{
		printf("Problema na alocação de Aluno\n");
		exit (1);
	}
	strcpy(aluno -> nome, nome);
	strcpy(aluno -> dataNascimento, dtNasc);
	strcpy(aluno -> cursoUfes, cursoUfes);
	strcpy(aluno -> periodoIngresso, periodoIngresso);
	aluno -> percConclusao = percConclusao;
	aluno -> cra = CRA;

	return aluno;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos)
{
	char nome[100];
	char dataNascimento[100];
	char cursoUfes[100];
	char periodoIngresso[100];
	int percConclusao;
	float cra;
	for (int i = 0; i < numeroAlunos; i++)
	{
		scanf("%[^\n]", nome);
		scanf("%*c");
		scanf("%[^\n]", dataNascimento);
		scanf("%*c");
		scanf("%[^\n]", periodoIngresso);
		scanf("%*c");
		scanf("%[^\n]", cursoUfes);
		scanf("%*c");
		scanf("%d", &percConclusao);
		scanf("%f", &cra);
		vetorAlunos[i] = CriaAluno(nome, dataNascimento, periodoIngresso, cursoUfes, percConclusao, cra);
	}
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos)
{
	for (int i = 0; i < numeroAlunos; i++)
	{
		free(alunos[i]);
	}
	free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
	
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName)
{

}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos)
{
	for (int i = 0; i < numeroAlunos; i++)
	{
		printf("Aluno %d", i);
		printf("Nome: %s\n", alunos[i] -> nome);
		printf("Data Nascimento: %s\n", alunos[i] -> dataNascimento);
		printf("Curso %s\n", alunos[i] -> cursoUfes);
		printf("Periodo Ingresso: %s\n", alunos[i] -> periodoIngresso);
		printf("%% Conclusao do Curso: %d\n", alunos[i] -> percConclusao);
		printf("CRA: %.2f", alunos[i] -> cra);
	}
}