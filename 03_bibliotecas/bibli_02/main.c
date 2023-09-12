#include "matrix_utils.h"
#include <stdio.h>

int main()
{
	int numeroMatrix = 0, scalar = 1, opcao = 0;
	int rows1, cols1, rows2, cols2;
	scanf ("%d %d", &rows1, &cols1);
	int matrix1[rows1][cols1];
	matrix_read(rows1, cols1, matrix1);
	scanf ("%d %d", &rows2, &cols2);
	int matrix2[rows2][cols2];
	matrix_read(rows2, cols2, matrix2);

	while (scanf("%d", &opcao) == 1)
	{
		printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida:\n");
		if (opcao == 6)
		{
			break;
		}
		else if (opcao == 1)
		{
			if (possible_matrix_sum(rows1, cols1, rows2, cols2) == 1)
			{
				int resultadoAdd[rows1][cols1];
				matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, resultadoAdd);
				matrix_print(rows1, cols1, resultadoAdd);
			}
			else
			{
				printf("Erro: as dimensoes da matriz nao correspondem\n\n");
			}
		}
		else if (opcao == 2)
		{
			if (possible_matrix_sub(rows1, cols1, rows2, cols2) == 1)
			{
				int resultadoSub[rows1][cols1];
				matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, resultadoSub);
				matrix_print(rows1, cols1, resultadoSub);
			}
			else
			{
				printf("Erro: as dimensoes da matriz nao correspondem\n\n");
			}
		}
		else if (opcao == 3)
		{
			if (possible_matrix_multiply(cols1, rows2) == 1)
			{
				int resultadoMult[rows1][cols2];
				matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, resultadoMult);
				matrix_print(rows1, cols2, resultadoMult);
			}
			else
			{
				printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
			}
		}
		else if (opcao == 4)
		{
			scanf("%d %d", &scalar, &numeroMatrix);
			if (numeroMatrix == 1)
			{
				scalar_multiply(rows1, cols1, matrix1, scalar);
				matrix_print(rows1, cols1, matrix1);
			}
			else if (numeroMatrix == 2)
			{
				scalar_multiply(rows2, cols2, matrix2, scalar);
				matrix_print(rows1, cols1, matrix2);
			}
			else
			{
				printf("ERRO: Matrix invalida\n\n");
			}
		}
		else if (opcao == 5)
		{
			int resultTM1[cols1][rows1];
			int resultTM2[cols2][rows2];
			transpose_matrix(rows1, cols1, matrix1, resultTM1);
			transpose_matrix(rows2, cols2, matrix2, resultTM2);
			matrix_print(cols1, rows1, resultTM1);
			matrix_print(cols2, rows2, resultTM2);
		}
		else if (opcao == 6)
		{
			rows1 = 0, cols1 = 0;
			matrix_print(rows1, cols1, matrix1);
			break;
		}
		else
		{
			printf("ERRO: Opcao invalida\n\n");
		}
	}
	return 0;
}