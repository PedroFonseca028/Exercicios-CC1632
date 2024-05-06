#include "1_produto.h"
#include <stdio.h>

int main() {
    Produtos produtos[total];
    int posicao = 0;
    while (1) {
        int opcao;
        printf("\n");
        printf("1 - Incluir produto no estoque\n");
        printf("2 - Lista de produtos no estoque\n");
        printf("3 - Preço total no estoque\n");
        printf("0 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1) {
            criar_produto(produtos, &posicao);
        }
        else if (opcao == 2) {
            listar_registro(produtos, &posicao);
        }
        else if (opcao == 3) {
            listar_preco(produtos, &posicao);
        }
        else if (opcao == 0) {
            printf("Saindo...\n");
            break;
        }
        else {
            printf("Opção inválida!\n");
        }
    }
    return 0;
}