#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic{
    Type tipo;
    int numElem;
    void* elementos;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem)
{
    int tamanho;
    if (type == FLOAT)
    {
        tamanho = sizeof(float);
    }
    if (type == INT)
    {
        tamanho = sizeof(int);
    }
    tGeneric* generico = calloc(1, sizeof(tGeneric));
    generico -> tipo = type;
    generico -> numElem = numElem;
    generico -> elementos = calloc(numElem, tamanho);
    return generico;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen)
{
    free(gen -> elementos);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen)
{
    printf("\nDigite o vetor:\n");
    for(int i = 0; i < gen -> numElem; i++)
    {
        if (gen -> tipo == FLOAT)
            scanf("%f", &((float*)gen -> elementos)[i]);
        else if (gen -> tipo == INT)
            scanf("%d", &((int*)gen -> elementos)[i]);
    }   
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen)
{
    for(int i = 0; i < gen -> numElem; i++)
    {
        if (gen -> tipo == 0)
            printf("%.2f ", ((float*)gen -> elementos)[i]);
        else if (gen -> tipo == 1)
            printf("%d ", ((int*)gen -> elementos)[i]);
    }
    printf("\n");
}
