#include "string_utils.h"
#include <stdio.h>

int main()
{
    char string[1000];
    char strCopiada[1000];
    int opcao;
    scanf("%99[^\n]", string);
    while (scanf("%d", &opcao) == 1)
    {
        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
        if (opcao == 1)
        {
            int tamanho = string_length(string);
            printf("Tamanho da string: %d\n\n", tamanho+1);
        }
        else if (opcao == 2)
        {
            string_copy(string, strCopiada);
            printf("String copiada: %s\n\n", strCopiada);
        }
        else if (opcao == 3)
        {
            string_upper(string);
            printf("String convertida para maiusculas: %s\n\n", string);
        }
        else if (opcao == 4)
        {
            string_lower(string);
            printf("String convertida para minusculas: %s\n\n", string);
        }
        else if (opcao == 5)
        {
            string_reverse(string);
            printf("String invertida: \n%s\n\n", string);
        }
        else if (opcao == 6)
        {
            break;
        }

    }
}