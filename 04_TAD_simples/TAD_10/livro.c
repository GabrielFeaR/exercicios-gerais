#include <stdio.h>
#include "livro.h"

tLivros lerLivro()
{
    tLivros livro;
    scanf("%s", livro.titulo);
    scanf("%s", livro.autor);
    scanf("%d", livro.anoPublicacao);
    return livro;
}

void imprimeLivro(tLivros livro)
{
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de publicacao: %d\n", livro.anoPublicacao);
}