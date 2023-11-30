#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

struct Vector{
	int tamanho;
	void * vetor;
};

Vector *VectorConstruct()
{
    Vector *v = (Vector *)malloc(sizeof(Vector));
    if (v == NULL)
    {
    	printf("Falha na alocação de memória para Vector\n");
        exit(1); // Encerra o programa se a alocação de memória falhar
    }
    
    v->tamanho = 0;
    v->vetor = NULL;
    return v;
}

void VectorPushBack(Vector *v, data_type val)
{
    v->tamanho++;

    // Realoca o vetor para acomodar um elemento adicional
    v->vetor = realloc(v->vetor, v->tamanho * sizeof(data_type));

    if (v->vetor == NULL)
    {
    	printf("Falha na realocação de memória para Vector\n");
        exit(1);
    }

    ((data_type *)(v->vetor))[v->tamanho - 1] = val;
}

data_type VectorGet(Vector *v, int i)
{
    if (i < 0 || i >= v->tamanho)
    {
    	printf("Tamanho fora do range do vetor\n");
        exit(1);
    }

    return ((data_type *)(v->vetor))[i];
}

int VectorSize(Vector *v) 
{
    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    for (int i = 0; i < v->tamanho; i++)
    {
        destroy(((data_type *)(v->vetor))[i]);
    }

    free(v->vetor); // Libera a memória alocada para o vetor
    free(v); // Libera a memória alocada para a estrutura Vector
}