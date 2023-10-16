#include <stdio.h>
#include <string.h>
#include "pessoa.h"

tPessoa CriaPessoa()
{
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.irmao = NULL;
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
        printf("IRMAO: ");
        if (pessoa -> irmao != NULL)
        {
            printf("%s\n", (pessoa -> irmao -> nome));
        }
        else
        {
            printf("NAO INFORMADO\n");
        }
        printf("\n"); 
    } 
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2)
{
    if ((pessoa1 -> pai == pessoa2 -> pai) && (pessoa1 -> mae == pessoa2 -> mae))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas)
{
    int qtd, i, j, mae, pai, filho, mesmaPessoa;
    char temp[100];
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
        for (j = 0; j < numPessoas; j++)
        {
            if (VerificaIrmaoPessoa(Filho, pessoas+j) == 1)
            {
                mesmaPessoa = strcmp(Filho -> nome, (pessoas+j) -> nome);
                if (mesmaPessoa != 0)
                {
                    Filho -> irmao = (pessoas + j);
                    (pessoas+j) -> irmao = Filho;
                }
            }
        } 
    }     
}
