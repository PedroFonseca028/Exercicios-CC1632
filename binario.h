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