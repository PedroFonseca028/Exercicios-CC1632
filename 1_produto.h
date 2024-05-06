
#define PRODUTO_H

#define total 255
#define max_nome 70

typedef struct {
  char nome[max_nome];
  int preco;
  int estoque;
} Produtos;

int criar_produto(Produtos produtos[], int *posicao);
int listar_registro(Produtos produtos[], int *posicao);
int listar_preco(Produtos produtos[], int *posicao);
void clearBuffer();
