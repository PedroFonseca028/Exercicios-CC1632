#include <stdio.h>
#include <ctype.h>
#include <string.h>
//Definindo o máximo para cada campo
#define total 255
#define max_nome 70
#define max_idade 70
#define max_salario 70

// definindo meu struct
typedef struct {
  char nome[max_nome];
  char idade[max_idade];
  char salario[max_salario];
  int telefone;
} Registros;


// Funções
int criar_registro(Registros registro[], int *posicao);

int listar_registro(Registros registro[], int *posicao);

int listar_registro_por_nome(Registros registro[], int *posicao);

int salvar_em_binario(Registros registro[], int *posicao);

int carregar_de_binario(Registros registro[], int *posicao);

void clearBuffer();

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