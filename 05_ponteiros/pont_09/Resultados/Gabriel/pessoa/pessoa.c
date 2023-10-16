#include <stdio.h>
#include <string.h>
#include "pessoa.h"

tPessoa CriaPessoa()
{
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa)
{
    scanf(" %[^\n]", pessoa -> nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if (pessoa -> mae != NULL || pessoa -> pai != NULL)
    {
        return 1;
    }

    return 0;
}

void ImprimePessoa(tPessoa *pessoa)
{
    if (!(pessoa -> mae == NULL && pessoa -> pai == NULL))
    {
        printf("NOME COMPLETO: %s\n", pessoa -> nome);
        printf("PAI: ");
        if (pessoa -> pai != NULL)
        {
            printf("%s\n", (pessoa -> pai -> nome));
        }
        else
        {
            printf("NAO INFORMADO\n");
        }
        printf("MAE: ");
        if (pessoa -> mae != NULL)
        {
            printf("%s\n", (pessoa -> mae -> nome));
        }
        else
        {
            printf("NAO INFORMADO\n");
        }
        printf("\n"); 
    } 
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    int qtd, i, mae, pai, filho;
    scanf("%d", &qtd);
    for (i = 0; i < qtd; i++)
    {
        scanf(" mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);
        tPessoa *Filho = (pessoas + filho);

        if (mae != -1)
        {
            Filho -> mae = (pessoas + mae);
        }
        if (pai != -1)
        {
            Filho -> pai = (pessoas + pai);
        }
    }
}
