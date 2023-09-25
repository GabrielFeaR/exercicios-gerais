#include "matrix_utils.h"
#include <stdio.h>


int main()
{
    int numeroMatrix = 0, scalar = 1, opcao = 0;
    int rows1, cols1, rows2, cols2;
    tMatrix matrix1, matrix2;
    scanf ("%d %d", &rows1, &cols1);
    matrix1 = MatrixCreate(rows1, cols1);
    matrix1 = MatrixRead(matrix1);
    scanf ("%d %d", &rows2, &cols2);
    matrix2 = MatrixCreate(rows2, cols2);
    matrix2 = MatrixRead(matrix2);

    while (scanf("%d", &opcao) == 1)
    {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida:\n");
        if (opcao == 6)
        {
            break;
        }
        else if (opcao == 1)
        {
            if (PossibleMatrixSum(matrix1, matrix2) == 1)
            {
                tMatrix resultadoAdd;
                resultadoAdd = MatrixAdd(matrix1, matrix2);
                MatrixPrint(resultadoAdd);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        else if (opcao == 2)
        {
            if (PossibleMatrixSub(matrix1, matrix2) == 1)
            {
                tMatrix resultadoSub = MatrixCreate(rows1, cols1);
                resultadoSub = MatrixSub(matrix1, matrix2);
                MatrixPrint(resultadoSub);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        else if (opcao == 3)
        {
            if (PossibleMatrixMultiply(matrix1, matrix2) == 1)
            {
                tMatrix resultadoMult = MatrixCreate(rows1, cols2);
                resultadoMult = MatrixMultiply(matrix1, matrix2);
                MatrixPrint(resultadoMult);
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
                matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                MatrixPrint(matrix1);
            }
            else if (numeroMatrix == 2)
            {
                matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                MatrixPrint(matrix2);
            }
            else
            {
                printf("ERRO: Matrix invalida\n\n");
            }
        }
        else if (opcao == 5)
        {
            tMatrix resultTM1 = MatrixCreate(rows1, cols1);
            tMatrix resultTM2 = MatrixCreate(rows2, cols2);

            resultTM1 = TransposeMatrix(matrix1);
            resultTM2 = TransposeMatrix(matrix2);
            MatrixPrint(resultTM1);
            MatrixPrint(resultTM2);
        }
        else if (opcao == 6)
        {
            rows1 = 0, cols1 = 0;
            MatrixPrint(matrix1);
            break;
        }
        else
        {
            printf("ERRO: Opcao invalida\n\n");
        }
    }
    return 0;
}