#include <stdio.h>
#include <string.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos)
{
    if (*numEventos == 10)
    {
        printf("Limite de eventos atingido!\n");
        return;
    }
    scanf("%s", (eventos+ *numEventos) -> nome);
    scanf("%d %d %d", &(eventos+ *numEventos) -> dia, &(eventos+ *numEventos) -> mes, &(eventos+ *numEventos) -> ano);
    (*numEventos)++;
    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos)
{
    int i;
    if (*numEventos == 0)
    {
       printf("Nenhum evento cadastrado.\n");
       return; 
    }
    printf("Eventos cadastrados:\n");
    for (i = 0; i < *numEventos; i++)
    {
        printf("%02d - %s - %02d/%02d/%02d\n", i, (eventos + i ) -> nome, (eventos + i) -> dia, (eventos + i) -> mes, (eventos + i) -> ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos)
{
    int numEvento;
    scanf("%d", &numEvento);
    if (numEventos > *numEventos || numEvento < 0)
    {
        printf("Indice invalido!\n");
        return;
    }
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    int i;
    for (i = 0; i < *numEventos; i++)
    {
        if (i == numEvento)
        {
            (eventos+i) -> dia = dia;
            (eventos+i) -> mes = mes;
            (eventos+i) -> ano = ano;
            break;
        }
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{  
    if (*indiceA > *numEventos || *indiceA < 0)
    {
        printf("Indices invalidos!\n");
        return;
    }
     if (*indiceB > *numEventos || *indiceB < 0)
    {
        printf("Indices invalidos!\n");
        return;
    }
    Evento temp;
    int i, j;
    for (i = 0; i < *numEventos; i++)
    {
        if (i == *indiceA)
        {
            for (j = 0; j < *numEventos; j++)
            {
                if (j == *indiceB)
                {
                    temp = *(eventos+i);
                    *(eventos+i) = *(eventos+j);
                    *(eventos+j) = temp;
                }
            }
        }
    }
}