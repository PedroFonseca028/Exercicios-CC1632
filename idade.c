#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para representar uma pessoa
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

// Função de comparação para qsort (compara as idades)
int compararIdade(const void *a, const void *b) {
    const Pessoa *p1 = (const Pessoa *)a;
    const Pessoa *p2 = (const Pessoa *)b;
    return p1->idade - p2->idade;
}

int main() {
    int num_pessoas;

    // Solicitando o número de pessoas
    printf("Digite o número de pessoas: ");
    scanf("%d", &num_pessoas);

    // Criando um array de pessoas com base no número inserido
    Pessoa pessoas[num_pessoas];

    // Solicitando o nome e a idade de cada pessoa
    for (int i = 0; i < num_pessoas; i++) {
        printf("\nDigite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
    }

    // Ordenando o array de pessoas com base na idade
    qsort(pessoas, num_pessoas, sizeof(Pessoa), compararIdade);

    // Exibindo as pessoas ordenadas
    printf("\nPessoas ordenadas por idade:\n");
    for (int i = 0; i < num_pessoas; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}
