#include "binario.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int criar_registro(Registros registro[], int *posicao) {
  // Verificando se a posição não estendeu o total.
  if (*posicao >= total) {
    printf("Não é possível adicionar mais registros, sua lista está cheia.\n");
    return 0;
  }

  // Pedindo para o usuário os dados e salvando-os no struct
  clearBuffer();
  printf("Nome: ");
  fgets(registro[*posicao].nome, max_nome, stdin);
  // Removendo o caractere de nova linha, se presente
  registro[*posicao].nome[strcspn(registro[*posicao].nome, "\n")] = '\0';

  printf("Idade: ");
  fgets(registro[*posicao].idade, max_idade, stdin);
  registro[*posicao].idade[strcspn(registro[*posicao].idade, "\n")] =
      '\0';

  printf("Salario: ");
  fgets(registro[*posicao].salario, max_salario, stdin);
  registro[*posicao].salario[strcspn(registro[*posicao].salario, "\n")] = '\0';


  (*posicao)++; // Incrementa a posição

  printf("Registro adicionado com sucesso!\n");

  return 1; // Retorna 1 indicando que o registro foi criado com sucesso
}

int listar_registro(Registros registro[], int *posicao){
  for (int i = 0; i < *posicao; i++) {
    printf("Pos: %d\t", i + 1);
    printf("Nome: %s\t", registro[i].nome);
    printf("Idade: %s\t", registro[i].idade);
    printf("Salario: %s\n", registro[i].salario);
  }
}

int listar_registro_por_nome(Registros registro[], int *posicao) {
    if (*posicao == 0) {
        printf("Não há registros para listar.\n");
        return 0;
    }

    char nome_escolhida[max_nome];
    int nome_existe = 0; 

    // Solicitação do usuário
    printf("Digite o nome no registro que você quer ver (ou deixe em branco para listar todos): ");
    scanf(" %[^\n]", nome_escolhida); // Modified scanf statement
    clearBuffer();

    
    // Procura o registro pelo nome especificado
    for (int i = 0; i < *posicao; i++) {
        if (strcmp(registro[i].nome, nome_escolhida) == 0) {
            printf("Listando o registro de %s: \n", nome_escolhida);
            printf("Pos: %d\t", i + 1);
            printf("Idade: %s\t", registro[i].idade);
            printf("Salario: %s\n", registro[i].salario);
            nome_existe = 1;
        }
    }

    // Se o registro não existir
    if (nome_existe == 0) {
        printf("Registro %s não existe.\n", nome_escolhida);
    }

    return 0;
}


int salvar_em_binario(Registros registro[], int *posicao) {
  FILE *f = fopen("Registro.bin", "wb");
  if (f == NULL) {
    printf("Erro ao abrir o arquivo para leitura\n");
    return 0;
  }
  int qtd = fwrite(registro, total, sizeof(Registros), f);
  if (qtd == 0) {
    printf("Erro ao ler os registros do arquivo\n");
    return 0;
  }
  qtd = fwrite(posicao, 1, sizeof(int), f);
  if (qtd == 0) {
    printf("Erro ao ler a posição do arquivo\n");
    return 0;
  }
  if (fclose(f)) {
    printf("Erro ao fechar o arquivo após a leitura\n");
    return 0;
  }

  printf(
      "\nArquivo foi salvo em arquivo binario com o nome: 'Registro.bin'. \n");
  return 1;
}

int carregar_de_binario(Registros registro[], int *posicao) {

  FILE *f = fopen("Registro.bin", "rb");
  if (f == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return 0;
  }

  int qtd = fread(registro, total, sizeof(Registros), f);
  if (qtd == 0) {
    printf("Erro ao ler os registros do arquivo\n");
    return 0;
  }

  qtd = fread(posicao, 1, sizeof(int), f);
  if (qtd == 0) {
    printf("Erro ao ler a posição do arquivo\n");
    return 0;
  }

  if (fclose(f)) {
    printf("Erro ao fechar o arquivo\n");
    return 0;
  }

  printf("\nRegistros carregados com sucesso!\n");
  return 1;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}