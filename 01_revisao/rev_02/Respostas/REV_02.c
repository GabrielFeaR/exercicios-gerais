#include <stdio.h>

int main()
{
    int qtd;
    scanf("%d", &qtd);
    int numMax = 1, linha = 1, num = 1;
    for (num = 1; num > 0; num++)
    {
        printf("%d ", num);
        if (num == numMax)
        {
            printf("\n");
            linha++;
            numMax = numMax + linha;
        }
        if (linha == qtd+1)
        {
            break;
        }
    }
    return 0;
}
