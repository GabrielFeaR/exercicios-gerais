#include <stdio.h>
#include "aluno.h"
#include "relatorio.h"
#include "vector.h"

void ImprimeRelatorio(Vector *alunos)
{
	int F = 0, M = 0, O = 0;
	int aprovadoQTD = 0;
	float notageral = 0;
	for(int i = 0; i < VectorSize(alunos); i++)
	{
		tAluno *aluno = (tAluno *)VectorGet(alunos, i);
		if (GetGeneroAluno(aluno) == 'F')
		{
			F++;
		}
		else if (GetGeneroAluno(aluno) == 'M')
		{
			M++;
		}
		else if(GetGeneroAluno(aluno) == 'O')
		{
			O++;
		}
		notageral += GetNotaAluno(aluno);
		if (GetNotaAluno(aluno) >= 6)
		{
			aprovadoQTD++;
		}
	}
	float pF, pM, pO, pA;
	pF = (float)F*100/VectorSize(alunos);
	pM = (float)M*100/VectorSize(alunos);
	pO = (float)O*100/VectorSize(alunos);
	pA = (float)aprovadoQTD*100/VectorSize(alunos);
	printf("Media das notas: %.2f\n", notageral/VectorSize(alunos));
	printf("Porcentagem de alunos aprovados: %.2f%\n", pA);
	printf("Porcentagem de cada genero:\n");
	printf("Masculino: %.2f%\n", pM);
	printf("Feminino: %.2f%\n", pF);
	printf("Outro: %.2f%\n", pO);
}
