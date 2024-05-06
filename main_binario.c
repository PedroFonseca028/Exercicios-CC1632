#include "binario.h"
#include <stdio.h>

int main() {
  Registros registros[total];
  int posicao = 0;
  while (1) {
    int opcao;
    printf("\n");
    printf("1 - Criar registro\n");
    printf("2 - Listar todos os registros de funcionários\n");
    printf("3 - Buscar registro de funcionário pelo nome\n");
    printf("4 - Salvar registro em arquivo binario\n");
    printf("5 - Carregar registro de arquivo binário\n");
    printf("0 - Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1) {
      criar_registro(registros, &posicao);
    }

    else if (opcao == 2) {
      listar_registro(registros, &posicao);
    }
    
    else if (opcao == 3) {
      listar_registro_por_nome(registros, &posicao);
    }

    else if (opcao == 4) {
      salvar_em_binario(registros, &posicao);
    }

    else if (opcao == 5) {
      carregar_de_binario(registros, &posicao);
    }

    else if (opcao == 0) {
      printf("Saindo...\n");
      break;
    }

    else {
      printf("Opção inválida!\n");
    }
  }
}