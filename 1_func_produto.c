
#include "1_produto.h"
#include <stdio.h>
#include <string.h>

int criar_produto(Produtos produtos[], int *posicao) {
    if (*posicao >= total) {
        printf("Não é possível adicionar mais registros, sua lista está cheia.\n");
        return 0;
    }

    clearBuffer();
    printf("Nome do produto: ");
    fgets(produtos[*posicao].nome, max_nome, stdin);
    produtos[*posicao].nome[strcspn(produtos[*posicao].nome, "\n")] = '\0';

    printf("Preço: ");
    scanf("%d", &produtos[*posicao].preco);

    printf("Quantidade: ");
    scanf("%d", &produtos[*posicao].estoque);
    (*posicao)++;

    printf("Produto adicionado com sucesso!\n");

    return 1;
}

int listar_registro(Produtos produtos[], int *posicao){
    if (*posicao == 0) {
        printf("Não há produtos para listar.\n");
        return 0;
    }

    for (int i = 0; i < *posicao; i++) {
        printf("Pos: %d\t", i + 1);
        printf("Nome: %s\t", produtos[i].nome);
        printf("Preço: R$%d\t", produtos[i].preco); 
        printf("Quantidade no estoque: %d\n", produtos[i].estoque); 
    }
    return 0;
}

int listar_preco(Produtos produtos[], int *posicao) {
    int totalPreco = 0;

    if (*posicao == 0) {
        printf("Não há produutos em estoque.\n");
        return 0;
    }
    for (int i = 0; i < *posicao; i++) {
        totalPreco += produtos[i].preco * produtos[i].estoque;
    }
    printf("Preço total no estoque: R$%d\n", totalPreco);
    return totalPreco;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}