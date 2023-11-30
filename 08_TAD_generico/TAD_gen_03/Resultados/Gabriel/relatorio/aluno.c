#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "vector.h"

struct Aluno{
	char nome[50];
	float nota;
	char genero;
};

tAluno *CriaAluno()
{	
	tAluno* aluno = (tAluno*) calloc(1, sizeof(tAluno));
	if (aluno == NULL)
	{
		printf("Falha na alocação de memória para o aluno\n");
		exit(1);
	}
	aluno -> nota = 0;
	aluno -> genero = '\0';
	strcpy(aluno -> nome, "\0");
	return aluno;
}

void DestroiAluno(data_type aluno)
{
	free(aluno);
}

void LeAluno(tAluno *aluno)
{
	scanf("%[^;]", aluno -> nome);
	scanf("%*c");
	scanf("%c;%f", &aluno -> genero, &aluno -> nota);
}

char GetGeneroAluno(tAluno *aluno)
{
	return aluno -> genero;
}

float GetNotaAluno(tAluno *aluno)
{
	return aluno -> nota;
}
